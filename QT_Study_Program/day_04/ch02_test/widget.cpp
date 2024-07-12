#include "widget.h"
#include "ui_widget.h"
#include "myclass.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    MyClass *my = new MyClass(this);
    connect(my, &MyClass::userNameChanged, this, &Widget::userChanged);
    my->setUserName("hdzk");
    qDebug() << "userName1:" << my->getUserName();
    my->setProperty("userName", "Linux");
    qDebug() << "userName2:" << my->property("userName").toString();
    my->setProperty("myValue", 10);                                     //动态属性，只对该实例有效
    qDebug() << "myValue:" << my->property("myValue").toInt();
}

void Widget::userChanged(QString userName)
{
    qDebug() << "user changed:" << userName;
}

Widget::~Widget()
{
    delete ui;
}
