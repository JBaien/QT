#ifndef RECEIVER_H
#define RECEIVER_H

#include <QDialog>
#include <QUdpSocket>

class QUdpSocket;

namespace Ui {
class Receiver;
}

class Receiver : public QDialog
{
    Q_OBJECT

public:
    explicit Receiver(QWidget *parent = nullptr);
    ~Receiver();

private:
    Ui::Receiver *ui;
    QUdpSocket *receiver;

private slots:
    void processPendingDatagram();
};

#endif // RECEIVER_H
