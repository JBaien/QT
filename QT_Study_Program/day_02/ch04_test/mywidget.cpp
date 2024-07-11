#include "mywidget.h"
#include "ui_mywidget.h"
#include <QString>
#include <QDebug>

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit->setDisplayFormat(tr("yyyy 年 MM 月 dd 日 ddd HH 时 mm 分 ss 秒"));
    QString datetime;
    datetime = ui->dateTimeEdit->text();
    qDebug() << "当前时间: " << datetime;
    QDateTime datetime2;
    datetime2 = ui->dateTimeEdit->dateTime();
    qDebug() << "这个也是当前时间: " << datetime2;
}

myWidget::~myWidget()
{
    delete ui;
}
