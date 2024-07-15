#include "client.h"
#include "ui_client.h"
#include <QtNetwork>

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Client::readMessage);
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
}

void Client::newConnect()
{
    //初始化数据大小信息为0
    blockSize = 0;
    //取消已有的连接
    tcpSocket->abort();
    //连接到指定主机的指定端口
    tcpSocket->connectToHost(ui->hostLineEdit->text(), ui->portLineEdit->text().toInt());

}

void Client::readMessage()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_5_12);
    //如果是刚开始接受数据
    if(blockSize == 0){
        //判断接受的数据是否大于两字节，是则保存，否则返回，继续接受数据
        if(tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
        in >> blockSize;
    }
    if(tcpSocket->bytesAvailable() < blockSize) return;
    in >> message;
    ui->messageLabel->setText(message);
}

void Client::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpSocket->errorString();
}

Client::~Client()
{
    delete ui;
}

void Client::on_connectButton_clicked()
{
    newConnect();
}
