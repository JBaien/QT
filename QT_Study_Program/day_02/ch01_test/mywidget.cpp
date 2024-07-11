#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPixmap>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    ui->frame_2->setFrameShape(QFrame::Box);
    ui->frame_2->setFrameShadow(QFrame::Sunken);
    ui->frame_2->setLineWidth(5);
    ui->frame_2->setMidLineWidth(10);

//    QFont font;
//    font.setFamily("华文行楷");
//    font.setPointSize(20);
//    font.setBold(true);
//    font.setItalic(true);
//    ui->label->setFont(font);

    ui->label->setPixmap(QPixmap("C:/Users/29281/Desktop/QT/Snipaste_2024-07-09_08-17-12.png"));

    ui->lcdNumber->display("123.456");


}

MyWidget::~MyWidget()
{
    delete ui;
}
