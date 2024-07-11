#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();

private slots:
    void on_action_New_triggered();

    void on_actionxians_triggered();

private:
    Ui::MyMainWindow *ui;
};

#endif // MYMAINWINDOW_H
