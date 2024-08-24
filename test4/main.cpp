#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "dbmanager.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    // 打开数据库(如果不存在则创建后再打开)
    DBManager::init("whaledb.db");
    // 创建表格
    DBManager::runSql("create table person (id int primary key , firstname varchar(20), lastname varchar(20))");
    // 插入数据
//    DBManager::runSql("insert into person values(103, 'Lars', 'Gordon')");
//    DBManager::runSql("insert into person values(104, '白', '急停')");
    // 查询数据
    QSqlQuery query;
    query.exec("select * from person ORDER BY id DESC");
    while(query.next()) {
        qDebug()<<query.value(0).toInt();
        qDebug()<<query.value(1).toString();
        qDebug()<<query.value(2).toString();
    }
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
