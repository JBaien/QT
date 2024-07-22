#ifndef COMMMBRTUPLUGIN_H
#define COMMMBRTUPLUGIN_H

#include <QQuickView>
#include <QObject>
#include <QtPlugin>
#include "tools/plugininterface/plugininterface.h"
#include "libmodbus/include/modbus/modbus.h"
typedef struct Rock_t
{
    uint16_t LeftTrack;
    uint16_t RightTrack;
    uint16_t CutLeftRight;
    uint16_t CutUpDown;
}Rock_t;
//回弹型按键枚举(需和SwitchPlugin保持一致)
typedef enum E_BACK_KEY
{
    //掘进机操作台
    E_FULL_SCREEN_SWITCH,//全屏切换
    E_PICTURE_SWITCH,//画面切换
    E_POWER_ON,//开机
    E_RESET,//复位
    E_ALARM_BELL_START,//警铃
    E_AUTO_CUT_INTERVENE,//自动截割干预
    E_ONE_KEY_START_STOP,//一键启停
    E_OIL_PUMP_START,//油泵
    E_TRANSPORT_2_FWD,//二运
    E_CUT_HIGH_START,//截高
    E_CUT_LOW_START,//截低
    E_FAN_START,//风机
    E_SPADEBLADE_UP,//铲板升
    E_SPADEBLADE_DOWN,//铲板降
    E_BACK_SUPPORT_UP,//后支撑升
    E_BACK_SUPPORT_DOWN,//后支撑降
    E_CUT_UP,//截割伸
    E_CUT_DOWN,//截割缩
    E_SPARE_1,//备用1
    E_SPARE_2,//备用2
    E_SPARE_3,//备用3
    E_SPARE_4,//备用4
    E_BACK_KEY_END,//结束标识

}E_BACK_KEY;
//自锁定开关
typedef enum E_NOT_BACK_KEY
{
    //掘进机操作台
    E_SCRAM,//急停
    E_AUTO_CUT,//自动截割，3档自锁定
    E_STAR_WHEEL_FWD,//星轮正转，3档自锁定
    E_STAR_WHEEL_REV,//星轮反转，3档自锁定
    E_TRANSPORT_1_FWD,//一运正转，3档自锁定
    E_TRANSPORT_1_REV,//一运反转，3档自锁定
    E_LOACAL_SWITCH,//地面切换，2档自锁定
    E_WATER_PUMP_START,//水泵启动，2档自锁定
    E_NOT_BACK_KEY_END,//结束标识
}E_NOT_BACK_KEY;
//定义8Byte指令值
//掘进机操作台
//回弹型开关
#define FULLSCREENSWITCH        (0x00000001 << E_FULL_SCREEN_SWITCH)//全屏切换
#define PICTURESWITCH           (0x00000001 << E_PICTURE_SWITCH)//画面切换
#define POWERON                 (0x00000001 << E_POWER_ON)//开机
#define RESET                   (0x00000001 << E_RESET)//复位
#define ALARMBELLSTART          (0x00000001 << E_ALARM_BELL_START)//警铃启动
#define AUTOCUTINTERVENE        (0x00000001 << E_AUTO_CUT_INTERVENE)//自动截割干预
#define ONEKEYSTARTSTOP         (0x00000001 << E_ONE_KEY_START_STOP)//一键启停
#define OILPUMPSTART            (0x00000001 << E_OIL_PUMP_START)//油泵启动
#define TRANSPORT2FWD           (0x00000001 << E_TRANSPORT_2_FWD)//二运正转
#define CUTHIGHSTART            (0x00000001 << E_CUT_HIGH_START)//截高启动
#define CUTLOWSTART             (0x00000001 << E_CUT_LOW_START)//截低启动
#define FANSTART                (0x00000001 << E_FAN_START)//风机启动
#define SPADEBLADEUP            (0x00000001 << E_SPADEBLADE_UP)//铲板升
#define SPADEBLADEDOWN          (0x00000001 << E_SPADEBLADE_DOWN)//铲板降
#define BACKSUPPORTUP           (0x00000001 << E_BACK_SUPPORT_UP)//后支撑升
#define BACKSUPPORTDOWN         (0x00000001 << E_BACK_SUPPORT_DOWN)//后支撑降
#define CUTUP                   (0x00000001 << E_CUT_UP)//截割伸
#define CUTDOWN                 (0x00000001 << E_CUT_DOWN)//截割缩
#define SPARE1                  (0x00000001 << E_SPARE_1)//备用1
#define SPARE2                  (0x00000001 << E_SPARE_2)//备用2
#define SPARE3                  (0x00000001 << E_SPARE_3)//备用3
#define SPARE4                  (0x00000001 << E_SPARE_4)//备用4



//非回弹型开关
#define SCRAM               (0x00000001 << E_SCRAM)//急停
#define AUTOCUT             (0x00000001 << E_AUTO_CUT)//自动截割，3档自锁定
#define STARWHEELFWD        (0x00000001 << E_STAR_WHEEL_FWD)//星轮正转，3档自锁定
#define STARWHEELREV        (0x00000001 << E_STAR_WHEEL_REV)//星轮反转，3档自锁定
#define TRANSPORT1FWD       (0x00000001 << E_TRANSPORT_1_FWD)//一运正转，3档自锁定
#define TRANSPORT1REV       (0x00000001 << E_TRANSPORT_1_REV)//一运反转，3档自锁定
#define LOCALSWITCH         (0x00000001 << E_LOACAL_SWITCH)//地面切换，2档自锁定
#define WATERPUMPSTART      (0x00000001 << E_WATER_PUMP_START)//水泵启动，2档自锁定
typedef struct TFrameTxData
{
    //掘进机操作台
    //TPDO:0x180+ID
    struct TFrame0
    {
        struct TWord0
        {
            //char[0]
            unsigned short int dummyDatas0_0 : 1;//无效数据
            unsigned short int scram : 1;//急停
            unsigned short int : 1;//无效数据//unsigned short int dummyDatas0_2 : 1;//无效数据
            unsigned short int : 1;//无效数据//unsigned short int dummyDatas0_3 : 1;//无效数据
            unsigned short int heartBead : 1;//心跳
            unsigned short int : 3;//无效数据

            //char[1]
            unsigned short int pictureSwitch : 1;//画面切换
            unsigned short int dummyDatas1_1 : 1;//空
            unsigned short int fullScreenSwitch : 1;//全屏切换
            unsigned short int dummyDatas1_3 : 1;//空
            unsigned short int dummyDatas1_4 : 1;//空
            unsigned short int dummyDatas1_5 : 1;//空
            unsigned short int dummyDatas1_6 : 1;//空
            unsigned short int dummyDatas1_7 : 1;//空

        }Word0;
        struct TWord1
        {
            //char[2]
            unsigned short int oilPumpStart : 1;//油泵启动
            unsigned short int oilPumpStop : 1;//油泵停机
            unsigned short int cutLowStart : 1;//截低启动
            unsigned short int cutLowStop : 1;//截低停
            unsigned short int cutHighStart : 1;//截高启动
            unsigned short int cutHighStop : 1;//截高停机
            unsigned short int transport2FWD : 1;//二运正转
            unsigned short int transport2REV : 1;//二运反转

            //char[3]
            unsigned short int fanStart : 1;//风机启动
            unsigned short int fanStop : 1;//风机停止
            unsigned short int waterPump : 1;//水泵
            unsigned short int dummyDatas3_3 : 1;//空
            unsigned short int alarmBellStart : 1;//警铃
            unsigned short int dummyDatas3_5 : 1;//空
            unsigned short int powerOn : 1;//开机
            unsigned short int reset : 1;//复位
        }Word1;
        struct TWord2
        {
            //char[4]
            unsigned short int autoCut : 1;//自动截割
            unsigned short int dummyDatas4_1 : 1;//空
            unsigned short int starWheelFWD : 1;//星轮正转
            unsigned short int starWheelREV : 1;//星轮反转
            unsigned short int transport1FWD : 1;//1运正转
            unsigned short int transport1REV : 1;//1运反转
            unsigned short int localSwitch : 1;//地面切换
            unsigned short int dummyDatas4_7 : 1;//空

            //char[5]
            unsigned short int spadeBladeUp : 1;//铲板升
            unsigned short int spadeBladeDown : 1;//铲板降
            unsigned short int backSupportUp : 1;//后支撑升
            unsigned short int backSupportDown : 1;//后支撑降
            unsigned short int cutUp : 1;//截割伸
            unsigned short int cutDown : 1;//截割缩
            unsigned short int autoCutIntervene : 1;//自动截割干预
            unsigned short int oneKeyStartStop : 1;//一键启停
        }Word2;
        struct TWord3
        {
            //char[6]
            unsigned short int spare1 : 1;//备用1
            unsigned short int spare2 : 1;//备用2
            unsigned short int spare3 : 1;//备用3
            unsigned short int spare4 : 1;//备用4
            unsigned short int dummyDatas6_4 : 1;//空
            unsigned short int dummyDatas6_5 : 1;//空
            unsigned short int dummyDatas6_6 : 1;//空
            unsigned short int dummyDatas6_7 : 1;//空

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
        struct TWord0
        {
            signed short int word0;
        }Word0;
        struct TWord1
        {
            signed short int word1;
        }Word1;
        struct TWord2
        {
            signed short int word2;
        }Word2;
        struct TWord3
        {
            signed short int word3;
        }Word3;
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
class  CommMbRTUPlugin : public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.machine.commmbrtuplugin" FILE "CommMbRTUPlugin.json")
    Q_INTERFACES(PluginInterface)
public:
    CommMbRTUPlugin();
    ~CommMbRTUPlugin();

    void run() override;
    QVariant read(const QString &type, quint16 channel) override;
    QVariant write(const QString &type,quint16 channel,const QVariant &value) override;
    QVariant ctrl(const QString &type,const QVariant &value) override;
private:
    int open_port();
    int modbusRTU_init();
    int set_opt(int fd,int nSpeed,int nBits,char nEvent,int nStop);
    static void* modbusRTU_write_thread(void *arg);
    void refresh_modbusRTU_transmitData(unsigned long long switchCmd,Rock_t& rock);
    void refresh_modbusRTU_transmitBuff();
    void refresh_modbusRTU_ReceiveBuff();
    static void* modbusRTU_read_thread(void *arg);
private:
    int mbRTU_fd;
    std::string slaveName;
    int bitRate;
    int dataBits;
    char dataEvent;
    int dataStop;
    modbus_t *ctx;
    int slaveID;
    modbus_mapping_t *mb_mapping;
    int holdRegistersSize;
    FrameTxData frameTxData;
    FrameRxData frameRxData;
    int rc;
    char query[64];
    bool commMbRTUStatus;
    int counter;
};

#endif // COMMMBRTUPLUGIN_H
