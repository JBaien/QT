#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QIntValidator>
#include <QCompleter>
#include <QStringList>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //新建验证器
    QValidator *validator = new QIntValidator(100, 999, this);
    ui->lineEdit_3->setValidator(validator);

    QStringList wordlist;
    wordlist << "Qt" << "Qt Creator" << tr("你好");
    QCompleter *completer = new QCompleter(wordlist, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);                 //设置大小写不敏感
    ui->lineEdit_4->setCompleter(completer);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_lineEdit_2_returnPressed()
{
    ui->lineEdit_3->setFocus();
    qDebug() << ui->lineEdit_2->text();
    qDebug() << ui->lineEdit_2->displayText();
}

void MyWidget::on_lineEdit_3_returnPressed()
{
    qDebug() << ui->lineEdit_3->text();
}
