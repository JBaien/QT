#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class MyLineEdit;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    bool eventFilter(QObject *obj, QEvent *event);
    ~Widget();

private:
    Ui::Widget *ui;
    MyLineEdit *lineEdit;

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // WIDGET_H
