#include <QtWidgets>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[]){

//    QApplication a(argc, argv);
//    //新建QWidget类对象，默认parent参数是0，所以它是个窗口
//    QWidget *widget = new QWidget();
//    //设置窗口标题
//    widget->setWindowTitle(QObject::tr("这是一个Widget"));
//    QLabel *label = new QLabel();
//    label->setWindowTitle(QObject::tr("这是一个Label"));

//    //改变部件大小
//    label->resize(500, 100);
//    widget->resize(500, 100);

//    //label指定了父窗口为widget，所以不是窗口
//    QLabel *label12 = new QLabel(widget);
//    label12->setText(QObject::tr("子窗口"));

//    label->show();
//    widget->show();
//    int ret = a.exec();
//    delete label;
//    delete widget;
//    return ret;

    QApplication a(argc, argv);

    QWidget widget;
    widget.resize(400, 300);
    widget.move(200, 100);
    widget.show();
    int x = widget.x();
    qDebug("x : %d", x);
    int y = widget.y();
    qDebug("y : %d", y);
    QRect geometry = widget.geometry();
    QRect frame = widget.frameGeometry();
    qDebug() << "geometry: " << geometry << "frame: " << frame;

    qDebug() << "pos: " << widget.pos() << "rect: " << widget.rect()
             << endl << "size: " << widget.size() << endl << "width: "
             << widget.width() << endl << "height: " << widget.height();

    return  a.exec();

}
