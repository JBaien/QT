#include "widget.h"
#include "ui_widget.h"
#include "mybutton.h"
#include <QDebug>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    MyButton *button = new MyButton(this);      //指定widget为父部件
    button->setText(tr("button"));

    MyButton *button2 = new MyButton;
    MyButton *button3 = new MyButton;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(button2);
    layout->addWidget(button3);
    setLayout(layout);
    qDebug() << children();
}

Widget::~Widget()
{
    delete ui;
    qDebug() << "delete widget";
}
