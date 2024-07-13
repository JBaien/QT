/********************************************************************************
** Form generated from reading UI file 'sender.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDER_H
#define UI_SENDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Sender
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *Sender)
    {
        if (Sender->objectName().isEmpty())
            Sender->setObjectName(QString::fromUtf8("Sender"));
        Sender->resize(400, 300);
        pushButton = new QPushButton(Sender);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 190, 93, 28));

        retranslateUi(Sender);

        QMetaObject::connectSlotsByName(Sender);
    } // setupUi

    void retranslateUi(QDialog *Sender)
    {
        Sender->setWindowTitle(QApplication::translate("Sender", "Sender", nullptr));
        pushButton->setText(QApplication::translate("Sender", "\350\277\233\350\241\214\345\271\277\346\222\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sender: public Ui_Sender {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDER_H
