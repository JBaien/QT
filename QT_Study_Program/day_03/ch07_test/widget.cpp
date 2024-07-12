#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QWheelEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->textEdit->installEventFilter(this);                 //为编辑器部件在本窗口安装事件过滤器
    ui->spinBox->installEventFilter(this);
}

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->textEdit){
        if(event->type() == QEvent::Wheel){
            QWheelEvent *wheelEvent = static_cast<QWheelEvent *>(event);
            if(wheelEvent->delta() > 0) ui->textEdit->zoomIn();
            else ui->textEdit->zoomOut();
            return true;
        } else {
            return false;
        }
    }
    else if (obj == ui->spinBox) {
        if(event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if(keyEvent->key() == Qt::Key_Space) {
                ui->spinBox->setValue(0);
                return true;
            } else {
                return false;
                }
            }else {
            return false;
                }
        }
    else return  QWidget::eventFilter(obj, event);
}

Widget::~Widget()
{
    delete ui;
}
