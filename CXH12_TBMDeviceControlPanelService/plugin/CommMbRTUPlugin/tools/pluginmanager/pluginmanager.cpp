#include "pluginmanager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPluginLoader>
#include <QDir>
#include <QDebug>
#include "tools/plugininterface/plugininterface.h"
PluginManager::PluginManager(QObject *parent) : QObject(parent)
{

}
void PluginManager::loadPlugins(const QString &configFilePath)
{
    QFile configFile(configFilePath);
    if(!configFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "File to open config file";
        return;
    }
    qDebug() << "Successfully to open config file";
    QByteArray configData = configFile.readAll();
    QJsonDocument configDoc = QJsonDocument::fromJson(configData);
    QJsonObject pluginsObj = configDoc.object();

    for(auto it = pluginsObj.begin();it != pluginsObj.end(); it++)
    {
        QJsonObject pluginObj = it.value().toObject();
        QString pluginPath = pluginObj["path"].toString();
//        qDebug() << "pluginPath = " << pluginPath;
        QPluginLoader loader(pluginPath);
        if(!loader.load())
        {
            qDebug() << "Failed to load plugin:" << loader.errorString();
        }
        QObject* myPlugin = loader.instance();
        qDebug() << myPlugin;
        if(myPlugin)
        {
            PluginInterface* plugin = qobject_cast<PluginInterface*>(myPlugin);
            qDebug() << plugin;
            if(plugin)
            {
                plugin->setObjectName(it.key());
                plugin->setList(&pluginList);
                pluginList.setPluginPtr(it.key(),plugin);
            }
            else
            {
                qDebug() << "Failed to cast plugin object to PluginInterface";
            }
        }
        else
        {
            qDebug() << "Failed to load plugin from" << pluginPath;
        }
    }

}

void PluginManager::executePlugins(const QString &configFilePath)
{
    QFile configFile(configFilePath);
    if(!configFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Failed to open config File";
        return;
    }
    QByteArray configData = configFile.readAll();
    QJsonDocument configDoc = QJsonDocument::fromJson(configData);
    QJsonObject pluginsObj = configDoc.object();
    for(auto it = pluginsObj.begin();it != pluginsObj.end();it++)
    {
        PluginInterface* plugin = static_cast<PluginInterface*>(pluginList.getPluginByName(it.key()));
        plugin->run();
    }
}
