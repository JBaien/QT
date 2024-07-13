#include "receiver.h"
#include "ui_receiver.h"
#include <QtNetwork>

Receiver::Receiver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Receiver)
{
    ui->setupUi(this);

    receiver = new QUdpSocket(this);
    receiver->bind(45454, QUdpSocket::ShareAddress);
    connect(receiver, &QUdpSocket::readyRead, this, &Receiver::processPendingDatagram);
}

void Receiver::processPendingDatagram()
{
    while(receiver->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(receiver->pendingDatagramSize());
        receiver->readDatagram(datagram.data(), datagram.size());
        ui->label->setText(datagram);
    }
}

Receiver::~Receiver()
{
    delete ui;
}
