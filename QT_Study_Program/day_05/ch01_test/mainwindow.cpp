#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtXml>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDomDocument doc;
    //添加处理指令即XML说明
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml", "verion=\"1.0\"encoding=\"UTF-8\"");
    doc.appendChild(instruction);
    //添加根元素
    QDomElement root = doc.createElement("书库");
    doc.appendChild(root);
    //添加第一个图书元素及其子元素
    QDomElement book = doc.createElement("图书");
    QDomAttr id = doc.createAttribute("编号");
    QDomElement title = doc.createElement("书名");
    QDomElement author = doc.createElement("作者");
    QDomText text;
    id.setValue(QString("1"));
    book.setAttributeNode(id);
    text = doc.createTextNode("Qt");
    title.appendChild(text);
    text = doc.createTextNode("shiming");
    author.appendChild(text);
    book.appendChild(title);
    book.appendChild(author);
    root.appendChild(book);
    //添加第一个图书元素及其子元素
    book = doc.createElement("图书");
    id = doc.createAttribute("编号");
    title = doc.createElement("书名");
    author = doc.createElement("作者");
    id.setValue(QString("2"));
    book.setAttributeNode(id);
    text = doc.createTextNode("Linux");
    title.appendChild(text);
    text = doc.createTextNode("yafei");
    author.appendChild(text);
    book.appendChild(title);
    book.appendChild(author);
    root.appendChild(book);

    QFile file("my.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice :: Truncate)) return ;
    QTextStream out(&file);
    //将文档保存到文件，4为字符缩进字符串
    doc.save(out, 4);
    file.close();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_5_clicked()
{
    //先清空显示
    ui->listWidget->clear();
    QFile file("my.xml");
    if(!file.open(QIODevice::ReadOnly)) return ;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return ;
    }
    file.close();
    QDomElement docElem = doc.documentElement();
    QDomNode n = docElem.firstChild();
}
