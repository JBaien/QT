/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(800, 600);
        pushButton = new QPushButton(MyWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 100, 93, 28));
        pushButton_2 = new QPushButton(MyWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(500, 100, 93, 28));
        pushButton_3 = new QPushButton(MyWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(100, 200, 93, 28));
        pushButton_4 = new QPushButton(MyWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(500, 200, 93, 28));
        pushButton_5 = new QPushButton(MyWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(100, 300, 93, 28));
        pushButton_6 = new QPushButton(MyWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(500, 300, 93, 28));
        pushButton_7 = new QPushButton(MyWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(100, 400, 141, 28));
        pushButton_8 = new QPushButton(MyWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(500, 400, 93, 28));

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "MyWidget", nullptr));
        pushButton->setText(QApplication::translate("MyWidget", "\351\242\234\350\211\262\345\257\271\350\257\235\346\241\206", nullptr));
        pushButton_2->setText(QApplication::translate("MyWidget", "\346\226\207\344\273\266\345\257\271\350\257\235\346\241\206", nullptr));
        pushButton_3->setText(QApplication::translate("MyWidget", "\345\255\227\344\275\223\345\257\271\350\257\235\346\241\206", nullptr));
        pushButton_4->setText(QApplication::translate("MyWidget", "\350\276\223\345\205\245\345\257\271\350\257\235\346\241\206", nullptr));
        pushButton_5->setText(QApplication::translate("MyWidget", "\346\266\210\346\201\257\345\257\271\350\257\235\346\241\206", nullptr));
        pushButton_6->setText(QApplication::translate("MyWidget", "\350\277\233\345\272\246\345\257\271\350\257\235\346\241\206", nullptr));
        pushButton_7->setText(QApplication::translate("MyWidget", "\351\224\231\350\257\257\346\266\210\346\201\257\345\257\271\350\257\235\346\241\206", nullptr));
        pushButton_8->setText(QApplication::translate("MyWidget", "\345\220\221\345\257\274\345\257\271\350\257\235\346\241\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
