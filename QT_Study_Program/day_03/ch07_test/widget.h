#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
};

#endif // WIDGET_H
