#include "client.h"
#include "ui_client.h"
#include <QtNetwork>
#include <QFileDialog>

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    payloadSize = 64*1024;              //64KB
    totalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
    tcpClient = new QTcpSocket(this);
    //连接服务器成功
    connect(tcpClient, SIGNAL(connected()), this, SLOT(startTransfer()));
    connect(tcpClient, SIGNAL(bytesWritten(qint64)), this, SLOT(updateClientProgress(qint64)));
    connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
    ui->sendButton->setEnabled(false);
}

void Client::openFile()
{
    fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty()){
        ui->sendButton->setEnabled(true);
        ui->clientStatusLabel->setText(tr("打开文件 %1 成功！").arg(fileName));
    }
}

void Client::send()
{
    ui->sendButton->setEnabled(false);

    //初始化已发送字节为0
    bytesWritten = 0;
    ui->clientStatusLabel->setText(tr("连接中..."));
    tcpClient->connectToHost(ui->hostLineEdit->text(), ui->portLineEdit->text().toInt());
}

void Client::startTransfer()
{
    localFile = new QFile(fileName);
    if(!localFile->open(QFile::ReadOnly)){
        qDebug() << "client: open file error!";
        return;
    }
    //获取文件大小
    totalBytes = localFile->size();
    QDataStream sendOut(&outBlock, QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_5_12);
    QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
    //保留总大小信息空间、文件名大小信息空间、然后输入文件名
    sendOut << qint64(0) << qint64(0) << currentFileName;
    totalBytes += outBlock.size();
    sendOut.device()->seek(0);
    //返回outBolock的开始，用实际的大小信息代替两个
    sendOut << totalBytes << qint64(outBlock.size() - sizeof(qint64)*2);
    //发送完文件头结构后剩余数据的大小
    bytesToWrite = totalBytes - tcpClient->write(outBlock);
    ui->clientStatusLabel->setText(tr("已连接"));
    outBlock.resize(0);
}

void Client::updateClientProgress(qint64 numBytes)
{
    //已经发送数据大小
    bytesWritten += (int)numBytes;
    //如果已经发送了数据
    if(bytesToWrite > 0){
        //每次发送payloadSize大小的数据,这里设置为64KB
        outBlock = localFile->read(qMin(bytesToWrite, payloadSize));
        bytesToWrite -= (int)tcpClient->write(outBlock);
        outBlock.resize(0);
    } else {
        localFile->close();
    }
    //更新进度条
    ui->clientProgressBar->setMaximum(totalBytes);
    ui->clientProgressBar->setValue(bytesWritten);
    if(bytesWritten == totalBytes) {
        ui->clientStatusLabel->setText(tr("传送文件 %1 成功").arg(fileName));
        localFile->close();
        tcpClient->close();
    }
}

void Client::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpClient->errorString();
    tcpClient->close();
    ui->clientProgressBar->reset();
    ui->clientStatusLabel->setText(tr("客户端就绪"));
    ui->sendButton->setEnabled(true);
}

Client::~Client()
{
    delete ui;
}

void Client::on_openButton_clicked()
{
    ui->clientProgressBar->reset();
    ui->clientStatusLabel->setText(tr("状态：等待打开文件！"));
    openFile();
}

void Client::on_sendButton_clicked()
{
    send();
}
