#ifndef CONTROLPANELPLUGIN_H
#define CONTROLPANELPLUGIN_H

#include <QQuickView>
#include <QObject>
#include <QtPlugin>
#include "tools/plugininterface/plugininterface.h"
#include "tools/pluginmanager/pluginlist.h"

#include <pthread.h>
//摇杆结构体
typedef struct Rock_t
{
    uint32_t LeftTrack;
    uint32_t RightTrack;
    uint32_t CutLeftRight;
    uint32_t CutUpDown;
}Rock_t;
class  ControlPanelPlugin : public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.machine.controlpanelplugin" FILE "ControlPanelPlugin.json")
    Q_INTERFACES(PluginInterface)
public:
    ControlPanelPlugin();
    ~ControlPanelPlugin();

    void run() override;
    QVariant read(const QString &type, quint16 channel) override;
    QVariant write(const QString &type,quint16 channel,const QVariant &value) override;
    QVariant ctrl(const QString &type,const QVariant &value) override;
private:
    static void* ControlPanelThread(void* arg);
    static uint8_t CmdResolve(const uint64_t& switchCmd,const Rock_t& rock);
    static uint8_t RockCalibration(const int& originalValue,int minValue,int midMinValue,int midMaxValue,int maxValue,uint8_t type);
    static bool DataValidityDetection(const uint64_t& switchCmd);
private:
    std::string system_string_time;//字符串系统时间
    uint64_t system_int_time;//整型系统时间
    std::string system_version;
    int32_t system_status_ID;
    int32_t system_comm_status;
    std::string system_error_message;
    int32_t system_error_ID;
    uint64_t back_key;//回弹按键
    uint64_t not_back_key;//非回弹按键
    uint64_t key;//所有按键
    uint8_t key_command;//按键指令
    Rock_t rock_original_value;//摇杆原始值
    Rock_t rock_calibration_value;//摇杆校准值
    bool key_value_valid_falg;//键值有效性标识
};

//掘进机操作台指令
typedef enum E_CMD
{
    //cmd[0]
    E_CMD_NONE,//无动作
    E_CMD_SCRAM,//急停
    E_CMD_ALARM_BELL_START,//警铃启动
    E_CMD_AUTO_CUT_INTERVENE,//自动截割干预
    E_CMD_TRANSPORT_2_FWD,//二运正转
    E_CMD_TRANSPORT_2_REV,//二运反转
    E_CMD_CUT_HIGH_START,//截高启动
    E_CMD_CUT_HIGH_STOP,//截高停机

    //cmd[1]
    E_CMD_PICTURE_SWITCH,//画面切换
    E_CMD_FULL_SCREEN_SITCH,//全屏切换
    E_CMD_POWER_1_CLOSED,//动力回路1闭合
    E_CMD_POWER_1_BREAK,//动力回路1分开
    E_CMD_POWER_2_CLOSED,//动力回路2闭合
    E_CMD_POWER_2_BREAK,//动力回路2分开
    E_CMD_CUT_LOW_START,//截低启动
    E_CMD_CUT_LOW_STOP,//截低停机

    //cmd[2]
    E_CMD_POWER_3_CLOSED,//动力回路3闭合
    E_CMD_POWER_3_BREAK,//动力回路3分开
    E_CMD_DUST_REMOVAL_FAN_IN_WATER,//除尘风机进水
    E_CMD_DUST_REMOVAL_FAN_START,//除尘风机启动
    E_CMD_DUST_REMOVAL_FAN_STOP,//除尘风机停止
    E_CMD_AIR_SUPPLY_FAN_START,//送风风机启动
    E_CMD_AIR_SUPPLY_FAN_STOP,//送风风机停止
    E_CMD_AUTO_CUT,//自动截割

    //cmd[3]
    E_CMD_ONEKEY_START_TOP,//一键启停
    E_CMD_SYSTEM_RESET,//系统复位
    E_CMD_POWER_ON,//开机
    E_CMD_SPADEBLADE_UP,//铲板升
    E_CMD_SPADEBLADE_DOWN,//铲板降
    E_CMD_BACK_SUPPORT_UP,//后支撑升
    E_CMD_BACK_SUPPORT_DOWN,//后支撑降
    E_CMD_FAN_START,//风机

    //cmd[4]
    E_CMD_BELT_1_FWD,//1号皮带正转
    E_CMD_BELT_1_REV,//1号皮带反转
    E_CMD_BELT_2_FWD,//2号皮带正转
    E_CMD_BELT_2_REV,//2号皮带反转
    E_CMD_BELT_3_FWD,//3号皮带正转
    E_CMD_BELT_3_REV,//3号皮带反转
    E_CMD_FWD,//正转
    E_CMD_REV,//反转

    //cmd[5]
    E_CMD_LOCAL_SWITCH,//地面切换
    E_CMD_PUMP_START,//泵启动
    E_CMD_PUMP_STOP,//泵停机
    E_CMD_RESET,//复位
    E_CMD_OIL_PUMP_START,//油泵启动
    E_CMD_OIL_PUMP_STOP,//油泵停机
    E_CMD_STAR_WHEEL_FWD,//星轮正转
    E_CMD_STAR_WHEEL_REV,//星轮反转


    //cmd[6]
    E_CMD_AUTO_FORWARD,//自动前进
    E_CMD_AUTO_BACKWARD,//自动后退
    E_CMD_PUSHER_PUSH,//推移伸
    E_CMD_PUSHER_PULL,//推移收
    E_CMD_LEFT_SUPPORT_PUSH,//左支撑伸
    E_CMD_LEFT_SUPPORT_PULL,//左支撑收
    E_CMD_RIGHT_SUPPORT_PUSH,//右支撑伸
    E_CMD_RIGHT_SUPPORT_PULL,//右支撑收

    //cmd[7]
    E_CMD_SIDE_1_PUSH,//侧移1伸
    E_CMD_SIDE_1_PULL,//侧移1收
    E_CMD_SIDE_2_PUSH,//侧移2伸
    E_CMD_SIDE_2_PULL,//侧移2收
    E_CMD_SIDE_3_PUSH,//侧移3伸
    E_CMD_SIDE_3_PULL,//侧移3收
    E_CMD_CUT_UP,//截割升
    E_CMD_CUT_DOWN,//截割降

    //cmd[8]
    E_CMD_SPARE_1,//备用1
    E_CMD_SPARE_2,//备用2
    E_CMD_SPARE_3,//备用3
    E_CMD_SPARE_4,//备用4
    E_CMD_TRANSPORT_1_FWD,//一运正转
    E_CMD_TRANSPORT_1_REV,//一运反转
    E_CMD_WATER_PUMP_START,//水泵启动
    E_CMD_WATER_PUMP_STOP,//水泵停机

    //cmd[9]
    E_CMD_LEFT_TRACT_UP,//左履带前进
    E_CMD_LEFT_TRACT_DOWN,//左履带后退
    E_CMD_RIGHT_TRACT_UP,//右履带前进
    E_CMD_RIGHT_TRACT_DOWN,//右履带后退
    E_CMD_CUT_HEAD_UP,//截割升
    E_CMD_CUT_HEAD_DOWN,//截割降
    E_CMD_CUT_HEAD_LEFT,//截割左
    E_CMD_CUT_HEAD_RIGHT,//截割右

    //cmd[10]
    E_CMD_SPARE_5,//备用5
    E_CMD_SPARE_6,//备用6
    E_CMD_SPARE_7,//备用7
    E_CMD_SPARE_8,//备用8
    E_CMD_RMT_CTRL,//遥控
    E_CMD_REMOTE_CTRL,//远控
    E_CMD_BACK_SUPPLY,//备用/支护
    E_CMD_LUBRICATION,//润滑


    //cmd[11]
    E_CMD_ANCHOR_RMT_CTRL,//锚杆遥控
    E_CMD_ANCHOR_SUPPLY,//锚支
    E_CMD_1_FAN,//1号风机
    E_CMD_2_FAN,//2号风机
    E_CMD_PAGE_UP,//上翻页
    E_CMD_PAGE_DOWN,//下翻页
    E_CMD_UP,//上
    E_CMD_DOWN,//下


    //cmd[12]
    E_CMD_ADD,//加
    E_CMD_SUBTRAC,//减
    E_CMD_CONFIRM,//确认
    E_CMD_GO_BACK,//返回

    E_CMD_INVALID = 0XFF,//无效指令
}Ecmd;
//摇杆通道定义
#define LEFTT_RACK_CHANNEL 4     //左履带进退
#define RIGHT_TRACK_CHANNEL 5    //右履带进退
#define CUT_UP_DOWN_CHANNEL 8     //截割头上下
#define CUT_LEFT_RIGHT_CHANNEL 9  //截割头左右

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
//自锁定开关(需和SwitchPlugin保持一致)
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



#define VERSION                             1069590712      //系统版本
#define SYS_STATUS                          -1586720316       //系统状态
#define SYS_COMM                            -1526152866   //  系统通信状态
#define ERR_MESSAGE                         -816043283      //错误信息
#define ERR_ID                              2053676629      //错误代码
#define SPRINT_BACK_KEY                     -2023490708       //回弹型开关指令
#define NOT_SPRING_BACK_KEY                 -1619657907       //非回弹型开关指令
#define ALL_KEY                             -192895359        //所有按键
#define KEY_CMD                             -96198886              //按键指令
#define LEFT_TRAVAL                         -508358186              //左履带
#define RIGHT_TRAVAL                        -1425558975       //右履带
#define CUT_LEFT_RIGHT_VLAUE                450852957       //左右截割头
#define CUT_UP_DOWN_VALUE                   -531154885       //上下截割头
#define KEY_VALID_FLAG                      2128431087      //数据有效性
#define SYS_INT_DATE                        -849531024     //系统日期
#define SYS_STR_DATE                        371499630     //系统日期

#endif // CONTROLPANELPLUGIN_H
