#include "switchplugin.h"
#include "tools/HashString/HashString.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include <qmetatype.h>

SwitchPlugin::SwitchPlugin()
{
    gpio_fd = -1;
    adc_fd = -1;
    dac_fd = -1;
    memset(gpio_for_backKey,0,sizeof(gpio_for_backKey));
    memset(gpio_for_notBackKey,0,sizeof(gpio_for_notBackKey));
    memset(gpio_for_led,0,sizeof(gpio_for_led));
    memset(adc_for_rock,0,sizeof(adc_for_rock));

}
SwitchPlugin::~SwitchPlugin()
{
    if(gpio_fd)
        close(gpio_fd);
    if(adc_fd)
        close(adc_fd);
    if(dac_fd)
        close(dac_fd);
}
int32_t SwitchPlugin::GpioInit()
{
    //1、打开文件
    gpio_fd = open("/dev/zmos/gpio_magic",O_RDWR);
    if (gpio_fd < 0)
    {
        perror("Failed to open GPIO device");
        return -1;
    }
    //2、GPIO口设定为输入模式
    //自锁定开关
    gpio_for_notBackKey[E_SCRAM].GpioNum = E_GPIO_NUMBER_SCRAM;//急停
    gpio_for_notBackKey[E_RMT_CTRL].GpioNum = E_GPIO_NUMBER_RMT_CTRL;//遥控
    gpio_for_notBackKey[E_REMOTE_CTRL].GpioNum = E_GPIO_NUMBER_REMOTE_CTRL;//远控
    gpio_for_notBackKey[E_AUTO_CUT].GpioNum = E_GPIO_NUMBER_AUTO_CUT;//自动截割
    gpio_for_notBackKey[E_BACK_SUPPLY].GpioNum = E_GPIO_NUMBER_BACK_SUPPLY;//备用/支护
    gpio_for_notBackKey[E_ANCHOR_RMT_CTRL].GpioNum = E_GPIO_NUMBER_ANCHOR_RMT_CTRL;//锚杆遥控
    gpio_for_notBackKey[E_ANCHOR_SUPPLY].GpioNum = E_GPIO_NUMBER_ANCHOR_SUPPLY;//锚支


    //自复位开关
    gpio_for_backKey[E_RESET].GpioNum = E_GPIO_NUMBER_RESET;//复位
    gpio_for_backKey[E_POWER_ON].GpioNum = E_GPIO_NUMBER_POWER_ON;//开机
    gpio_for_backKey[E_ALARM_BELL_START].GpioNum = E_GPIO_NUMBER_ALARM_BELL_START;//警铃
    gpio_for_backKey[E_LUBRICATION].GpioNum = E_GPIO_NUMBER_LUBRICATION;//润滑
    gpio_for_backKey[E_AUTO_CUT_INTERVENE].GpioNum = E_GPIO_NUMBER_AUTO_CUT_INTERVENE;//截割干预
    gpio_for_backKey[E_OIL_PUMP_START].GpioNum = E_GPIO_NUMBER_OIL_PUMP_START;//油泵
    gpio_for_backKey[E_TRANSPORT_2_FWD].GpioNum = E_GPIO_NUMBER_TRANSPORT_2_FWD;//二运
    gpio_for_backKey[E_CUT_HIGH_START].GpioNum = E_GPIO_NUMBER_CUT_HIGH_START;//截高
    gpio_for_backKey[E_CUT_LOW_START].GpioNum = E_GPIO_NUMBER_CUT_LOW_START;//截低
    gpio_for_backKey[E_1_FAN].GpioNum = E_GPIO_NUMBER_1_FAN;//风机1
    gpio_for_backKey[E_2_FAN].GpioNum = E_GPIO_NUMBER_2_FAN;//风机2
    gpio_for_backKey[E_PAGE_UP].GpioNum = E_GPIO_NUMBER_PAGE_UP;//上翻页
    gpio_for_backKey[E_PAGE_DOWN].GpioNum = E_GPIO_NUMBER_PAGE_DOWN;//下翻页
    gpio_for_backKey[E_UP].GpioNum = E_GPIO_NUMBER_UP;//上
    gpio_for_backKey[E_DOWN].GpioNum = E_GPIO_NUMBER_DOWN;//下
    gpio_for_backKey[E_ADD].GpioNum = E_GPIO_NUMBER_ADD;//加
    gpio_for_backKey[E_SUBTRAC].GpioNum = E_GPIO_NUMBER_SUBTRAC;//减
    gpio_for_backKey[E_CONFIRM].GpioNum = E_GPIO_NUMBER_CONFIRM;//确认
    gpio_for_backKey[E_GO_BACK].GpioNum = E_GPIO_NUMBER_GO_BACK;//返回

    return 0;
}
int SwitchPlugin::AdcInit()
{
    adc_fd = open("/dev/zmos/adc",O_RDWR);
    if(adc_fd < 0)
    {
        perror("Failed to open ADC device");
        return -1;
    }
    return 0;
}
int32_t SwitchPlugin::DacInit()
{
    dac_fd = open("/dev/zmos/dac",O_RDWR);
    if(dac_fd < 0)
    {
        perror("Failed to open DAC device");
        return -1;
    }
    return 0;
}
void SwitchPlugin::run()
{
//    if((GpioInit() == -1) || (AdcInit() == -1) || (DacInit() == -1))
//        qDebug() << "GPIO || ADC || DAC 初始化失败";
//    if((GpioInit() == -1) || (AdcInit() == -1))
//        qDebug() << "GPIO || ADC 初始化失败";
    if(GpioInit() == -1)
        qDebug() << "GPIO 初始化失败";
}
QVariant SwitchPlugin::read(const QString &type, quint16 channel)
{
    int32_t getValueTemp = 0xFFFFFFFF;
    int32_t typeTemp = hashString(type.toStdString());
    uint16_t channelTemp = channel;
    switch(typeTemp)
    {
    case SPRINGBACK:
        if(channelTemp >= E_BACK_KEY_END)
            break;
        ioctl(gpio_fd,ZMOS_GPIO_IOC_GET_VALUE,&gpio_for_backKey[channelTemp]);
        getValueTemp = gpio_for_backKey[channelTemp].GpioValue;
        break;
    case NOT_SPRINGBACK:
        if(channelTemp >= E_NOT_BACK_KEY_END)
            break;
        ioctl(gpio_fd,ZMOS_GPIO_IOC_GET_VALUE,&gpio_for_notBackKey[channelTemp]);
        getValueTemp = gpio_for_notBackKey[channelTemp].GpioValue;

        break;
    case LEFT_RIGHT_ROCK:
        ioctl(adc_fd,ZMOS_RK_ADC_CHANNEL(channelTemp),&adc_for_rock[channelTemp]);
        getValueTemp = adc_for_rock[channelTemp];
        break;
    case UP_DOWN_ROCK:
        ioctl(adc_fd,ZMOS_RK_ADC_CHANNEL(channelTemp),&adc_for_rock[channelTemp]);
        getValueTemp = adc_for_rock[channelTemp];
        break;
    case COMM_STATUS_LED:
        ioctl(gpio_fd,ZMOS_GPIO_IOC_GET_VALUE,&gpio_for_led[E_COMM_LED]);
        getValueTemp = gpio_for_led[E_COMM_LED].GpioValue;
        break;
    case ACTION_LED:
        ioctl(gpio_fd,ZMOS_GPIO_IOC_GET_VALUE,&gpio_for_led[E_KEY_LED]);
        getValueTemp = gpio_for_led[E_KEY_LED].GpioValue;
        break;
    case SCRAM_LED:
        ioctl(gpio_fd,ZMOS_GPIO_IOC_GET_VALUE,&gpio_for_led[E_SCRAM_LED]);
        getValueTemp = gpio_for_led[E_SCRAM_LED].GpioValue;
        break;
    default:
        break;
    }
    QVariant var = QVariant(getValueTemp);
    return var;
}
QVariant SwitchPlugin::write(const QString &type,quint16 channel,const QVariant &value)
{
    int32_t setValueTemp = value.toInt();
    int32_t typeTemp = hashString(type.toStdString());
    int32_t ret = -1;
    switch(typeTemp)
    {
    case COMM_STATUS_LED:
        gpio_for_led[E_COMM_LED].GpioValue = setValueTemp;
        ret = ioctl(gpio_fd,ZMOS_GPIO_IOC_SET_VALUE,&gpio_for_led[E_COMM_LED]);
        break;
    case ACTION_LED:
        gpio_for_led[E_KEY_LED].GpioValue = setValueTemp;
        ret = ioctl(gpio_fd,ZMOS_GPIO_IOC_SET_VALUE,&gpio_for_led[E_KEY_LED]);
        break;
    case SCRAM_LED:
        gpio_for_led[E_SCRAM_LED].GpioValue = setValueTemp;
        ret = ioctl(gpio_fd,ZMOS_GPIO_IOC_SET_VALUE,&gpio_for_led[E_SCRAM_LED]);
        break;
    default:
        break;
    }
    QVariant var = QVariant(ret);
    return var;
}
QVariant SwitchPlugin::ctrl(const QString &type,const QVariant &value)
{
    qDebug() << "SwitchPlugin::ctrl(const QString &type,const QVariant &value) is called";
    return 0;
}
