#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QObject>
#include "pluginlist.h"

class PluginManager : public QObject
{
    Q_OBJECT
public:
    explicit PluginManager(QObject *parent = nullptr);
    void loadPlugins(const QString &configFilePath);
    void executePlugins(const QString &configFilePath);
signals:

public slots:
private:
    PluginList pluginList;
};

#endif // PLUGINMANAGER_H
