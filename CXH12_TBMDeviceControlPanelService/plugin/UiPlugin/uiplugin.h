#ifndef UIPLUGIN_H
#define UIPLUGIN_H

#include <QQuickView>
#include <QObject>
#include <QtPlugin>
#include "tools/plugininterface/plugininterface.h"
#include <string>
#include <map>
class  UiPlugin :public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.machine.uiplugin" FILE "UiPlugin.json")
    Q_INTERFACES(PluginInterface)
//    Q_PROPERTY(quint8 commValue READ getCommValue WRITE setCommValue NOTIFY commValueChanged)
public:
    UiPlugin();
    ~UiPlugin();

    void run() override;
    QVariant read(const QString &type, quint16 channel) override;
    QVariant write(const QString &type,quint16 channel,const QVariant &value) override;
    QVariant ctrl(const QString &type,const QVariant &value) override;
private:
    void map_init();
    static void* ui_write_thread(void *arg);
    QString getText(int num);
    Q_INVOKABLE void funTest();
private:
    quint8 commStatus;
    unsigned char springBackCmd;
    std::string version;
    std::map<unsigned char,std::string> mapDisplay;
    QString viewText;

public:
    quint8 getCommValue();
    void setCommValue(const quint8 value);
signals:
    void commValueChanged();
};
//掘进机操作台指令
typedef enum ECmd
{
    //cmd[0]
    eCmdNone = 0,//无指令
    eCmdScram,//急停

    //cmd[1]
    eCmdPictureSwitch,//画面切换
    eCmdFullScreenSwitch,//全屏切换
    eCmdPowerClosed,//动力回路闭合
    eCmdPowerBreak,//动力回路分开
    eCmdPower2Closed,//动力回路2闭合
    eCmdPower2Break,//动力回路2分开

    //cmd[2]
    eCmdPower3Closed,//动力回路3闭合
    eCmdPower3Break,//动力回路3分开
    eCmdDustRemovalFanInWater,//除尘风机进水
    eCmdDustRemovalFanStart,//除尘风机启动
    eCmdDustRemovalFanStop,//除尘风机停止
    eCmdAirSupplyFanStart,//送风风机启动
    eCmdAirSupplyFanStop,//送风风机停止

    //cmd[3]
    eCmdOneKeyStartStop,//一键启停
    eCmdSystemReset,//系统复位

    //cmd[4]
    eCmdBelt1FWD,//1号皮带正转
    eCmdBelt1REV,//1号皮带反转
    eCmdBelt2FWD,//2号皮带正转
    eCmdBelt2REV,//2号皮带反转
    eCmdBelt3FWD,//3号皮带正转
    eCmdBelt3REV,//3号皮带反转
    eCmdFWD,//正转
    eCmdREV,//反转

    //cmd[5]
    eCmdLocalSwitch,//地面切换
    eCmdPumpStart,//泵启动
    eCmdPumpStop,//泵停机
    eCmdReset,//复位


    //cmd[6]
    eCmdAutoForward,//自动前进
    eCmdAutoBackward,//自动后退
    eCmdPusherPush,//推移伸
    eCmdPusherPull,//推移收
    eCmdLeftSupportPush,//左支撑伸
    eCmdLeftSupportPull,//左支撑收
    eCmdRightSupportPush,//右支撑伸
    eCmdRightSupportPull,//右支撑收

    //cmd[7]
    eCmdSide1Push,//侧移1伸
    eCmdSide1Pull,//侧移1收
    eCmdSide2Push,//侧移2伸
    eCmdSide2Pull,//侧移2收
    eCmdSide3Push,//侧移3伸
    eCmdSide3Pull,//侧移3收

    eCmdInvalid = 0xff, //无效指令
}Ecmd;
#endif // UIPLUGIN_H
