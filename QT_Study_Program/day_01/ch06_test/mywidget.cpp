#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>
#include "mydialog.h"


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
//    QDialog *dialog = new QDialog(this);
//    dialog->show();

//    QDialog dialog(this);
//    dialog.show();
//    dialog.exec();

//    QDialog *dialog = new QDialog(this);
//    dialog->setModal(true);
//    dialog->show();

//    connect(ui->showChildButton, &QPushButton::clicked, this, &MyWidget::on_showChildButton_clicked);

}

void MyWidget::on_showChildButton_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->show();
}


MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
    //先关闭主界面，其实是隐藏起来了，并没有真正退出
    close();
    MyDialog dlg;
    if(dlg.exec() == QDialog::Accepted) show();
}
