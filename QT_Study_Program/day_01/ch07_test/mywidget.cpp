#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QErrorMessage>

QWizardPage *MyWidget::createPage1()                    //向导
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("介绍"));
    return page;
}

QWizardPage *MyWidget::createPage2()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("选择信息"));
    return page;
}

QWizardPage *MyWidget::createPage3()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("结束"));
    return page;
}

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    errordlg = new QErrorMessage(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
//    QColor color = QColorDialog::getColor(Qt::blue, this, tr("颜色对话框"), QColorDialog::ShowAlphaChannel);
//    qDebug() << "color: " << color;
    QColorDialog dialog(Qt::red, this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color = dialog.currentColor();
    qDebug() << "color: " << color;
}

void MyWidget::on_pushButton_2_clicked()
{
    QStringList filenames = QFileDialog::getOpenFileNames(this, tr("文件对话框"), "F:", tr("图片文件( *png *jpg);;文本文件( *txt)"));
    qDebug() << "fileNames: " << filenames;
}

void MyWidget::on_pushButton_3_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok) ui->pushButton_3->setFont(font);
    else qDebug() << tr("没有选择字体！");
}

void MyWidget::on_pushButton_4_clicked()
{
    bool ok;
    QString string = QInputDialog::getText(this, tr("输入字符串对话框"), tr("请输入用户名："), QLineEdit::Normal, tr("admin"), &ok);
    if(ok) qDebug() << "string: " << string;
    int value1 = QInputDialog::getInt(this, tr("输入整数对话框"), tr("请输入-1000到1000之间的数值"), 100, -1000, 1000, 10, &ok);
    if(ok) qDebug() << "value1: " << value1;

    QStringList items;
    items << tr("hd") << tr("zk");
    QString item = QInputDialog::getItem(this, tr("输入条目对话框"), tr("请输入一个条目"), items, 0, true, &ok);
    //参数true 表示条目是否可以被更改， true表示可以
    if(ok) qDebug() << "item: " << item;
}

void MyWidget::on_pushButton_5_clicked()
{
//    //问题对话框
//    int ret1 = QMessageBox::question(this, tr("问题对话框"), tr("今天星期一？"), QMessageBox::Yes, QMessageBox::No);
//    if(ret1 == QMessageBox::Yes) qDebug() << tr("是的！");
//    else qDebug() << tr("不是！");

//    int ret2 = QMessageBox::warning(this, tr("警告对话框"), tr("不能退出！"), QMessageBox::Abort);
//    if(ret2 == QMessageBox::Abort) qDebug() << tr("警告！");

    QMessageBox::about(this, tr("关于对话框"), tr("关于2024年7月9的学习！"));
}

void MyWidget::on_pushButton_6_clicked()
{
    QProgressDialog dialog(tr("文件复制进度"), tr("取消"), 0, 500000, this);
    dialog.setWindowTitle(tr("进度对话框"));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.show();
    for(int i = 0; i < 500000; i++){                    //演示复制进度
        dialog.setValue(i);                             //进度条当前值
        QCoreApplication::processEvents();              //避免界面冻结
        if(dialog.wasCanceled()) break;                 //按下取消按钮则中断
    }
    dialog.setValue(500000);
    qDebug() << tr("复制结束！");
}

void MyWidget::on_pushButton_7_clicked()
{
    errordlg->setWindowTitle(tr("错误信息对话框"));
    errordlg->showMessage(tr("因为***而出错了！"));
}

void MyWidget::on_pushButton_8_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle("向导对话框");
    wizard.addPage(createPage1());
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.exec();
}
