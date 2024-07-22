#include "pluginlist.h"

PluginList::PluginList(QObject *parent) : QObject(parent)
{

}
void PluginList::setPluginPtr(const QString &name, void *pluginPtr)
{
    m_plugins[name] = pluginPtr;
}
void* PluginList::getPluginByName(const QString &name)
{
    for(const auto& pair : m_plugins)
    {
        if(pair.first == name)
            return pair.second;
    }
    return nullptr;
}
