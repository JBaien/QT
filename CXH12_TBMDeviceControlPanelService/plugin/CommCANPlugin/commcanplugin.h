#ifndef COMMCANPLUGIN_H
#define COMMCANPLUGIN_H

#include <QQuickView>
#include <QObject>
#include <QtPlugin>
#include "tools/plugininterface/plugininterface.h"
#include <string>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <QVariant>

typedef struct Rock_t
{
    uint16_t LeftTrack;
    uint16_t RightTrack;
    uint16_t CutLeftRight;
    uint16_t CutUpDown;
}Rock_t;

//需和操作台插件中结构保持一致
typedef struct TFrameTxData
{
    //驾驶室操作台
    //TPDO:0x180+ID
    struct TFrame0
    {
        struct TWord0
        {
            //char[0]
            unsigned short int dataValid : 1;//数据有效性
            unsigned short int scram : 1;//急停
            unsigned short int : 1;//无效数据
            unsigned short int : 1;//无效数据
            unsigned short int heartBead : 1;//心跳
            unsigned short int : 3;//无效数据

            //char[1]
            unsigned short int pageUp : 1;//上翻页
            unsigned short int pageDown : 1;//下翻页
            unsigned short int : 6;//无效数据

        }Word0;
        struct TWord1
        {
            //char[2]
            unsigned short int oilPumpStart : 1;//油泵启动
            unsigned short int dummyDatas2_1 : 1;//空
            unsigned short int cutLowStart : 1;//截低启动
            unsigned short int dummyDatas2_3 : 1;//空
            unsigned short int cutHighStart : 1;//截高启动
            unsigned short int dummyDatas2_5 : 1;//空
            unsigned short int transport2FWD : 1;//二运正转
            unsigned short int dummyDatas2_7 : 1;//空


            //char[3]
            unsigned short int fan1Start : 1;//风机1启动
            unsigned short int fan2Start : 1;//风机2启动
            unsigned short int anchorRMTCtrl : 1;//锚杆遥控
            unsigned short int anchorSupply : 1;//锚支
            unsigned short int alarmBellStart : 1;//警铃
            unsigned short int dummyDatas3_5 : 1;//空
            unsigned short int powerOn : 1;//开机
            unsigned short int reset : 1;//复位
        }Word1;
        struct TWord2
        {
            //char[4]
            unsigned short int autoCut : 1;//自动截割
            unsigned short int backSupply : 1;//备用/支护
            unsigned short int dummyDatas4_2 : 1;//空
            unsigned short int dummyDatas4_3 : 1;//空
            unsigned short int dummyDatas4_4 : 1;//空
            unsigned short int dummyDatas4_5 : 1;//空
            unsigned short int RTMCtrl : 1;//遥控
            unsigned short int remoteCtrl : 1;//远控

            //char[5]
            unsigned short int keyUp : 1;//上
            unsigned short int keyDown : 1;//下
            unsigned short int keyAdd : 1;//加
            unsigned short int keySubtrac : 1;//减
            unsigned short int keyConfirm : 1;//确认
            unsigned short int keyGoBack : 1;//返回
            unsigned short int autoCutInterVene : 1;//自动截割干预
            unsigned short int lubrication : 1;//润滑
        }Word2;
        struct TWord3
        {
            //char[6]
            unsigned short int : 8;

            //char[7]
            unsigned short int : 8;
        }Word3;
    }Frame0;
    //TPDO:0x280+ID
    struct TFrame1
    {
        struct TWord0
        {
            //char[0]
            unsigned short int LeftTrack:8;

            //char[1]
            unsigned short int RightTrack:8;

        }Word0;
        struct TWord1
        {
            //char[2]
            unsigned short int CutLeftRight:8;

            //char[3]
            unsigned short int CutUpDown:8;

        }Word1;
        struct TWord2
        {
            unsigned short int :16;
        }Word2;
        struct TWord3
        {
            unsigned short int :16;
        }Word3;
    }Frame1;
    //TPDO:0x380+ID
    struct TFrame2
    {
        unsigned long int frame2;
    }Frame2;
    //TPDO:0x480+ID
    struct TFrame3
    {
        unsigned long int frame3;
    }Frame3;
    //TPDO:0x880+ID
    struct TFrame4
    {
        unsigned long int frame4;
    }Frame4;
}FrameTxData;
typedef struct TFrameRxData
{
    //RPDO:0x200+ID
    struct TFrame0
    {
        unsigned long int frame0;
    }Frame0;
    //RPDO:0x300+ID
    struct TFrame1
    {
        unsigned long int frame1;
    }Frame1;
    //RPDO:0x400+ID
    struct TFrame2
    {
        unsigned long int frame2;
    }Frame2;
    //RPDO:0x500+ID
    struct TFrame3
    {
        unsigned long int frame3;
    }Frame3;
    //RPDO:0x600+ID
    struct TFrame4
    {
        unsigned long int frame4;
    }Frame4;
}FrameRxData;

class  CommCANPlugin : public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.machine.commcanplugin" FILE "CommCANPlugin.json")
    Q_INTERFACES(PluginInterface)
public:
    CommCANPlugin();
    ~CommCANPlugin();

    void run() override;
    QVariant read(const QString &type, quint16 channel) override;
    QVariant write(const QString &type,quint16 channel,const QVariant &value) override;
    QVariant ctrl(const QString &type,const QVariant &value) override;
private:
    int canInit();
    void refresh_can_transmitData(unsigned long long switchCmd,Rock_t& rock,int dataValidFlag);
    void refresh_can_transmitBuff();
    int can_write_data();
    static void* can_write_thread(void *arg);
    void refresh_can_receiveBuff();
    void refresh_can_receiveData();
    void can_read_data();
    static void* can_read_thread(void *arg);
    static void* can_refrsh_readData_thread(void *arg);
    bool DataValidityDetection(unsigned long long switchCmd);
private:
    int can_sockfd;
    std::string ifname;//can接口名称
    int bitRate;//can波特率
    int baseFrameID;
    int canReceiveCounter[5];
    FrameTxData frameTxData;
    FrameRxData frameRxData;
    int canReceiveTime;
    struct can_frame frameIDTx[5];
    struct can_frame frameIDRx;
    bool commCanStatus;
};

//回弹型按键枚举(需和SwitchPlugin保持一致)
typedef enum E_BACK_KEY
{
    //驾驶室操作台
    E_RESET,//复位
    E_POWER_ON,//开机
    E_ALARM_BELL_START,//警铃
    E_LUBRICATION,//润滑
    E_AUTO_CUT_INTERVENE,//截割干预
    E_OIL_PUMP_START,//油泵
    E_TRANSPORT_2_FWD,//二运
    E_CUT_HIGH_START,//截高
    E_CUT_LOW_START,//截低
    E_1_FAN,//风机1
    E_2_FAN,//风机2
    E_PAGE_UP,//上翻页
    E_PAGE_DOWN,//下翻页
    E_UP,//上
    E_DOWN,//下
    E_ADD,//加
    E_SUBTRAC,//减
    E_CONFIRM,//确认
    E_GO_BACK,//返回
    E_BACK_KEY_END,//结束标识
}E_BACK_KEY;
//自锁定开关
typedef enum E_NOT_BACK_KEY
{
    E_SCRAM,//急停
    E_RMT_CTRL,//遥控
    E_REMOTE_CTRL,//远控
    E_AUTO_CUT,//自动截割
    E_BACK_SUPPLY,//备用/支护
    E_ANCHOR_RMT_CTRL,//锚杆遥控
    E_ANCHOR_SUPPLY,//锚支
    E_NOT_BACK_KEY_END,//结束标识
}E_NOT_BACK_KEY;
//定义8Byte指令值
//回弹型开关
#define RESET                                   (0x00000001 << E_RESET)//复位
#define POWER_ON                                (0x00000001 << E_POWER_ON)//开机
#define ALARM_BELL_START                        (0x00000001 << E_ALARM_BELL_START)//警铃
#define LUBRICATION                             (0x00000001 << E_LUBRICATION)//润滑
#define AUTO_CUT_INTERVENE                      (0x00000001 << E_AUTO_CUT_INTERVENE)//截割干预
#define OIL_PUMP_START                          (0x00000001 << E_OIL_PUMP_START)//油泵
#define TRANSPORT_2_FWD                         (0x00000001 << E_TRANSPORT_2_FWD)//二运
#define CUT_HIGH_START                          (0x00000001 << E_CUT_HIGH_START)//截高
#define CUT_LOW_START                           (0x00000001 << E_CUT_LOW_START)//截低
#define FIRST_1_FAN                             (0x00000001 << E_1_FAN)//风机1
#define SECOND_2_FAN                            (0x00000001 << E_2_FAN)//风机2
#define PAGE_UP                                 (0x00000001 << E_PAGE_UP)//上翻页
#define PAGE_DOWN                               (0x00000001 << E_PAGE_DOWN)//下翻页
#define UP                                      (0x00000001 << E_UP)//上
#define DOWN                                    (0x00000001 << E_DOWN)//下
#define ADD                                     (0x00000001 << E_ADD)//加
#define SUBTRAC                                 (0x00000001 << E_SUBTRAC)//减
#define CONFIRM                                 (0x00000001 << E_CONFIRM)//确认
#define GO_BACK                                 (0x00000001 << E_GO_BACK)//返回


//非回弹型开关
#define SCRAM                                   (0x00000001 << E_SCRAM)//急停
#define RMT_CTRL                                (0x00000001 << E_RMT_CTRL)//遥控
#define REMOTE_CTRL                             (0x00000001 << E_REMOTE_CTRL)//远控
#define AUTO_CUT                                (0x00000001 << E_AUTO_CUT)//自动截割
#define BACK_SUPPLY                             (0x00000001 << E_BACK_SUPPLY)//备用/支护
#define ANCHOR_RMT_CTRL                         (0x00000001 << E_ANCHOR_RMT_CTRL)//锚杆遥控
#define ANCHOR_SUPPLY                           (0x00000001 << E_ANCHOR_SUPPLY)//锚支

#endif // COMMCANPLUGIN_H
