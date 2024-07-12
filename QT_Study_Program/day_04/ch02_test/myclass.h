#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ getUserName WRITE setUserName NOTIFY userNameChanged)             //注册属性userName
public:
    explicit MyClass(QObject *parent = nullptr);
    QString getUserName() const
    { return m_userName; }
    void setUserName(QString username)
    {
        m_userName = username;
        emit userNameChanged(username);
    }

signals:
    void userNameChanged(QString);

public slots:

private:
    QString m_userName;
};

#endif // MYCLASS_H
