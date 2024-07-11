// #include <QApplication>
// #include <QDialog>
// #include <QLabel>
#include "ui_hellodialog.h"
/* QT中每一个类都有一个与其同名的头文件，这里要包含这些类的定义 */

int main(int argc, char *argv[]) {

  QApplication a(argc, argv);
  // 新建QApplication类对象，用于管理应用程序资源，任何一个Qt
  // Widgets程序都需要有一个QApplication对象
  // 因为QT程序可以接受命令行变量，所以它需要argc和argv两个参数

  QDialog w;
  // 新建QDialog对象，QDialog类用来实现一个对话框界面
  // w.resize(400, 300);

  // QLabel label(&w);
  //  新建一个QLabel对象，并将QDialog对象作为参数，表明了对话框是它的父窗口

  // label.setText("Hello World!");
  Ui::HelloDialog ui;
  ui.setupUi(&w);
  w.show();
  return a.exec();
  // 让QApplication对象进入事件循环
}
