#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QObject>
#include "tools/pluginmanager/pluginlist.h"

class PluginInterface : public QObject
{
    Q_OBJECT
public:
    explicit PluginInterface(QObject *parent = nullptr){}
    virtual ~PluginInterface(){}

    virtual void run() = 0;
    virtual QVariant read(const QString &type, quint16 channel) = 0;
    virtual QVariant write(const QString &type,quint16 channel,const QVariant &value) = 0;
    virtual QVariant ctrl(const QString &type,const QVariant &value) = 0;

    void setObjectName(const QString &name){m_name = name;}
    void setList(PluginList* pluginPtr){pluginList = pluginPtr;}

    QString m_name;
    PluginList* pluginList;
signals:

public slots:
private:

};
Q_DECLARE_INTERFACE(PluginInterface, "com.machine.PluginInterface")
#endif // PLUGININTERFACE_H
