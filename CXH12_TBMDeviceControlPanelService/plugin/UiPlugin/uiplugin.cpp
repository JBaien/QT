#include "uiplugin.h"
#include "tools/HashString/HashString.h"

#include <QQmlEngine>
#include <qmetatype.h>
#include <QQmlContext>
#include <QtQuick>
#include <QQuickWindow>
#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <unistd.h>

UiPlugin::UiPlugin()
{
    commStatus = 6;
    springBackCmd = 0;
}
UiPlugin::~UiPlugin()
{
}
quint8 UiPlugin::getCommValue()
{
    return commStatus;
}
void UiPlugin::setCommValue(const quint8 value)
{
    if(value == commStatus)
        return;
    commStatus = value;
    emit commValueChanged();
}
QString UiPlugin::getText(int num)
{
    auto it = mapDisplay.find(num);
    if(it != mapDisplay.end())
    {
        return QString::fromStdString(it->second);
    }
    return nullptr;
}
void UiPlugin::map_init()
{
    //cmd[0]
    mapDisplay[eCmdNone] = "无指令";
    mapDisplay[eCmdScram] = "急停";


    //cmd[1]
    mapDisplay[eCmdPictureSwitch] = "画面切换";
    mapDisplay[eCmdFullScreenSwitch] = "全屏切换";
    mapDisplay[eCmdPowerClosed] = "动力回路闭合";
    mapDisplay[eCmdPowerBreak] = "动力回路分开";
    mapDisplay[eCmdPower2Closed] = "动力回路2闭合";
    mapDisplay[eCmdPower2Break] = "动力回路2分开";


    //cmd[2]
    mapDisplay[eCmdPower3Closed] = "动力回路3闭合";
    mapDisplay[eCmdPower3Break] = "动力回路3分开";
    mapDisplay[eCmdDustRemovalFanInWater] = "除尘风机进水";
    mapDisplay[eCmdDustRemovalFanStart] = "除尘风机启动";
    mapDisplay[eCmdDustRemovalFanStop] = "除尘风机停止";
    mapDisplay[eCmdAirSupplyFanStart] = "送风风机启动";
    mapDisplay[eCmdAirSupplyFanStop] = "送风风机停止";

    //cmd[3]
    mapDisplay[eCmdOneKeyStartStop] = "一键启停";
    mapDisplay[eCmdSystemReset] = "系统复位";

    //cmd[4]
    mapDisplay[eCmdBelt1FWD] = "1号皮带正转";
    mapDisplay[eCmdBelt1REV] = "1号皮带反转";
    mapDisplay[eCmdBelt2FWD] = "2号皮带正转";
    mapDisplay[eCmdBelt2REV] = "2号皮带反转";
    mapDisplay[eCmdBelt3FWD] = "3号皮带正转";
    mapDisplay[eCmdBelt3REV] = "3号皮带反转";
    mapDisplay[eCmdFWD] = "正转";
    mapDisplay[eCmdREV] = "反转";

    //cmd[5]
    mapDisplay[eCmdLocalSwitch] = "地面切换";
    mapDisplay[eCmdPumpStart] = "泵启动";
    mapDisplay[eCmdPumpStop] = "泵停机";
    mapDisplay[eCmdReset] = "复位";

    //cmd[6]
    mapDisplay[eCmdAutoForward] = "自动前进";
    mapDisplay[eCmdAutoBackward] = "自动后退";
    mapDisplay[eCmdPusherPush] = "推移伸";
    mapDisplay[eCmdPusherPull] = "推移收";
    mapDisplay[eCmdLeftSupportPush] = "左支撑伸";
    mapDisplay[eCmdLeftSupportPull] = "左支撑收";
    mapDisplay[eCmdRightSupportPush] = "右支撑伸";
    mapDisplay[eCmdRightSupportPull] = "右支撑收";

    //cmd[7]
    mapDisplay[eCmdSide1Push] = "侧移1伸";
    mapDisplay[eCmdSide1Pull] = "侧移1收";
    mapDisplay[eCmdSide2Push] = "侧移2伸";
    mapDisplay[eCmdSide2Pull] = "侧移2收";
    mapDisplay[eCmdSide3Push] = "侧移3伸";
    mapDisplay[eCmdSide3Pull] = "侧移3收";

    mapDisplay[eCmdInvalid] = "无效指令";

}
void* UiPlugin::ui_write_thread(void *arg)
{
    UiPlugin* myUi = (UiPlugin*)arg;
    PluginInterface* controlPanelPlugin = static_cast<PluginInterface*>(myUi->pluginList->getPluginByName("ControlPanelPlugin"));
    QString verTemp = QString::fromUtf8((controlPanelPlugin->read("version",0)).toByteArray());
    myUi->version = verTemp.toStdString();//显示版本
    while(1)
    {
//        myUi->commStatus = (controlPanelPlugin->read("sysComm",0)).toInt();//通讯状态
        ++myUi->commStatus;//测试使用
        qDebug() << myUi->commStatus;
        myUi->springBackCmd = (controlPanelPlugin->read("springBackCmd",0)).toInt();//非回弹指令
        myUi->viewText = myUi->getText(myUi->springBackCmd);
        //延时20ms
        usleep(20000);
    }
}
void UiPlugin::funTest()
{
    qDebug() << "funTest is called";

}
void UiPlugin::run()
{
    map_init();
    //更新数据
    pthread_t ui_write_tid;
    int ret = pthread_create(&ui_write_tid,NULL,ui_write_thread,this);
    if(ret == 0)
        printf("ui_write_thread created successfully.\n" );
    else
        fprintf(stderr,"Failed to create ui_write_thread\n");

    //QML界面显示
    //注册uiModel到QML中，可以设置QML端的数据，也可以获取QML端的数据
//    qmlRegisterType<UiPlugin>("uiModel",1,0,"UiPlugin");
//    //创建QML引擎
//    QQmlEngine engine;
//    //加载QML文件
//    QQmlComponent component(&engine,QUrl("qrc:/main.qml"));
//    //实例化QML对象
//    QObject* qmlObject = component.create();
//    QQuickWindow* item = qobject_cast<QQuickWindow*>(qmlObject);
//    qDebug()<< item->height();


//    //创建QML上下文
//    QQmlContext* context = engine.rootContext();
//    //设置上下文属性，可以做QML中使用
//    context->setContextProperty("UiPlugin",this);
//    while(1){}


//    QQmlEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

}
QVariant UiPlugin::read(const QString &type, quint16 channel)
{

}
QVariant UiPlugin::write(const QString &type,quint16 channel,const QVariant &value)
{
    return 0;
}
QVariant UiPlugin::ctrl(const QString &type,const QVariant &value)
{

}
