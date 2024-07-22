#include "tools/pluginmanager/pluginmanager.h"
#include "tools/plugininterface/plugininterface.h"
#include "tools/HashString/HashString.h"
#include "ui/ui.h"

#include <QFile>
#include <QQmlEngine>
#include <qmetatype.h>
#include <QQmlContext>
#include <QtQuick>
#include <QQuickWindow>
#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    //插件加载
    PluginManager pluginManager;
    qDebug() << "App strat";
    pluginManager.loadPlugins("/home/CXH12/plugins_config.json");
    pluginManager.executePlugins("/home/CXH12/plugins_config.json");


    //QML界面显示
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Ui", Ui::GetInstance());
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    //更新界面显示的数据
    Ui::GetInstance()->RegreshViewData(&pluginManager);
    return app.exec();
    qDebug() << "App Down";
}
