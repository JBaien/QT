#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QApplication>
#include <QWidget>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    keyUp = false;
    keyLeft = false;
    move = false;
    setFocus();             //使主界面获得焦点
}

void Widget::keyPressEvent(QKeyEvent *event)
{
//    if(event->modifiers() == Qt::ControlModifier){          //是否按下Ctrl键
//        if(event->key() == Qt::Key_M)                       //是否按下M键
//                setWindowState(Qt::WindowMaximized);        //窗口最大化
//    }
//    else QWidget::keyPressEvent(event);

//    if(event->key() == Qt::Key_Up)
//        qDebug() << "press:" << event->isAutoRepeat();

    if(event->key() == Qt::Key_Up){
        if(event->isAutoRepeat()) return;
        keyUp = true;
    }
    else if (event->key() == Qt::Key_Left) {
        if(event->isAutoRepeat()) return;
        keyLeft = true;
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
//    if(event->key() == Qt::Key_Up){
//        qDebug() << "release:" << event->isAutoRepeat();
//        qDebug() << "up";
//    }

    if(event->key() == Qt::Key_Up){
        if(event->isAutoRepeat()) return;
        keyUp = false;
        if(move) {
            move = false;
            return;
        }
        if(keyLeft){
            ui->pushButton->move(30, 80);
            move = true;
        } else {
            ui->pushButton->move(120, 80);
        }
    }
}

Widget::~Widget()
{
    delete ui;
}
