/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_MyDialog
{
public:
    QPushButton *pushButton;
    QSpinBox *spinBox;

    void setupUi(QDialog *MyDialog)
    {
        if (MyDialog->objectName().isEmpty())
            MyDialog->setObjectName(QString::fromUtf8("MyDialog"));
        MyDialog->resize(300, 60);
        pushButton = new QPushButton(MyDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 15, 93, 28));
        spinBox = new QSpinBox(MyDialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(100, 15, 46, 22));

        retranslateUi(MyDialog);

        QMetaObject::connectSlotsByName(MyDialog);
    } // setupUi

    void retranslateUi(QDialog *MyDialog)
    {
        MyDialog->setWindowTitle(QApplication::translate("MyDialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("MyDialog", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyDialog: public Ui_MyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
