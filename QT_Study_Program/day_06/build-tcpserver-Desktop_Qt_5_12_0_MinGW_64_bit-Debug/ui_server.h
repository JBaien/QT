/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QLabel *severStatusLabel;
    QProgressBar *serverProgressBar;
    QPushButton *startButton;

    void setupUi(QDialog *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QString::fromUtf8("Server"));
        Server->resize(600, 200);
        severStatusLabel = new QLabel(Server);
        severStatusLabel->setObjectName(QString::fromUtf8("severStatusLabel"));
        severStatusLabel->setGeometry(QRect(100, 30, 72, 15));
        serverProgressBar = new QProgressBar(Server);
        serverProgressBar->setObjectName(QString::fromUtf8("serverProgressBar"));
        serverProgressBar->setGeometry(QRect(90, 60, 390, 30));
        serverProgressBar->setValue(0);
        startButton = new QPushButton(Server);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(230, 130, 93, 28));

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QDialog *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", nullptr));
        severStatusLabel->setText(QApplication::translate("Server", "\346\234\215\345\212\241\345\231\250\347\253\257\357\274\232", nullptr));
        startButton->setText(QApplication::translate("Server", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
