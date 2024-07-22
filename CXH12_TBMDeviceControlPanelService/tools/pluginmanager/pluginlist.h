#ifndef PLUGINLIST_H
#define PLUGINLIST_H

#include <QObject>

class PluginList : public QObject
{
    Q_OBJECT
public:
    explicit PluginList(QObject *parent = nullptr);
    void setPluginPtr(const QString &name,void* pluginPtr);
    void* getPluginByName(const QString &name);
signals:

public slots:
private:
    std::map<QString,void*> m_plugins;
};

#endif // PLUGINLIST_H
