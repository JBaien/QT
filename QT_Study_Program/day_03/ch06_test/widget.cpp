#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTime>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    id1 = startTimer(1000);
//    id2 = startTimer(1500);
//    id3 = startTimer(2200);

    QTimer *timer = new QTimer(this);                   //创建一个新的定时器
    //关联定时器的溢出信号到槽上
    connect(timer, &QTimer::timeout, this, &Widget::timerUpdate);
    timer->start(1000);                                 //设置溢出时间为1s，并启动定时器
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    QTimer::singleShot(10000, this, &Widget::close);
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == id1) {
        qDebug() << "timer1";
    }
    else if (event->timerId() == id2) {
        qDebug() << "timer2";
    }
    else if (event->timerId() == id3) {
        qDebug() << "timer3";
    }
}

void Widget::timerUpdate()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if(time.second() % 2 == 0)                      //每隔1s就将":"显示为空格
        text[2] = ' ';
    ui->lcdNumber->display(text);
    int rand = qrand() % 300;
    ui->lcdNumber->move(rand, rand);
}

Widget::~Widget()
{
    delete ui;
}
