#ifndef MYACTION_H
#define MYACTION_H

#include <QWidget>
#include <QWidgetAction>

class QLineEdit;

class MyAction : public QWidget
{
    Q_OBJECT
public:
    explicit MyAction(QWidget *parent = nullptr);
protected:
    //声明函数，该函数是QWidgetAction类中的虚函数
    QWidget *createWidget(QWidget *parent);
signals:
    //新建信号，用于按下回车时发送
    void getText(const QString &string);

public slots:
    //新建槽，它用来与行编辑器的按下回车键信号关联
    void sendText();
private:
    //声明行编辑器对象的指针
    QLineEdit *lineEdit;
};

#endif // MYACTION_H
