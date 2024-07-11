#include "widget.h"
#include "ui_widget.h"
#include "mylineedit.h"
#include <QEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    lineEdit = new MyLineEdit(this);
    lineEdit->move(100, 100);

    lineEdit->installEventFilter(this);                         //在Widget上为line安装事件过滤器
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("Widget 键盘按下事件");
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == lineEdit){
        if(event->type() == QEvent::KeyPress)
            qDebug() << tr("Widget的事件过滤器");
    }
    return QWidget::eventFilter(obj, event);
}
