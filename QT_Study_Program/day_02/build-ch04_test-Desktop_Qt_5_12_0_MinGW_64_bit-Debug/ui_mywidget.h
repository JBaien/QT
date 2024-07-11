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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myWidget
{
public:
    QDateTimeEdit *dateTimeEdit;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QDial *dial;
    QScrollBar *horizontalScrollBar;
    QScrollBar *verticalScrollBar;
    QSlider *verticalSlider;

    void setupUi(QWidget *myWidget)
    {
        if (myWidget->objectName().isEmpty())
            myWidget->setObjectName(QString::fromUtf8("myWidget"));
        myWidget->resize(400, 300);
        dateTimeEdit = new QDateTimeEdit(myWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(10, 40, 360, 22));
        timeEdit = new QTimeEdit(myWidget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(130, 10, 118, 22));
        dateEdit = new QDateEdit(myWidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(10, 10, 110, 22));
        dateEdit->setCalendarPopup(true);
        spinBox = new QSpinBox(myWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(30, 100, 60, 22));
        spinBox->setSingleStep(10);
        doubleSpinBox = new QDoubleSpinBox(myWidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(120, 100, 70, 22));
        doubleSpinBox->setDecimals(3);
        dial = new QDial(myWidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(40, 160, 50, 64));
        horizontalScrollBar = new QScrollBar(myWidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(140, 160, 160, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        verticalScrollBar = new QScrollBar(myWidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(320, 110, 16, 160));
        verticalScrollBar->setOrientation(Qt::Vertical);
        verticalSlider = new QSlider(myWidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(360, 100, 22, 160));
        verticalSlider->setOrientation(Qt::Vertical);

        retranslateUi(myWidget);
        QObject::connect(dial, SIGNAL(sliderMoved(int)), horizontalScrollBar, SLOT(setValue(int)));
        QObject::connect(dial, SIGNAL(sliderMoved(int)), verticalScrollBar, SLOT(setValue(int)));
        QObject::connect(dial, SIGNAL(sliderMoved(int)), verticalSlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(myWidget);
    } // setupUi

    void retranslateUi(QWidget *myWidget)
    {
        myWidget->setWindowTitle(QApplication::translate("myWidget", "myWidget", nullptr));
        timeEdit->setDisplayFormat(QApplication::translate("myWidget", "H:mm:ssA", nullptr));
        spinBox->setSuffix(QApplication::translate("myWidget", "%", nullptr));
        spinBox->setPrefix(QString());
        doubleSpinBox->setPrefix(QApplication::translate("myWidget", "$", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myWidget: public Ui_myWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
