#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <blockingmodel.h>
#include <QQmlContext>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

//    QString filePath = "d:/git/QT/tets3/file/blockingModel.json";
    BlockingModel blockingModel;
    blockingModel.loadFromJson(":/file/blockingModel.json");
    blockingModel.addBlockingRecord("AC127漏电屏蔽");
    blockingModel.saveToJson(":/file/blockingModel.json");

    engine.rootContext()->setContextProperty("blockingModel", &blockingModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
