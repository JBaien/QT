#include "mywidget.h"
#include "ui_mywidget.h"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

//    QHBoxLayout *layout = new QHBoxLayout;              //新建水平布局管理器
//    layout->addWidget(ui->fontComboBox);                //向布局管理器添加部件
//    layout->addWidget(ui->textEdit);
//    layout->setSpacing(50);                             //设置部件间的间距
//    layout->setContentsMargins(0, 0, 50, 100);          //设置布局管理器到边界的距离
//                                                        //左上右下

//    QGridLayout *layout = new QGridLayout;
//    layout->addWidget(ui->fontComboBox, 0, 0, 1, 2);
//    layout->addWidget(ui->pushButton, 0, 2 , 1, 1);
//    layout->addWidget(ui->textEdit, 2, 0, 1, 3);
//    setLayout(layout);

    ui->textEdit->hide();

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_toggled(bool checked)          //显示隐藏窗口
{
    ui->textEdit->setVisible(checked);                      //设置文本编辑器的显示和隐藏
    if(checked)
        ui->pushButton->setText(tr("隐藏可扩展窗口"));
    else ui->pushButton->setText(tr("显示可扩展窗口"));
}
