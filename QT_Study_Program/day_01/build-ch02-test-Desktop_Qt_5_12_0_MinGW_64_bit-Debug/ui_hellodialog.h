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
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_HelloDialog {
public:
  void setupUi(QDialog *HelloDialog) {
    if (HelloDialog->objectName().isEmpty())
      HelloDialog->setObjectName(QString::fromUtf8("HelloDialog"));
    HelloDialog->resize(120, 120);

    retranslateUi(HelloDialog);

    QMetaObject::connectSlotsByName(HelloDialog);
  } // setupUi

  void retranslateUi(QDialog *HelloDialog) {
    HelloDialog->setWindowTitle(
        QApplication::translate("HelloDialog", "Dialog", nullptr));
  } // retranslateUi
};

namespace Ui {
class HelloDialog : public Ui_HelloDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLODIALOG_H
