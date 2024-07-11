/********************************************************************************
** Form generated from reading UI file 'hellodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLODIALOG_H
#define UI_HELLODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_HelloDialog
{
public:
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QCheckBox *checkBox;
    QCommandLinkButton *commandLinkButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *HelloDialog)
    {
        if (HelloDialog->objectName().isEmpty())
            HelloDialog->setObjectName(QString::fromUtf8("HelloDialog"));
        HelloDialog->resize(966, 656);
        pushButton = new QPushButton(HelloDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 610, 93, 28));
        radioButton = new QRadioButton(HelloDialog);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(360, 190, 115, 19));
        checkBox = new QCheckBox(HelloDialog);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(360, 230, 91, 19));
        commandLinkButton = new QCommandLinkButton(HelloDialog);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(340, 270, 187, 41));
        buttonBox = new QDialogButtonBox(HelloDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(350, 340, 193, 28));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(HelloDialog);

        QMetaObject::connectSlotsByName(HelloDialog);
    } // setupUi

    void retranslateUi(QDialog *HelloDialog)
    {
        HelloDialog->setWindowTitle(QApplication::translate("HelloDialog", "HelloDialog", nullptr));
        pushButton->setText(QApplication::translate("HelloDialog", "\346\217\220\344\272\244", nullptr));
        radioButton->setText(QApplication::translate("HelloDialog", "RadioButton", nullptr));
        checkBox->setText(QApplication::translate("HelloDialog", "CheckBox", nullptr));
        commandLinkButton->setText(QApplication::translate("HelloDialog", "CommandLinkButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelloDialog: public Ui_HelloDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLODIALOG_H
