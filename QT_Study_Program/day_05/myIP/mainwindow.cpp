#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString localHostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(localHostName);
    qDebug() << "localHostName:" << localHostName << endl
             << "IP Address:" << info.addresses();
    QHostInfo::lookupHost("www.baidu,com", this, SLOT(lookedUp(QHostInfo)));
}

void MainWindow::lookedUp(const QHostInfo &host)
{
    if(host.error() != QHostInfo::NoError){
        qDebug() << "Lookup failed:" << host.errorString();
        return;
    }
    foreach(const QHostAddress &address, host.addresses())
        qDebug() << "Found address:" << address.toString();
}

MainWindow::~MainWindow()
{
    delete ui;
}
