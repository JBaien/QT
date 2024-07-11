#include "mywidget.h"
#include <QApplication>
#include "mydialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    MyDialog dialog;
    if(dialog.exec() == QDialog::Accepted){

            w.show();
            return a.exec();
    }


    else return 0;
}
