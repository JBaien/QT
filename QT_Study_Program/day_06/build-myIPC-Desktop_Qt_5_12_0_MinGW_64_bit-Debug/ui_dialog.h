/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *loadFromFileButton;
    QPushButton *loadFromSharedMemoryButton;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(690, 580);
        loadFromFileButton = new QPushButton(Dialog);
        loadFromFileButton->setObjectName(QString::fromUtf8("loadFromFileButton"));
        loadFromFileButton->setGeometry(QRect(120, 130, 150, 28));
        loadFromSharedMemoryButton = new QPushButton(Dialog);
        loadFromSharedMemoryButton->setObjectName(QString::fromUtf8("loadFromSharedMemoryButton"));
        loadFromSharedMemoryButton->setGeometry(QRect(400, 130, 150, 28));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 250, 72, 15));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        loadFromFileButton->setText(QApplication::translate("Dialog", "\344\273\216\346\226\207\344\273\266\344\270\255\345\212\240\350\275\275\345\233\276\347\211\207", nullptr));
        loadFromSharedMemoryButton->setText(QApplication::translate("Dialog", "\344\273\216\345\205\261\344\272\253\345\206\205\345\255\230\346\230\276\347\244\272\345\233\276\347\211\207", nullptr));
        label->setText(QApplication::translate("Dialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
