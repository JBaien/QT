#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <alarmhistory.h>
#include <blockingmodel.h>
#include <QQmlContext>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

//    QString filePath = "d:/git/QT/tets3/file/blockingModel.json";
//    BlockingModel blockingModel;
//    blockingModel.loadFromJson("blockingModel.json");
//    blockingModel.addBlockingRecord("24漏电屏蔽ssssssssssssssssssssssssss");
//    blockingModel.saveToJson("blockingModel.json");
//    engine.rootContext()->setContextProperty("blockingModel", &blockingModel);


//    AlarmModel alarmModel;
//    alarmModel.loadFromJson("alarmHistory.json");
    // 添加新的报警记录
//    alarmModel.addAlarmRecord("新的报警消息", true, "19:30:57");
//    alarmModel.addAlarmRecord("新的报警消息", false, "19:46:08");
//    alarmModel.saveToJson("alarmHistory.json");

//    engine.rootContext()->setContextProperty("alarmModel", &alarmModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
