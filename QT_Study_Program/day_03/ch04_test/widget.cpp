#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QCursor cursor;                         //创建光标对象
    cursor.setShape(Qt::OpenHandCursor);    //设置光标形状
    setCursor(cursor);                      //使用光标
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        offset = event->globalPos() - pos();            //获取指针位置和窗口位置差值
    }
    else if (event->button() == Qt::RightButton) {
        QCursor cursor(QPixmap("F:/QT_Program/day_02/ch05_test/images/open.png"));
        QApplication::setOverrideCursor(cursor);        //使用自定义图片作为鼠标指针
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton){
        QPoint temp;
        temp = event->globalPos() - offset;
        qDebug() << temp;
        move(temp);
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        if(windowState() != Qt::WindowFullScreen)
            setWindowState(Qt::WindowFullScreen);
        else setWindowState(Qt::WindowNoState);
    }
}

void Widget::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0){                 //当滚轮远离使用者时
        ui->textEdit->zoomIn();             //放大
    }
    else{
        ui->textEdit->zoomOut();            //缩小
    }
}

Widget::~Widget()
{
    delete ui;
}
