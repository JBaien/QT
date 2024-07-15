#include "server.h"
#include "ui_server.h"
#include <QtNetwork>
#include <QFile>

Server::Server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    connect(&tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

void Server::start()
{
    if(!tcpServer.listen(QHostAddress::LocalHost, 6666)){
        qDebug() << tcpServer.errorString();
        close();
        return;
    }
    ui->startButton->setEnabled(false);
    totalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    ui->severStatusLabel->setText(tr("监听"));
    ui->serverProgressBar->reset();
}

void Server::acceptConnection()
{
    tcpServerConnection = tcpServer.nextPendingConnection();
    connect(tcpServerConnection, SIGNAL(readyRead()), this, SLOT(updateServerProgress()));
    connect(tcpServerConnection, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
    ui->severStatusLabel->setText(tr("接受连接"));
    tcpServer.close();
}

void Server::updateServerProgress()
{
    QDataStream in(tcpServerConnection);
    in.setVersion(QDataStream::Qt_5_12);
    //如果接受到的数据小于16个字节，保存到来的文件头结构
    if(bytesReceived <= sizeof(qint64)*2){
        if((tcpServerConnection->bytesAvailable() >= sizeof(qint64)*2) && (fileNameSize == 0)){
            in >> totalBytes >> fileNameSize;
            bytesReceived += sizeof(qint64) * 2;
        }
        if((tcpServerConnection->bytesAvailable() >= fileNameSize) && (fileName != 0)){
            //接收文件名，并建立文件
            in >> fileName;
            ui->severStatusLabel->setText(tr("接受文件 %1 ...").arg(fileName));
            bytesReceived += fileNameSize;
            localFile = new QFile(fileName);
            if(!localFile->open(QFile::WriteOnly)){
                qDebug() << "server: open file error!";
                return;
            }

        }
        else {
            return;
        }
    }
    //如果接受的数据小于总数居，那么写入文件
    if(bytesReceived < totalBytes){
        bytesReceived += tcpServerConnection->bytesAvailable();
        inBlock = tcpServerConnection->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }
    ui->serverProgressBar->setMaximum(totalBytes);
    ui->serverProgressBar->setValue(bytesReceived);
    //接受数据完成时
    if(bytesReceived == totalBytes) {
        tcpServerConnection->close();
        localFile->close();
        ui->startButton->setEnabled(true);
        ui->severStatusLabel->setText(tr("接收文件 %1 成功！").arg(fileName));
    }
}

void Server::displayError(QAbstractSocket::SocketError socketError)
{
    qDebug() << tcpServerConnection->errorString();
    tcpServerConnection->close();
    ui->serverProgressBar->reset();
    ui->severStatusLabel->setText(tr("服务端就绪"));
    ui->startButton->setEnabled(true);
}

Server::~Server()
{
    delete ui;
}

void Server::on_startButton_clicked()
{
    start();
}
