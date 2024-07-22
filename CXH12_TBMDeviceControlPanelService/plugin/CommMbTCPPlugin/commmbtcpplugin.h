#ifndef COMMMBTCPPLUGIN_H
#define COMMMBTCPPLUGIN_H

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

#define RECEIVE_DATA                            1574724518 //ModbusTCP接收数据
#define MODBUS_TCP_MAX_CLIENT_LENGTH            256
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

#pragma pack(1) //禁止使用内存对齐
typedef struct TFrameRxData
{
    //_system    系统
    uint16_t system_placeHolder_0[40];//空
    uint16_t system_data_valid_flag;//数据有效标识
    uint16_t system_data_counter;//流水号
    char system_car_type[8];//车型
    char system_car_number[8];//车号
    uint16_t system_ctrl_mode;//控制模式
    uint16_t system_auto_manual_cut_status;//自动或手动截割状态
    uint16_t system_system_voltage;//系统电压
    uint16_t system_start_time;//启动时间
    uint16_t system_remote_time;//远控时间
    uint16_t system_auto_cut_time;//自动截割时间
    uint16_t system_placeHolder_56;//空
    uint16_t system_placeHolder_57;//空
    uint16_t system_scram;//急停状态
    uint16_t system_sensor_fault_info;//传感器、漏电、故障信息
    uint16_t system_hydraulic_pressure;//液压压力
    uint16_t system_environment_temp;//环境温度
    uint16_t system_environment_humidity;//环境湿度
    uint16_t system_gas_density;//瓦斯浓度
    uint16_t system_dust_density;//粉尘浓度
    uint16_t system_carbon_density;//CO浓度
    uint16_t system_pumpOilMotor_work_status;//油泵工作状态
    uint16_t system_cut_motor_work_status;//截割电机状态
    uint16_t system_transport_2_motor_work_status;//二运状态
    uint16_t system_fan_motor_work_status;//风机状态
    uint16_t system_lubrication_work_status;//润滑状态
    uint16_t system_waterPump_work_status;//水泵启停状态
    uint16_t system_spray_valve_work_status;//喷雾阀状态
    uint16_t system_transport_1_motor_work_status;//一运状态
    uint16_t system_shoveBlade_work_status;//铲板状态
    uint16_t system_rearSupport_work_status;//后支撑状态
    uint16_t system_cutArm_rotation_status;//截割臂回转状态
    uint16_t system_cutArm_up_down_status;//截割臂升降状态
    uint16_t system_cutArm_push_pull_status;//截割臂伸缩状态
    uint16_t system_left_tract_work_status;//左行走状态
    uint16_t system_right_tract_work_status;//右行走状态
    uint16_t system_star_wheel_motor_work_status;//星轮状态
    uint16_t system_left_star_wheel_motor_work_status;//左星轮状态
    uint16_t system_right_star_wheel_motor_work_status;//右星轮状态
    uint16_t system_placeHolder_84;//空
    uint16_t system_fuel_tank_temp;//油箱温度
    uint16_t system_fuel_tank_oil_level;//油箱油位
    uint16_t system_cool_water_flow_calculate;//冷却水流量
    uint16_t system_cool_water_pressure;//冷却水水压
    uint16_t system_fuselage_angle_X;//机身倾角X
    uint16_t system_fuselage_angle_Y;//机身倾角Y
    uint16_t system_fuselage_angle_Z;//机身倾角Z
    uint16_t system_shoveBlade_angle_X;//铲板X倾角
    uint16_t system_shoveBlade_angle_Y;//铲板Y倾角
    uint16_t system_shoveBlade_offset;//铲板位移
    uint16_t system_cutArm_rotation_offset;//截割臂回转位移
    uint16_t system_cutArm_up_down_offset;//截割臂升降位移
    uint16_t system_cutArm_push_pull_offset;//截割臂伸缩位移
    uint16_t system_rearSupport_offset;//后支撑位移
    uint16_t system_back_car_pressure;//倒车压力
    uint16_t system_rotation_1_pressure;//回转压力1
    uint16_t system_rotation_2_pressure;//回转压力2
    uint16_t system_up_down_1_pressure;//升降压力1
    uint16_t system_up_down_2_pressure;//升降压力2
    uint16_t system_push_pull_1_pressure;//伸缩压力1
    uint16_t system_push_pull_2_pressure;//伸缩压力2
    uint16_t system_placeHolder_106;//空
    uint16_t system_placeHolder_107;//空
    uint16_t system_placeHolder_108;//空
    uint16_t system_placeHolder_109;//空
    uint16_t system_left_forward_laser_distance;//左前激光测距
    uint16_t system_left_backward_laser_distance;//左后激光测距
    uint16_t system_right_forward_laser_distance;//右前激光测距
    uint16_t system_right_backward_laser_distance;//右后激光测距
    uint16_t system_person_detection;//人员检测
    uint16_t system_placeHolder_115;//空
    uint16_t system_placeHolder_116;//空
    uint16_t system_placeHolder_117;//空
    uint16_t system_placeHolder_118;//空
    uint16_t system_placeHolder_119;//空
    uint16_t system_cut_motor_current ;//截割电机电流
    //HighCutMotor  截高电机
    uint16_t highCutMotor_work_status;//工作状态
    uint16_t highCutMotor_current_A;//A电流
    uint16_t highCutMotor_current_B;//B电流
    uint16_t highCutMotor_current_C;//C电流
    uint16_t highCutMotor_current;//电流
    uint16_t highCutMotor_wind_temp;//绕组温度
    uint16_t highCutMotor_AC_contractor_feedback_status;//交流接触器反馈状态
    uint16_t system_placeHolder_128;//空
    //LowCutMotor   截低电机
    uint16_t lowCutMotor_work_status;//工作状态
    uint16_t lowCutMotor_current_A;//A电流
    uint16_t lowCutMotor_current_B;//B电流
    uint16_t lowCutMotor_current_C;//C电流
    uint16_t lowCutMotor_current;//电流
    uint16_t lowCutMotor_wind_temp;//绕组温度
    uint16_t lowCutMotor_AC_contractor_feedback_status;//交流接触器反馈状态
    uint16_t lowCutMotor_placeHolder_136;//空
    //FanMotor 风机
    uint16_t fanMotor_work_status;//工作状态
    uint16_t fanMotor_current_A;//A电流
    uint16_t fanMotor_current_B;//B电流
    uint16_t fanMotor_current_C;//C电流
    uint16_t fanMotor_current;//电流
    uint16_t fanMotor_wind_temp;//绕组温度
    uint16_t fanMotor_AC_contractor_feedback_status;//交流接触器反馈状态
    uint16_t fanMotor_placeHolder_144;//空
    //pumpOilMotor  油泵电机
    uint16_t pumpOilMotor_work_status;//工作状态
    uint16_t pumpOilMotor_current_A;//A电流
    uint16_t pumpOilMotor_current_B;//B电流
    uint16_t pumpOilMotor_current_C;//C电流
    uint16_t pumpOilMotor_current;//电流
    uint16_t pumpOilMotor_wind_temp;//绕组温度
    uint16_t pumpOilMotor_AC_contractor_feedback_status;//交流接触器反馈状态
    uint16_t pumpOilMotor_placeHolder_152;//空

    //transport2Motor   二运
    uint16_t transport_2_Motor_work_status;//工作状态
    uint16_t transport_2_Motor_current_A;//A电流
    uint16_t transport_2_Motor_current_B;//B电流
    uint16_t transport_2_Motor_current_C;//C电流
    uint16_t transport_2_Motor_current;//电流
    uint16_t transport_2_Motor_wind_temp;//绕组温度
    uint16_t transport_2_Motor_AC_contractor_feedback_status;//交流接触器反馈状态
    uint16_t transport_2_Motor_placeHolder_160;//空

    uint16_t placeHolder[95];//结束
}FrameRxData;
#pragma pack()
class  CommMbTCPPlugin : public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.machine.commmbtcpplugin" FILE "CommMbTCPPlugin.json")
    Q_INTERFACES(PluginInterface)
public:
    CommMbTCPPlugin();
    ~CommMbTCPPlugin();

    void run() override;
    QVariant read(const QString &type, quint16 channel) override;
    QVariant write(const QString &type,quint16 channel,const QVariant &value) override;
    QVariant ctrl(const QString &type,const QVariant &value) override;
private:
    int ModbusTCPInit();
    static void* ModbusTCPWriteThread(void *arg);
    static void* modbusTCP_read_thread(void *arg);
    static void* modbusTCP_fixComm_thread(void *arg);
    void RefreshModbusTCPTransmitData(unsigned long long switchCmd,Rock_t& rock,int dataValidFlag);
    void RefreshModbusTCPTransmitBuff();
    void RefreshModbusTCPReceiveBuff();
    void close_sigint(int dummy);

private:
    int server_socket;
    modbus_t *serverCtx;//服务端上下文
    modbus_t *clientCtx;//客户端上下文
    std::string serverIP;//服务端IP地址
    int serverPort;//服务端端口号
    int serverHoldRegistersSize;//服务端寄存器个数
    std::string clientIP;//客户端IP地址
    int clientPort;//客户端端口号
    int clientHoldRegistersSize;//客户端寄存器个数
    modbus_mapping_t *mb_mapping;
    int pollSize;
    FrameTxData frameTxData;
    FrameRxData frameRxData;
    int rc;
    char query[MODBUS_MAX_READ_REGISTERS];
    unsigned short tab_reg[MODBUS_TCP_MAX_CLIENT_LENGTH];
    bool commMbTCPStatus;
    fd_set refset;//文件句柄
    int fdmax;//maximum file desc number;
};

#endif // COMMMBTCPPLUGIN_H
