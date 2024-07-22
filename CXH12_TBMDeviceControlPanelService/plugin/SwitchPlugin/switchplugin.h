#ifndef SWITCHPLUGIN_H
#define SWITCHPLUGIN_H

#include <QQuickView>
#include <QObject>
#include <QtPlugin>
#include "tools/plugininterface/plugininterface.h"


struct GpioInfo {
    int32_t GpioNum;// GPIO pin number
    int32_t GpioValue;
    int32_t GpioStatus;// 1 for output mode
};

#define ZMOS_GPIO_IOC_MAGIC 'm'
#define ZMOS_GPIO_IOC_SET_MODE _IOWR(ZMOS_GPIO_IOC_MAGIC, 0, struct GpioInfo)
#define ZMOS_GPIO_IOC_SET_VALUE _IOWR(ZMOS_GPIO_IOC_MAGIC, 1, struct GpioInfo)
#define ZMOS_GPIO_IOC_GET_VALUE _IOWR(ZMOS_GPIO_IOC_MAGIC, 2, struct GpioInfo)

#define ZMOS_ADC_IOCTL_BASE 'k'
#define ZMOS_RK_ADC_CHANNEL(num) _IOR(ZMOS_ADC_IOCTL_BASE,num,int32_t)
#define ADC_CHANNEL_NUMS 8

#define ZMOS_DAC_IOCTL_BASE 'd'

#define SPRINGBACK          1847272564//回弹型开关量
#define NOT_SPRINGBACK       -1589236352//非回弹型开关量
#define LEFT_RIGHT_ROCK             1490913024//左右型摇杆
#define UP_DOWN_ROCK             -1307023298//上下型摇杆


#define COMM_STATUS_LED       -1302733007      //通讯指示灯
#define ACTION_LED           -1956725662       //动作指示灯
#define SCRAM_LED            -1489887782      //急停指示灯

class  SwitchPlugin : public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.machine.switchplugin" FILE "SwitchPlugin.json")
    Q_INTERFACES(PluginInterface)
public:
    SwitchPlugin();
    ~SwitchPlugin();

    void run() override;
    QVariant read(const QString &type, quint16 channel) override;
    QVariant write(const QString &type,quint16 channel,const QVariant &value) override;
    QVariant ctrl(const QString &type,const QVariant &value) override;
private:
    int32_t GpioInit();
    int32_t AdcInit();
    int32_t DacInit();
private:
    int32_t gpio_fd;//GPIO文件
    int32_t adc_fd;//ADC文件
    int32_t dac_fd;//DAC文件
    struct GpioInfo gpio_for_backKey[64];//64个回弹型按键
    struct GpioInfo gpio_for_notBackKey[64];//64个非回弹型按键
    struct GpioInfo gpio_for_led[8];//8个输出指示灯
    int32_t adc_for_rock[16];//16个摇杆
};
//回弹型按键枚举
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
    //驾驶室操作台
    E_SCRAM,//急停
    E_RMT_CTRL,//遥控
    E_REMOTE_CTRL,//远控
    E_AUTO_CUT,//自动截割
    E_BACK_SUPPLY,//备用/支护
    E_ANCHOR_RMT_CTRL,//锚杆遥控
    E_ANCHOR_SUPPLY,//锚支
    E_NOT_BACK_KEY_END,//结束标识

}E_NOT_BACK_KEY;
typedef enum E_LED
{
    E_KEY_LED,//按键指示灯
    E_COMM_LED,//通信指示灯
    E_SCRAM_LED,//急停指示灯
    E_LED_END,//结束标识
}E_LED;

typedef enum E_GPIO_NUMBER
{
    //驾驶室操作台
    E_GPIO_NUMBER_SCRAM = 63,//急停
    E_GPIO_NUMBER_RMT_CTRL = 203,//遥控
    E_GPIO_NUMBER_REMOTE_CTRL = 103,//远控
    E_GPIO_NUMBER_AUTO_CUT = 109,//自动截割
    E_GPIO_NUMBER_BACK_SUPPLY = 112,//备用/支护
    E_GPIO_NUMBER_ANCHOR_RMT_CTRL = 80,//锚杆遥控
    E_GPIO_NUMBER_ANCHOR_SUPPLY = 69,//锚支


    E_GPIO_NUMBER_RESET = 117,//复位
    E_GPIO_NUMBER_POWER_ON = 64,//开机
    E_GPIO_NUMBER_ALARM_BELL_START = 113,//警铃
    E_GPIO_NUMBER_LUBRICATION = 116,//润滑
    E_GPIO_NUMBER_AUTO_CUT_INTERVENE = 110,//截割干预
    E_GPIO_NUMBER_OIL_PUMP_START = 21,//油泵
    E_GPIO_NUMBER_TRANSPORT_2_FWD = 89,//二运
    E_GPIO_NUMBER_CUT_HIGH_START = 96,//截高
    E_GPIO_NUMBER_CUT_LOW_START = 14,//截低
    E_GPIO_NUMBER_1_FAN = 111,//风机1
    E_GPIO_NUMBER_2_FAN = 98,//风机2
    E_GPIO_NUMBER_PAGE_UP = 106,//上翻页
    E_GPIO_NUMBER_PAGE_DOWN = 105,//下翻页
    E_GPIO_NUMBER_UP = 13,//上
    E_GPIO_NUMBER_DOWN = 150,//下
    E_GPIO_NUMBER_ADD = 82,//加
    E_GPIO_NUMBER_SUBTRAC = 81,//减
    E_GPIO_NUMBER_CONFIRM = 86,//确认
    E_GPIO_NUMBER_GO_BACK = 85,//返回

}E_GPIO_NUMBER;
#endif // SWITCHPLUGIN_H
