#ifndef UI_H
#define UI_H
#include "tools/pluginmanager/pluginmanager.h"
#include "tools/plugininterface/plugininterface.h"
#include <QObject>
//需要和ModbusTCP保持一致
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
    uint16_t highCutMotor_placeHolder_128;//空
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

typedef struct TUiData
{
    //_system    系统
    uint16_t uiData_system_placeHolder_0[40];//空
    int uiData_system_data_valid_flag;//数据有效标识
    int uiData_system_data_counter;//流水号
    char uiData_system_car_type[8];//车型
    char uiData_system_car_number[8];//车号
    int uiData_system_ctrl_mode;//控制模式
    int uiData_system_auto_manual_cut_status;//自动或手动截割状态
    float uiData_system_system_voltage;//系统电压
    float uiData_system_start_time;//启动时间
    float uiData_system_remote_time;//远控时间
    float uiData_system_auto_cut_time;//自动截割时间
    uint16_t uiData_system_placeHolder_56;//空
    uint16_t uiData_system_placeHolder_57;//空
    int uiData_system_scram;//急停状态
    int uiData_system_sensor_fault_info;//传感器、漏电、故障信息
    float uiData_system_hydraulic_pressure;//液压压力
    float uiData_system_environment_temp;//环境温度
    float uiData_system_environment_humidity;//环境湿度
    float uiData_system_gas_density;//瓦斯浓度
    float uiData_system_dust_density;//粉尘浓度
    float uiData_system_carbon_density;//CO浓度
    int uiData_system_pumpOilMotor_work_status;//油泵工作状态
    int uiData_system_cut_motor_work_status;//截割电机状态
    int uiData_system_transport_2_motor_work_status;//二运状态
    int uiData_system_fan_motor_work_status;//风机状态
    int uiData_system_lubrication_work_status;//润滑状态
    int uiData_system_waterPump_work_status;//水泵启停状态
    int uiData_system_spray_valve_work_status;//喷雾阀状态
    int uiData_system_transport_1_motor_work_status;//一运状态
    int uiData_system_shoveBlade_work_status;//铲板状态
    int uiData_system_rearSupport_work_status;//后支撑状态
    int uiData_system_cutArm_rotation_status;//截割臂回转状态
    int uiData_system_cutArm_up_down_status;//截割臂升降状态
    int uiData_system_cutArm_push_pull_status;//截割臂伸缩状态
    int uiData_system_left_tract_work_status;//左行走状态
    int uiData_system_right_tract_work_status;//右行走状态
    int uiData_system_star_wheel_motor_work_status;//星轮状态
    int uiData_system_left_star_wheel_motor_work_status;//左星轮状态
    int uiData_system_right_star_wheel_motor_work_status;//右星轮状态
    uint16_t uiData_system_placeHolder_84;//空
    float uiData_system_fuel_tank_temp;//油箱温度
    float uiData_system_fuel_tank_oil_level;//油箱油位
    float uiData_system_cool_water_flow_calculate;//冷却水流量
    float uiData_system_cool_water_pressure;//冷却水水压
    float uiData_system_fuselage_angle_X;//机身倾角X
    float uiData_system_fuselage_angle_Y;//机身倾角Y
    float uiData_system_fuselage_angle_Z;//机身倾角Z
    float uiData_system_shoveBlade_angle_X;//铲板X倾角
    float uiData_system_shoveBlade_angle_Y;//铲板Y倾角
    float uiData_system_shoveBlade_offset;//铲板位移
    float uiData_system_cutArm_rotation_offset;//截割臂回转位移
    float uiData_system_cutArm_up_down_offset;//截割臂升降位移
    float uiData_system_cutArm_push_pull_offset;//截割臂伸缩位移
    float uiData_system_rearSupport_offset;//后支撑位移
    float uiData_system_back_car_pressure;//倒车压力
    float uiData_system_rotation_1_pressure;//回转压力1
    float uiData_system_rotation_2_pressure;//回转压力2
    float uiData_system_up_down_1_pressure;//升降压力1
    float uiData_system_up_down_2_pressure;//升降压力2
    float uiData_system_push_pull_1_pressure;//伸缩压力1
    float uiData_system_push_pull_2_pressure;//伸缩压力2
    uint16_t uiData_system_placeHolder_106;//空
    uint16_t uiData_system_placeHolder_107;//空
    uint16_t uiData_system_placeHolder_108;//空
    uint16_t uiData_system_placeHolder_109;//空
    float uiData_system_left_forward_laser_distance;//左前激光测距
    float uiData_system_left_backward_laser_distance;//左后激光测距
    float uiData_system_right_forward_laser_distance;//右前激光测距
    float uiData_system_right_backward_laser_distance;//右后激光测距
    int uiData_system_person_detection;//人员检测
    uint16_t uiData_system_placeHolder_115;//空
    uint16_t uiData_system_placeHolder_116;//空
    uint16_t uiData_system_placeHolder_117;//空
    uint16_t uiData_system_placeHolder_118;//空
    uint16_t uiData_system_placeHolder_119;//空
    float uiData_system_cut_motor_current ;//截割电机电流
    //HighCutMotor  截高电机
    int uiData_highCutMotor_work_status;//工作状态
    float uiData_highCutMotor_current_A;//A电流
    float uiData_highCutMotor_current_B;//B电流
    float uiData_highCutMotor_current_C;//C电流
    float uiData_highCutMotor_current;//电流
    float uiData_highCutMotor_wind_temp;//绕组温度
    int uiData_highCutMotor_AC_contractor_feedback_status;//交流接触器反馈状态
    uint16_t uiData_highCutMotor_placeHolder_128;//空
    //LowCutMotor   截低电机
    int uiData_lowCutMotor_work_status;//工作状态
    float uiData_lowCutMotor_current_A;//A电流
    float uiData_lowCutMotor_current_B;//B电流
    float uiData_lowCutMotor_current_C;//C电流
    float uiData_lowCutMotor_current;//电流
    float uiData_lowCutMotor_wind_temp;//绕组温度
    int uiData_lowCutMotor_AC_contractor_feedback_status;//交流接触器反馈状态
    uint16_t uiData_lowCutMotor_placeHolder_136;//空
    //FanMotor 风机
    int uiData_fanMotor_work_status;//工作状态
    float uiData_fanMotor_current_A;//A电流
    float uiData_fanMotor_current_B;//B电流
    float uiData_fanMotor_current_C;//C电流
    float uiData_fanMotor_current;//电流
    float uiData_fanMotor_wind_temp;//绕组温度
    int uiData_fanMotor_AC_contractor_feedback_status;//交流接触器反馈状态
    uint16_t uiData_fanMotor_placeHolder_144;//空
    //pumpOilMotor  油泵电机
    int uiData_pumpOilMotor_work_status;//工作状态
    float uiData_pumpOilMotor_current_A;//A电流
    float uiData_pumpOilMotor_current_B;//B电流
    float uiData_pumpOilMotor_current_C;//C电流
    float uiData_pumpOilMotor_current;//电流
    float uiData_pumpOilMotor_wind_temp;//绕组温度
    int uiData_pumpOilMotor_AC_contractor_feedback_status;//交流接触器反馈状态
    uint16_t uiData_pumpOilMotor_placeHolder_152;//空

    //transport2Motor   二运
    int uiData_transport_2_Motor_work_status;//工作状态
    float uiData_transport_2_Motor_current_A;//A电流
    float uiData_transport_2_Motor_current_B;//B电流
    float uiData_transport_2_Motor_current_C;//C电流
    float uiData_transport_2_Motor_current;//电流
    float uiData_transport_2_Motor_wind_temp;//绕组温度
    int uiData_transport_2_Motor_AC_contractor_feedback_status;//交流接触器反馈状态
    uint16_t uiData_transport_2_Motor_placeHolder_160;//空

    uint16_t uiData_transport_2_Motor_placeHolder[95];//结束
}UiData;
class Ui : public QObject
{
    Q_OBJECT
    //操作箱数据
    Q_PROPERTY(int commStatus READ getCommStatus WRITE setCommStatus NOTIFY commStatusChanged)//通信状态
    Q_PROPERTY(int springBackCmd READ getSpringBackCmd WRITE setSpringBackCmd NOTIFY springBackCmdChanged)//面板指令
    Q_PROPERTY(QString cmdText READ getCmdText WRITE setCmdText NOTIFY cmdTextChanged)//指令文本
    Q_PROPERTY(QString version READ getVersion WRITE setVersion NOTIFY versionChanged)//版本
    Q_PROPERTY(bool dataValidFlag READ getDataValidFlag WRITE setDataValidFlag NOTIFY dataValidFlagChanged)//指令有效性标识

    //ModbusTCP接收数据，UI属性注册
    //_system    系统
    Q_PROPERTY(int uiData_system_data_valid_flag READ get_uiData_system_data_valid_flag WRITE set_uiData_system_data_valid_flag NOTIFY uiData_system_data_valid_flagChanged)//数据有效标识
    Q_PROPERTY(int uiData_system_data_counter READ get_uiData_system_data_counter WRITE set_uiData_system_data_counter NOTIFY uiData_system_data_counterChanged)//流水号
    Q_PROPERTY(QString uiData_system_car_type READ get_uiData_system_car_type WRITE set_uiData_system_car_type NOTIFY uiData_system_car_typeChanged)//车型
    Q_PROPERTY(QString uiData_system_car_number READ get_uiData_system_car_number WRITE set_uiData_system_car_number NOTIFY uiData_system_car_numberChanged)//车号
    Q_PROPERTY(int uiData_system_ctrl_mode READ get_uiData_system_ctrl_mode WRITE set_uiData_system_ctrl_mode NOTIFY uiData_system_ctrl_modeChanged)//控制模式

    Q_PROPERTY(int uiData_system_auto_manual_cut_status READ get_uiData_system_auto_manual_cut_status WRITE set_uiData_system_auto_manual_cut_status NOTIFY uiData_system_auto_manual_cut_statusChanged)//自动或手动截割状态
    Q_PROPERTY(float uiData_system_system_voltage READ get_uiData_system_system_voltage WRITE set_uiData_system_system_voltage NOTIFY uiData_system_system_voltageChanged)//系统电压
    Q_PROPERTY(float uiData_system_start_time READ get_uiData_system_start_time WRITE set_uiData_system_start_time NOTIFY uiData_system_start_timeChanged)//启动时间
    Q_PROPERTY(float uiData_system_remote_time READ get_uiData_system_remote_time WRITE set_uiData_system_remote_time NOTIFY uiData_system_remote_timeChanged)//远控时间
    Q_PROPERTY(float uiData_system_auto_cut_time READ get_uiData_system_auto_cut_time WRITE set_uiData_system_auto_cut_time NOTIFY uiData_system_auto_cut_timeChanged)//自动截割时间

    Q_PROPERTY(int uiData_system_scram READ get_uiData_system_scram WRITE set_uiData_system_scram NOTIFY uiData_system_scramChanged)//急停状态
    Q_PROPERTY(int uiData_system_sensor_fault_info READ get_uiData_system_sensor_fault_info WRITE set_uiData_system_sensor_fault_info NOTIFY uiData_system_sensor_fault_infoChanged)//传感器、漏电、故障信息
    Q_PROPERTY(float uiData_system_hydraulic_pressure READ get_uiData_system_hydraulic_pressure WRITE set_uiData_system_hydraulic_pressure NOTIFY uiData_system_hydraulic_pressureChanged)//液压压力

    Q_PROPERTY(float uiData_system_environment_temp READ get_uiData_system_environment_temp WRITE set_uiData_system_environment_temp NOTIFY uiData_system_environment_tempChanged)//环境温度
    Q_PROPERTY(float uiData_system_environment_humidity READ get_uiData_system_environment_humidity WRITE set_uiData_system_environment_humidity NOTIFY uiData_system_environment_humidityChanged)//环境湿度
    Q_PROPERTY(float uiData_system_gas_density READ get_uiData_system_gas_density WRITE set_uiData_system_gas_density NOTIFY uiData_system_gas_densityChanged)//瓦斯浓度
    Q_PROPERTY(float uiData_system_dust_density READ get_uiData_system_dust_density WRITE set_uiData_system_dust_density NOTIFY uiData_system_dust_densityChanged)//粉尘浓度
    Q_PROPERTY(float uiData_system_carbon_density READ get_uiData_system_carbon_density WRITE set_uiData_system_carbon_density NOTIFY uiData_system_carbon_densityChanged)//CO浓度

    Q_PROPERTY(int uiData_system_pumpOilMotor_work_status READ get_uiData_system_pumpOilMotor_work_status WRITE set_uiData_system_pumpOilMotor_work_status NOTIFY uiData_system_pumpOilMotor_work_statusChanged)//油泵工作状态
    Q_PROPERTY(int uiData_system_cut_motor_work_status READ get_uiData_system_cut_motor_work_status WRITE set_uiData_system_cut_motor_work_status NOTIFY uiData_system_cut_motor_work_statusChanged)//截割电机状态
    Q_PROPERTY(int uiData_system_transport_2_motor_work_status READ get_uiData_system_transport_2_motor_work_status WRITE set_uiData_system_transport_2_motor_work_status NOTIFY uiData_system_transport_2_motor_work_statusChanged)//二运状态
    Q_PROPERTY(int uiData_system_fan_motor_work_status READ get_uiData_system_fan_motor_work_status WRITE set_uiData_system_fan_motor_work_status NOTIFY uiData_system_fan_motor_work_statusChanged)//风机状态
    Q_PROPERTY(int uiData_system_lubrication_work_status READ get_uiData_system_lubrication_work_status WRITE set_uiData_system_lubrication_work_status NOTIFY uiData_system_lubrication_work_statusChanged)//润滑状态

    Q_PROPERTY(int uiData_system_waterPump_work_status READ get_uiData_system_waterPump_work_status WRITE set_uiData_system_waterPump_work_status NOTIFY uiData_system_waterPump_work_statusChanged)//水泵启停状态
    Q_PROPERTY(int uiData_system_spray_valve_work_status READ get_uiData_system_spray_valve_work_status WRITE set_uiData_system_spray_valve_work_status NOTIFY uiData_system_spray_valve_work_statusChanged)//喷雾阀状态
    Q_PROPERTY(int uiData_system_transport_1_motor_work_status READ get_uiData_system_transport_1_motor_work_status WRITE set_uiData_system_transport_1_motor_work_status NOTIFY uiData_system_transport_1_motor_work_statusChanged)//一运状态
    Q_PROPERTY(int uiData_system_shoveBlade_work_status READ get_uiData_system_shoveBlade_work_status WRITE set_uiData_system_shoveBlade_work_status NOTIFY uiData_system_shoveBlade_work_statusChanged)//铲板状态
    Q_PROPERTY(int uiData_system_rearSupport_work_status READ get_uiData_system_rearSupport_work_status WRITE set_uiData_system_rearSupport_work_status NOTIFY uiData_system_rearSupport_work_statusChanged)//后支撑状态

    Q_PROPERTY(int uiData_system_cutArm_rotation_status READ get_uiData_system_cutArm_rotation_status WRITE set_uiData_system_cutArm_rotation_status NOTIFY uiData_system_cutArm_rotation_statusChanged)//截割臂回转状态
    Q_PROPERTY(int uiData_system_cutArm_up_down_status READ get_uiData_system_cutArm_up_down_status WRITE set_uiData_system_cutArm_up_down_status NOTIFY uiData_system_cutArm_up_down_statusChanged)//截割臂升降状态
    Q_PROPERTY(int uiData_system_cutArm_push_pull_status READ get_uiData_system_cutArm_push_pull_status WRITE set_uiData_system_cutArm_push_pull_status NOTIFY uiData_system_cutArm_push_pull_statusChanged)//截割臂伸缩状态
    Q_PROPERTY(int uiData_system_left_tract_work_status READ get_uiData_system_left_tract_work_status WRITE set_uiData_system_left_tract_work_status NOTIFY uiData_system_left_tract_work_statusChanged)//左行走状态
    Q_PROPERTY(int uiData_system_right_tract_work_status READ get_uiData_system_right_tract_work_status WRITE set_uiData_system_right_tract_work_status NOTIFY uiData_system_right_tract_work_statusChanged)//右行走状态

    Q_PROPERTY(int uiData_system_star_wheel_motor_work_status READ get_uiData_system_star_wheel_motor_work_status WRITE set_uiData_system_star_wheel_motor_work_status NOTIFY uiData_system_star_wheel_motor_work_statusChanged)//星轮状态
    Q_PROPERTY(int uiData_system_left_star_wheel_motor_work_status READ get_uiData_system_left_star_wheel_motor_work_status WRITE set_uiData_system_left_star_wheel_motor_work_status NOTIFY uiData_system_left_star_wheel_motor_work_statusChanged)//左星轮状态
    Q_PROPERTY(int uiData_system_right_star_wheel_motor_work_status READ get_uiData_system_right_star_wheel_motor_work_status WRITE set_uiData_system_right_star_wheel_motor_work_status NOTIFY uiData_system_right_star_wheel_motor_work_statusChanged)//右星轮状态
    Q_PROPERTY(float uiData_system_fuel_tank_temp READ get_uiData_system_fuel_tank_temp WRITE set_uiData_system_fuel_tank_temp NOTIFY uiData_system_fuel_tank_tempChanged)//油箱温度

    Q_PROPERTY(float uiData_system_fuel_tank_oil_level READ get_uiData_system_fuel_tank_oil_level WRITE set_uiData_system_fuel_tank_oil_level NOTIFY uiData_system_fuel_tank_oil_levelChanged)//油箱油位
    Q_PROPERTY(float uiData_system_cool_water_flow_calculate READ get_uiData_system_cool_water_flow_calculate WRITE set_uiData_system_cool_water_flow_calculate NOTIFY uiData_system_cool_water_flow_calculateChanged)//冷却水流量
    Q_PROPERTY(float uiData_system_cool_water_pressure READ get_uiData_system_cool_water_pressure WRITE set_uiData_system_cool_water_pressure NOTIFY uiData_system_cool_water_pressureChanged)//冷却水水压
    Q_PROPERTY(float uiData_system_fuselage_angle_X READ get_uiData_system_fuselage_angle_X WRITE set_uiData_system_fuselage_angle_X NOTIFY uiData_system_fuselage_angle_XChanged)//机身倾角X
    Q_PROPERTY(float uiData_system_fuselage_angle_Y READ get_uiData_system_fuselage_angle_Y WRITE set_uiData_system_fuselage_angle_Y NOTIFY uiData_system_fuselage_angle_YChanged)//机身倾角Y

    Q_PROPERTY(float uiData_system_fuselage_angle_Z READ get_uiData_system_fuselage_angle_Z WRITE set_uiData_system_fuselage_angle_Z NOTIFY uiData_system_fuselage_angle_ZChanged)//机身倾角Z
    Q_PROPERTY(float uiData_system_shoveBlade_angle_X READ get_uiData_system_shoveBlade_angle_X WRITE set_uiData_system_shoveBlade_angle_X NOTIFY uiData_system_shoveBlade_angle_XChanged)//铲板X倾角
    Q_PROPERTY(float uiData_system_shoveBlade_angle_Y READ get_uiData_system_shoveBlade_angle_Y WRITE set_uiData_system_shoveBlade_angle_Y NOTIFY uiData_system_shoveBlade_angle_YChanged)//铲板Y倾角
    Q_PROPERTY(float uiData_system_shoveBlade_offset READ get_uiData_system_shoveBlade_offset WRITE set_uiData_system_shoveBlade_offset NOTIFY uiData_system_shoveBlade_offsetChanged)//铲板位移
    Q_PROPERTY(float uiData_system_cutArm_rotation_offset READ get_uiData_system_cutArm_rotation_offset WRITE set_uiData_system_cutArm_rotation_offset NOTIFY uiData_system_cutArm_rotation_offsetChanged)//截割臂回转位移

    Q_PROPERTY(float uiData_system_cutArm_up_down_offset READ get_uiData_system_cutArm_up_down_offset WRITE set_uiData_system_cutArm_up_down_offset NOTIFY uiData_system_cutArm_up_down_offsetChanged)//截割臂升降位移
    Q_PROPERTY(float uiData_system_cutArm_push_pull_offset READ get_uiData_system_cutArm_push_pull_offset WRITE set_uiData_system_cutArm_push_pull_offset NOTIFY uiData_system_cutArm_push_pull_offsetChanged)//截割臂伸缩位移
    Q_PROPERTY(float uiData_system_rearSupport_offset READ get_uiData_system_rearSupport_offset WRITE set_uiData_system_rearSupport_offset NOTIFY uiData_system_rearSupport_offsetChanged)//后支撑位移
    Q_PROPERTY(float uiData_system_back_car_pressure READ get_uiData_system_back_car_pressure WRITE set_uiData_system_back_car_pressure NOTIFY uiData_system_back_car_pressureChanged)//倒车压力
    Q_PROPERTY(float uiData_system_rotation_1_pressure READ get_uiData_system_rotation_1_pressure WRITE set_uiData_system_rotation_1_pressure NOTIFY uiData_system_rotation_1_pressureChanged)//回转压力1

    Q_PROPERTY(float uiData_system_rotation_2_pressure READ get_uiData_system_rotation_2_pressure WRITE set_uiData_system_rotation_2_pressure NOTIFY uiData_system_rotation_2_pressureChanged)//回转压力2
    Q_PROPERTY(float uiData_system_up_down_1_pressure READ get_uiData_system_up_down_1_pressure WRITE set_uiData_system_up_down_1_pressure NOTIFY uiData_system_up_down_1_pressureChanged)//升降压力1
    Q_PROPERTY(float uiData_system_up_down_2_pressure READ get_uiData_system_up_down_2_pressure WRITE set_uiData_system_up_down_2_pressure NOTIFY uiData_system_up_down_2_pressureChanged)//升降压力2
    Q_PROPERTY(float uiData_system_push_pull_1_pressure READ get_uiData_system_push_pull_1_pressure WRITE set_uiData_system_push_pull_1_pressure NOTIFY uiData_system_push_pull_1_pressureChanged)//伸缩压力1
    Q_PROPERTY(float uiData_system_push_pull_2_pressure READ get_uiData_system_push_pull_2_pressure WRITE set_uiData_system_push_pull_2_pressure NOTIFY uiData_system_push_pull_2_pressureChanged)//伸缩压力2

    Q_PROPERTY(float uiData_system_left_forward_laser_distance READ get_uiData_system_left_forward_laser_distance WRITE set_uiData_system_left_forward_laser_distance NOTIFY uiData_system_left_forward_laser_distanceChanged)//左前激光测距

    Q_PROPERTY(float uiData_system_left_backward_laser_distance READ get_uiData_system_left_backward_laser_distance WRITE set_uiData_system_left_backward_laser_distance NOTIFY uiData_system_left_backward_laser_distanceChanged)//左后激光测距
    Q_PROPERTY(float uiData_system_right_forward_laser_distance READ get_uiData_system_right_forward_laser_distance WRITE set_uiData_system_right_forward_laser_distance NOTIFY uiData_system_right_forward_laser_distanceChanged)//右前激光测距
    Q_PROPERTY(float uiData_system_right_backward_laser_distance READ get_uiData_system_right_backward_laser_distance WRITE set_uiData_system_right_backward_laser_distance NOTIFY uiData_system_right_backward_laser_distanceChanged)//右后激光测距
    Q_PROPERTY(int uiData_system_person_detection READ get_uiData_system_person_detection WRITE set_uiData_system_person_detection NOTIFY uiData_system_person_detectionChanged)//人员检测

     Q_PROPERTY(float uiData_system_cut_motor_current READ get_uiData_system_cut_motor_current WRITE set_uiData_system_cut_motor_current NOTIFY uiData_system_cut_motor_currentChanged)//截割电机电流

    //HighCutMotor  截高电机
    Q_PROPERTY(int uiData_highCutMotor_work_status READ get_uiData_highCutMotor_work_status WRITE set_uiData_highCutMotor_work_status NOTIFY uiData_highCutMotor_work_statusChanged)//工作状态
    Q_PROPERTY(float uiData_highCutMotor_current_A READ get_uiData_highCutMotor_current_A WRITE set_uiData_highCutMotor_current_A NOTIFY uiData_highCutMotor_current_AChanged)//A电流
    Q_PROPERTY(float uiData_highCutMotor_current_B READ get_uiData_highCutMotor_current_B WRITE set_uiData_highCutMotor_current_B NOTIFY uiData_highCutMotor_current_BChanged)//B电流
    Q_PROPERTY(float uiData_highCutMotor_current_C READ get_uiData_highCutMotor_current_C WRITE set_uiData_highCutMotor_current_C NOTIFY uiData_highCutMotor_current_CChanged)//C电流
    Q_PROPERTY(float uiData_highCutMotor_current READ get_uiData_highCutMotor_current WRITE set_uiData_highCutMotor_current NOTIFY uiData_highCutMotor_currentChanged)//电流
    Q_PROPERTY(float uiData_highCutMotor_wind_temp READ get_uiData_highCutMotor_wind_temp WRITE set_uiData_highCutMotor_wind_temp NOTIFY uiData_highCutMotor_wind_tempChanged)//绕组温度
    Q_PROPERTY(int uiData_highCutMotor_AC_contractor_feedback_status READ get_uiData_highCutMotor_AC_contractor_feedback_status WRITE set_uiData_highCutMotor_AC_contractor_feedback_status NOTIFY uiData_highCutMotor_AC_contractor_feedback_statusChanged)//交流接触器反馈状态

    //LowCutMotor   截低电机
    Q_PROPERTY(int uiData_lowCutMotor_work_status READ get_uiData_lowCutMotor_work_status WRITE set_uiData_lowCutMotor_work_status NOTIFY uiData_lowCutMotor_work_statusChanged)//工作状态
    Q_PROPERTY(float uiData_lowCutMotor_current_A READ get_uiData_lowCutMotor_current_A WRITE set_uiData_lowCutMotor_current_A NOTIFY uiData_lowCutMotor_current_AChanged)//A电流
    Q_PROPERTY(float uiData_lowCutMotor_current_B READ get_uiData_lowCutMotor_current_B WRITE set_uiData_lowCutMotor_current_B NOTIFY uiData_lowCutMotor_current_BChanged)//B电流
    Q_PROPERTY(float uiData_lowCutMotor_current_C READ get_uiData_lowCutMotor_current_C WRITE set_uiData_lowCutMotor_current_C NOTIFY uiData_lowCutMotor_current_CChanged)//C电流
    Q_PROPERTY(float uiData_lowCutMotor_current READ get_uiData_lowCutMotor_current WRITE set_uiData_lowCutMotor_current NOTIFY uiData_lowCutMotor_currentChanged)//电流
    Q_PROPERTY(float uiData_lowCutMotor_wind_temp READ get_uiData_lowCutMotor_wind_temp WRITE set_uiData_lowCutMotor_wind_temp NOTIFY uiData_lowCutMotor_wind_tempChanged)//绕组温度
    Q_PROPERTY(int uiData_lowCutMotor_AC_contractor_feedback_status READ get_uiData_lowCutMotor_AC_contractor_feedback_status WRITE set_uiData_lowCutMotor_AC_contractor_feedback_status NOTIFY uiData_lowCutMotor_AC_contractor_feedback_statusChanged)//交流接触器反馈状态

    //FanMotor 风机
    Q_PROPERTY(int uiData_fanMotor_work_status READ get_uiData_fanMotor_work_status WRITE set_uiData_fanMotor_work_status NOTIFY uiData_fanMotor_work_statusChanged)//工作状态
    Q_PROPERTY(float uiData_fanMotor_current_A READ get_uiData_fanMotor_current_A WRITE set_uiData_fanMotor_current_A NOTIFY uiData_fanMotor_current_AChanged)//A电流
    Q_PROPERTY(float uiData_fanMotor_current_B READ get_uiData_fanMotor_current_B WRITE set_uiData_fanMotor_current_B NOTIFY uiData_fanMotor_current_BChanged)//B电流
    Q_PROPERTY(float uiData_fanMotor_current_C READ get_uiData_fanMotor_current_C WRITE set_uiData_fanMotor_current_C NOTIFY uiData_fanMotor_current_CChanged)//C电流
    Q_PROPERTY(float uiData_fanMotor_current READ get_uiData_fanMotor_current WRITE set_uiData_fanMotor_current NOTIFY uiData_fanMotor_currentChanged)//电流
    Q_PROPERTY(float uiData_fanMotor_wind_temp READ get_uiData_fanMotor_wind_temp WRITE set_uiData_fanMotor_wind_temp NOTIFY uiData_fanMotor_wind_tempChanged)//绕组温度
    Q_PROPERTY(int uiData_fanMotor_AC_contractor_feedback_status READ get_uiData_fanMotor_AC_contractor_feedback_status WRITE set_uiData_fanMotor_AC_contractor_feedback_status NOTIFY uiData_fanMotor_AC_contractor_feedback_statusChanged)//交流接触器反馈状态

    //pumpOilMotor  油泵电机

    Q_PROPERTY(int uiData_pumpOilMotor_work_status READ get_uiData_pumpOilMotor_work_status WRITE set_uiData_pumpOilMotor_work_status NOTIFY uiData_pumpOilMotor_work_statusChanged)//工作状态
    Q_PROPERTY(float uiData_pumpOilMotor_current_A READ get_uiData_pumpOilMotor_current_A WRITE set_uiData_pumpOilMotor_current_A NOTIFY uiData_pumpOilMotor_current_AChanged)//A电流
    Q_PROPERTY(float uiData_pumpOilMotor_current_B READ get_uiData_pumpOilMotor_current_B WRITE set_uiData_pumpOilMotor_current_B NOTIFY uiData_pumpOilMotor_current_BChanged)//B电流
    Q_PROPERTY(float uiData_pumpOilMotor_current_C READ get_uiData_pumpOilMotor_current_C WRITE set_uiData_pumpOilMotor_current_C NOTIFY uiData_pumpOilMotor_current_CChanged)//C电流
    Q_PROPERTY(float uiData_pumpOilMotor_current READ get_uiData_pumpOilMotor_current WRITE set_uiData_pumpOilMotor_current NOTIFY uiData_pumpOilMotor_currentChanged)//电流
    Q_PROPERTY(float uiData_pumpOilMotor_wind_temp READ get_uiData_pumpOilMotor_wind_temp WRITE set_uiData_pumpOilMotor_wind_temp NOTIFY uiData_pumpOilMotor_wind_tempChanged)//绕组温度
    Q_PROPERTY(int uiData_pumpOilMotor_AC_contractor_feedback_status READ get_uiData_pumpOilMotor_AC_contractor_feedback_status WRITE set_uiData_pumpOilMotor_AC_contractor_feedback_status NOTIFY uiData_pumpOilMotor_AC_contractor_feedback_statusChanged)//交流接触器反馈状态

    //transport2Motor   二运
    Q_PROPERTY(int uiData_transport_2_Motor_work_status READ get_uiData_transport_2_Motor_work_status WRITE set_uiData_transport_2_Motor_work_status NOTIFY uiData_transport_2_Motor_work_statusChanged)//工作状态
    Q_PROPERTY(float uiData_transport_2_Motor_current_A READ get_uiData_transport_2_Motor_current_A WRITE set_uiData_transport_2_Motor_current_A NOTIFY uiData_transport_2_Motor_current_AChanged)//A电流
    Q_PROPERTY(float uiData_transport_2_Motor_current_B READ get_uiData_transport_2_Motor_current_B WRITE set_uiData_transport_2_Motor_current_B NOTIFY uiData_transport_2_Motor_current_BChanged)//B电流
    Q_PROPERTY(float uiData_transport_2_Motor_current_C READ get_uiData_transport_2_Motor_current_C WRITE set_uiData_transport_2_Motor_current_C NOTIFY uiData_transport_2_Motor_current_CChanged)//C电流
    Q_PROPERTY(float uiData_transport_2_Motor_current READ get_uiData_transport_2_Motor_current WRITE set_uiData_transport_2_Motor_current NOTIFY uiData_transport_2_Motor_currentChanged)//电流
    Q_PROPERTY(float uiData_transport_2_Motor_wind_temp READ get_uiData_transport_2_Motor_wind_temp WRITE set_uiData_transport_2_Motor_wind_temp NOTIFY uiData_transport_2_Motor_wind_tempChanged)//绕组温度
    Q_PROPERTY(int uiData_transport_2_Motor_AC_contractor_feedback_status READ get_uiData_transport_2_Motor_AC_contractor_feedback_status WRITE set_uiData_transport_2_Motor_AC_contractor_feedback_status NOTIFY uiData_transport_2_Motor_AC_contractor_feedback_statusChanged)//交流接触器反馈状态

    //ModbusTCP接收数据
public:
    explicit Ui(QObject *parent = nullptr);
    ~Ui();
private:
    Q_INVOKABLE int getCommStatus() const {return m_commStatus;}
    Q_INVOKABLE void setCommStatus(int iVal);
    Q_INVOKABLE int getSpringBackCmd() const{return m_springBackCmd;}
    Q_INVOKABLE void setSpringBackCmd(int iVal);
    Q_INVOKABLE int getDataValidFlag() const{return m_dataValidFlag;}
    Q_INVOKABLE void setDataValidFlag(int iVal);


    Q_INVOKABLE QString getCmdText() const{return m_cmdText;}
    Q_INVOKABLE void setCmdText(const QString &sStr);
    Q_INVOKABLE QString getVersion() const{return m_version;}
    Q_INVOKABLE void setVersion(const QString &sStr);

    //ModbusTCP接收数据
    //_system    系统
    Q_INVOKABLE void set_uiData_system_data_valid_flag (int iVal);//数据有效标识
    Q_INVOKABLE void set_uiData_system_data_counter (int iVal);//流水号
    Q_INVOKABLE void set_uiData_system_car_type (const QString &sStr);//车型
    Q_INVOKABLE void set_uiData_system_car_number (const QString &sStr);//车号
    Q_INVOKABLE void set_uiData_system_ctrl_mode (int iVal);//控制模式

    Q_INVOKABLE void set_uiData_system_auto_manual_cut_status (int iVal);//自动或手动截割状态
    Q_INVOKABLE void set_uiData_system_system_voltage (int iVal);//系统电压
    Q_INVOKABLE void set_uiData_system_start_time (int iVal);//启动时间
    Q_INVOKABLE void set_uiData_system_remote_time (int iVal);//远控时间
    Q_INVOKABLE void set_uiData_system_auto_cut_time (int iVal);//自动截割时间


    Q_INVOKABLE void set_uiData_system_scram (int iVal);//急停状态
    Q_INVOKABLE void set_uiData_system_sensor_fault_info (int iVal);//传感器、漏电、故障信息
    Q_INVOKABLE void set_uiData_system_hydraulic_pressure (int iVal);//液压压力

    Q_INVOKABLE void set_uiData_system_environment_temp (int iVal);//环境温度
    Q_INVOKABLE void set_uiData_system_environment_humidity (int iVal);//环境湿度
    Q_INVOKABLE void set_uiData_system_gas_density (int iVal);//瓦斯浓度
    Q_INVOKABLE void set_uiData_system_dust_density (int iVal);//粉尘浓度
    Q_INVOKABLE void set_uiData_system_carbon_density (int iVal);//CO浓度

    Q_INVOKABLE void set_uiData_system_pumpOilMotor_work_status (int iVal);//油泵工作状态
    Q_INVOKABLE void set_uiData_system_cut_motor_work_status (int iVal);//截割电机状态
    Q_INVOKABLE void set_uiData_system_transport_2_motor_work_status (int iVal);//二运状态
    Q_INVOKABLE void set_uiData_system_fan_motor_work_status (int iVal);//风机状态
    Q_INVOKABLE void set_uiData_system_lubrication_work_status (int iVal);//润滑状态

    Q_INVOKABLE void set_uiData_system_waterPump_work_status (int iVal);//水泵启停状态
    Q_INVOKABLE void set_uiData_system_spray_valve_work_status (int iVal);//喷雾阀状态
    Q_INVOKABLE void set_uiData_system_transport_1_motor_work_status (int iVal);//一运状态
    Q_INVOKABLE void set_uiData_system_shoveBlade_work_status (int iVal);//铲板状态
    Q_INVOKABLE void set_uiData_system_rearSupport_work_status (int iVal);//后支撑状态

    Q_INVOKABLE void set_uiData_system_cutArm_rotation_status (int iVal);//截割臂回转状态
    Q_INVOKABLE void set_uiData_system_cutArm_up_down_status (int iVal);//截割臂升降状态
    Q_INVOKABLE void set_uiData_system_cutArm_push_pull_status (int iVal);//截割臂伸缩状态
    Q_INVOKABLE void set_uiData_system_left_tract_work_status (int iVal);//左行走状态
    Q_INVOKABLE void set_uiData_system_right_tract_work_status (int iVal);//右行走状态

    Q_INVOKABLE void set_uiData_system_star_wheel_motor_work_status (int iVal);//星轮状态
    Q_INVOKABLE void set_uiData_system_left_star_wheel_motor_work_status (int iVal);//左星轮状态
    Q_INVOKABLE void set_uiData_system_right_star_wheel_motor_work_status (int iVal);//右星轮状态

    Q_INVOKABLE void set_uiData_system_fuel_tank_temp (int iVal);//油箱温度

    Q_INVOKABLE void set_uiData_system_fuel_tank_oil_level (int iVal);//油箱油位
    Q_INVOKABLE void set_uiData_system_cool_water_flow_calculate (int iVal);//冷却水流量
    Q_INVOKABLE void set_uiData_system_cool_water_pressure (int iVal);//冷却水水压
    Q_INVOKABLE void set_uiData_system_fuselage_angle_X (int iVal);//机身倾角X
    Q_INVOKABLE void set_uiData_system_fuselage_angle_Y (int iVal);//机身倾角Y

    Q_INVOKABLE void set_uiData_system_fuselage_angle_Z (int iVal);//机身倾角Z
    Q_INVOKABLE void set_uiData_system_shoveBlade_angle_X (int iVal);//铲板X倾角
    Q_INVOKABLE void set_uiData_system_shoveBlade_angle_Y (int iVal);//铲板Y倾角
    Q_INVOKABLE void set_uiData_system_shoveBlade_offset (int iVal);//铲板位移
    Q_INVOKABLE void set_uiData_system_cutArm_rotation_offset (int iVal);//截割臂回转位移

    Q_INVOKABLE void set_uiData_system_cutArm_up_down_offset (int iVal);//截割臂升降位移
    Q_INVOKABLE void set_uiData_system_cutArm_push_pull_offset (int iVal);//截割臂伸缩位移
    Q_INVOKABLE void set_uiData_system_rearSupport_offset (int iVal);//后支撑位移
    Q_INVOKABLE void set_uiData_system_back_car_pressure (int iVal);//倒车压力
    Q_INVOKABLE void set_uiData_system_rotation_1_pressure (int iVal);//回转压力1

    Q_INVOKABLE void set_uiData_system_rotation_2_pressure (int iVal);//回转压力2
    Q_INVOKABLE void set_uiData_system_up_down_1_pressure (int iVal);//升降压力1
    Q_INVOKABLE void set_uiData_system_up_down_2_pressure (int iVal);//升降压力2
    Q_INVOKABLE void set_uiData_system_push_pull_1_pressure (int iVal);//伸缩压力1
    Q_INVOKABLE void set_uiData_system_push_pull_2_pressure (int iVal);//伸缩压力2


    Q_INVOKABLE void set_uiData_system_left_forward_laser_distance (int iVal);//左前激光测距

    Q_INVOKABLE void set_uiData_system_left_backward_laser_distance (int iVal);//左后激光测距
    Q_INVOKABLE void set_uiData_system_right_forward_laser_distance (int iVal);//右前激光测距
    Q_INVOKABLE void set_uiData_system_right_backward_laser_distance (int iVal);//右后激光测距
    Q_INVOKABLE void set_uiData_system_person_detection (int iVal);//人员检测

    Q_INVOKABLE void set_uiData_system_cut_motor_current (int iVal);//截割电机电流

    //HighCutMotor  截高电机
    Q_INVOKABLE void set_uiData_highCutMotor_work_status (int iVal);//工作状态
    Q_INVOKABLE void set_uiData_highCutMotor_current_A (int iVal);//A电流
    Q_INVOKABLE void set_uiData_highCutMotor_current_B (int iVal);//B电流
    Q_INVOKABLE void set_uiData_highCutMotor_current_C (int iVal);//C电流
    Q_INVOKABLE void set_uiData_highCutMotor_current (int iVal);//电流
    Q_INVOKABLE void set_uiData_highCutMotor_wind_temp (int iVal);//绕组温度
    Q_INVOKABLE void set_uiData_highCutMotor_AC_contractor_feedback_status (int iVal);//交流接触器反馈状态


    //LowCutMotor   截低电机
    Q_INVOKABLE void set_uiData_lowCutMotor_work_status (int iVal);//工作状态
    Q_INVOKABLE void set_uiData_lowCutMotor_current_A (int iVal);//A电流
    Q_INVOKABLE void set_uiData_lowCutMotor_current_B (int iVal);//B电流
    Q_INVOKABLE void set_uiData_lowCutMotor_current_C (int iVal);//C电流
    Q_INVOKABLE void set_uiData_lowCutMotor_current (int iVal);//电流
    Q_INVOKABLE void set_uiData_lowCutMotor_wind_temp (int iVal);//绕组温度
    Q_INVOKABLE void set_uiData_lowCutMotor_AC_contractor_feedback_status (int iVal);//交流接触器反馈状态


    //FanMotor 风机
    Q_INVOKABLE void set_uiData_fanMotor_work_status (int iVal);//工作状态
    Q_INVOKABLE void set_uiData_fanMotor_current_A (int iVal);//A电流
    Q_INVOKABLE void set_uiData_fanMotor_current_B (int iVal);//B电流
    Q_INVOKABLE void set_uiData_fanMotor_current_C (int iVal);//C电流
    Q_INVOKABLE void set_uiData_fanMotor_current (int iVal);//电流
    Q_INVOKABLE void set_uiData_fanMotor_wind_temp (int iVal);//绕组温度
    Q_INVOKABLE void set_uiData_fanMotor_AC_contractor_feedback_status (int iVal);//交流接触器反馈状态

    //pumpOilMotor  油泵电机
    Q_INVOKABLE void set_uiData_pumpOilMotor_work_status (int iVal);//工作状态
    Q_INVOKABLE void set_uiData_pumpOilMotor_current_A (int iVal);//A电流
    Q_INVOKABLE void set_uiData_pumpOilMotor_current_B (int iVal);//B电流
    Q_INVOKABLE void set_uiData_pumpOilMotor_current_C (int iVal);//C电流
    Q_INVOKABLE void set_uiData_pumpOilMotor_current (int iVal);//电流
    Q_INVOKABLE void set_uiData_pumpOilMotor_wind_temp (int iVal);//绕组温度
    Q_INVOKABLE void set_uiData_pumpOilMotor_AC_contractor_feedback_status (int iVal);//交流接触器反馈状态

    //transport2Motor
    Q_INVOKABLE void set_uiData_transport_2_Motor_work_status (int iVal);//工作状态
    Q_INVOKABLE void set_uiData_transport_2_Motor_current_A (int iVal);//A电流
    Q_INVOKABLE void set_uiData_transport_2_Motor_current_B (int iVal);//B电流
    Q_INVOKABLE void set_uiData_transport_2_Motor_current_C (int iVal);//C电流
    Q_INVOKABLE void set_uiData_transport_2_Motor_current (int iVal);//电流
    Q_INVOKABLE void set_uiData_transport_2_Motor_wind_temp (int iVal);//绕组温度
    Q_INVOKABLE void set_uiData_transport_2_Motor_AC_contractor_feedback_status (int iVal);//交流接触器反馈状态


    //_system    系统
    Q_INVOKABLE int get_uiData_system_data_valid_flag() const{return uiData.uiData_system_data_valid_flag;}//数据有效标识
    Q_INVOKABLE int get_uiData_system_data_counter() const{return uiData.uiData_system_data_counter;}//流水号
    Q_INVOKABLE QString  get_uiData_system_car_type() const{QString strCarType = QString::fromUtf8(uiData.uiData_system_car_type);return strCarType;}//车型
    Q_INVOKABLE QString  get_uiData_system_car_number() const{QString strCarType = QString::fromUtf8(uiData.uiData_system_car_number);return strCarType;}//车号
    Q_INVOKABLE int get_uiData_system_ctrl_mode() const{return uiData.uiData_system_ctrl_mode;}//控制模式

    Q_INVOKABLE int get_uiData_system_auto_manual_cut_status() const{return uiData.uiData_system_auto_manual_cut_status;}//自动或手动截割状态
    Q_INVOKABLE float get_uiData_system_system_voltage() const{return uiData.uiData_system_system_voltage;}//系统电压
    Q_INVOKABLE float get_uiData_system_start_time() const{return uiData.uiData_system_start_time;}//启动时间
    Q_INVOKABLE float get_uiData_system_remote_time() const{return uiData.uiData_system_remote_time;}//远控时间
    Q_INVOKABLE float get_uiData_system_auto_cut_time() const{return uiData.uiData_system_auto_cut_time;}//自动截割时间

    Q_INVOKABLE int get_uiData_system_scram() const{return uiData.uiData_system_scram;}//急停状态
    Q_INVOKABLE int get_uiData_system_sensor_fault_info() const{return uiData.uiData_system_sensor_fault_info;}//传感器、漏电、故障信息
    Q_INVOKABLE float get_uiData_system_hydraulic_pressure() const{return uiData.uiData_system_hydraulic_pressure;}//液压压力

    Q_INVOKABLE float get_uiData_system_environment_temp() const{return uiData.uiData_system_environment_temp;}//环境温度
    Q_INVOKABLE float get_uiData_system_environment_humidity() const{return uiData.uiData_system_environment_humidity;}//环境湿度
    Q_INVOKABLE float get_uiData_system_gas_density() const{return uiData.uiData_system_gas_density;}//瓦斯浓度
    Q_INVOKABLE float get_uiData_system_dust_density() const{return uiData.uiData_system_dust_density;}//粉尘浓度
    Q_INVOKABLE float get_uiData_system_carbon_density() const{return uiData.uiData_system_carbon_density;}//CO浓度

    Q_INVOKABLE int get_uiData_system_pumpOilMotor_work_status() const{return uiData.uiData_system_pumpOilMotor_work_status;}//油泵工作状态
    Q_INVOKABLE int get_uiData_system_cut_motor_work_status() const{return uiData.uiData_system_cut_motor_work_status;}//截割电机状态
    Q_INVOKABLE int get_uiData_system_transport_2_motor_work_status() const{return uiData.uiData_system_transport_2_motor_work_status;}//二运状态
    Q_INVOKABLE int get_uiData_system_fan_motor_work_status() const{return uiData.uiData_system_fan_motor_work_status;}//风机状态
    Q_INVOKABLE int get_uiData_system_lubrication_work_status() const{return uiData.uiData_system_lubrication_work_status;}//润滑状态

    Q_INVOKABLE int get_uiData_system_waterPump_work_status() const{return uiData.uiData_system_waterPump_work_status;}//水泵启停状态
    Q_INVOKABLE int get_uiData_system_spray_valve_work_status() const{return uiData.uiData_system_spray_valve_work_status;}//喷雾阀状态
    Q_INVOKABLE int get_uiData_system_transport_1_motor_work_status() const{return uiData.uiData_system_transport_1_motor_work_status;}//一运状态
    Q_INVOKABLE int get_uiData_system_shoveBlade_work_status() const{return uiData.uiData_system_shoveBlade_work_status;}//铲板状态
    Q_INVOKABLE int get_uiData_system_rearSupport_work_status() const{return uiData.uiData_system_rearSupport_work_status;}//后支撑状态

    Q_INVOKABLE int get_uiData_system_cutArm_rotation_status() const{return uiData.uiData_system_cutArm_rotation_status;}//截割臂回转状态
    Q_INVOKABLE int get_uiData_system_cutArm_up_down_status() const{return uiData.uiData_system_cutArm_up_down_status;}//截割臂升降状态
    Q_INVOKABLE int get_uiData_system_cutArm_push_pull_status() const{return uiData.uiData_system_cutArm_push_pull_status;}//截割臂伸缩状态
    Q_INVOKABLE int get_uiData_system_left_tract_work_status() const{return uiData.uiData_system_left_tract_work_status;}//左行走状态
    Q_INVOKABLE int get_uiData_system_right_tract_work_status() const{return uiData.uiData_system_right_tract_work_status;}//右行走状态

    Q_INVOKABLE int get_uiData_system_star_wheel_motor_work_status() const{return uiData.uiData_system_star_wheel_motor_work_status;}//星轮状态
    Q_INVOKABLE int get_uiData_system_left_star_wheel_motor_work_status() const{return uiData.uiData_system_left_star_wheel_motor_work_status;}//左星轮状态
    Q_INVOKABLE int get_uiData_system_right_star_wheel_motor_work_status() const{return uiData.uiData_system_right_star_wheel_motor_work_status;}//右星轮状态
    Q_INVOKABLE float get_uiData_system_fuel_tank_temp() const{return uiData.uiData_system_fuel_tank_temp;}//油箱温度

    Q_INVOKABLE float get_uiData_system_fuel_tank_oil_level() const{return uiData.uiData_system_fuel_tank_oil_level;}//油箱油位
    Q_INVOKABLE float get_uiData_system_cool_water_flow_calculate() const{return uiData.uiData_system_cool_water_flow_calculate;}//冷却水流量
    Q_INVOKABLE float get_uiData_system_cool_water_pressure() const{return uiData.uiData_system_cool_water_pressure;}//冷却水水压
    Q_INVOKABLE float get_uiData_system_fuselage_angle_X() const{return uiData.uiData_system_fuselage_angle_X;}//机身倾角X
    Q_INVOKABLE float get_uiData_system_fuselage_angle_Y() const{return uiData.uiData_system_fuselage_angle_Y;}//机身倾角Y

    Q_INVOKABLE float get_uiData_system_fuselage_angle_Z() const{return uiData.uiData_system_fuselage_angle_Z;}//机身倾角Z
    Q_INVOKABLE float get_uiData_system_shoveBlade_angle_X() const{return uiData.uiData_system_shoveBlade_angle_X;}//铲板X倾角
    Q_INVOKABLE float get_uiData_system_shoveBlade_angle_Y() const{return uiData.uiData_system_shoveBlade_angle_Y;}//铲板Y倾角
    Q_INVOKABLE float get_uiData_system_shoveBlade_offset() const{return uiData.uiData_system_shoveBlade_offset;}//铲板位移
    Q_INVOKABLE float get_uiData_system_cutArm_rotation_offset() const{return uiData.uiData_system_cutArm_rotation_offset;}//截割臂回转位移

    Q_INVOKABLE float get_uiData_system_cutArm_up_down_offset() const{return uiData.uiData_system_cutArm_up_down_offset;}//截割臂升降位移
    Q_INVOKABLE float get_uiData_system_cutArm_push_pull_offset() const{return uiData.uiData_system_cutArm_push_pull_offset;}//截割臂伸缩位移
    Q_INVOKABLE float get_uiData_system_rearSupport_offset() const{return uiData.uiData_system_rearSupport_offset;}//后支撑位移
    Q_INVOKABLE float get_uiData_system_back_car_pressure() const{return uiData.uiData_system_back_car_pressure;}//倒车压力
    Q_INVOKABLE float get_uiData_system_rotation_1_pressure() const{return uiData.uiData_system_rotation_1_pressure;}//回转压力1

    Q_INVOKABLE float get_uiData_system_rotation_2_pressure() const{return uiData.uiData_system_rotation_2_pressure;}//回转压力2
    Q_INVOKABLE float get_uiData_system_up_down_1_pressure() const{return uiData.uiData_system_up_down_1_pressure;}//升降压力1
    Q_INVOKABLE float get_uiData_system_up_down_2_pressure() const{return uiData.uiData_system_up_down_2_pressure;}//升降压力2
    Q_INVOKABLE float get_uiData_system_push_pull_1_pressure() const{return uiData.uiData_system_push_pull_1_pressure;}//伸缩压力1
    Q_INVOKABLE float get_uiData_system_push_pull_2_pressure() const{return uiData.uiData_system_push_pull_2_pressure;}//伸缩压力2

    Q_INVOKABLE float get_uiData_system_left_forward_laser_distance() const{return uiData.uiData_system_left_forward_laser_distance;}//左前激光测距

    Q_INVOKABLE float get_uiData_system_left_backward_laser_distance() const{return uiData.uiData_system_left_backward_laser_distance;}//左后激光测距
    Q_INVOKABLE float get_uiData_system_right_forward_laser_distance() const{return uiData.uiData_system_right_forward_laser_distance;}//右前激光测距
    Q_INVOKABLE float get_uiData_system_right_backward_laser_distance() const{return uiData.uiData_system_right_backward_laser_distance;}//右后激光测距
    Q_INVOKABLE int get_uiData_system_person_detection() const{return uiData.uiData_system_person_detection;}//人员检测

    Q_INVOKABLE float get_uiData_system_cut_motor_current() const{return uiData.uiData_system_cut_motor_current;}//截割电机电流

    //HighCutMotor  截高电机
    Q_INVOKABLE int get_uiData_highCutMotor_work_status() const{return uiData.uiData_highCutMotor_work_status;}//工作状态
    Q_INVOKABLE float get_uiData_highCutMotor_current_A() const{return uiData.uiData_highCutMotor_current_A;}//A电流
    Q_INVOKABLE float get_uiData_highCutMotor_current_B() const{return uiData.uiData_highCutMotor_current_B;}//B电流
    Q_INVOKABLE float get_uiData_highCutMotor_current_C() const{return uiData.uiData_highCutMotor_current_C;}//C电流
    Q_INVOKABLE float get_uiData_highCutMotor_current() const{return uiData.uiData_highCutMotor_current;}//电流
    Q_INVOKABLE float get_uiData_highCutMotor_wind_temp() const{return uiData.uiData_highCutMotor_wind_temp;}//绕组温度
    Q_INVOKABLE int get_uiData_highCutMotor_AC_contractor_feedback_status() const{return uiData.uiData_highCutMotor_AC_contractor_feedback_status;}//交流接触器反馈状态

    //LowCutMotor   截低电机
    Q_INVOKABLE int get_uiData_lowCutMotor_work_status() const{return uiData.uiData_lowCutMotor_work_status;}//工作状态
    Q_INVOKABLE float get_uiData_lowCutMotor_current_A() const{return uiData.uiData_lowCutMotor_current_A;}//A电流
    Q_INVOKABLE float get_uiData_lowCutMotor_current_B() const{return uiData.uiData_lowCutMotor_current_B;}//B电流
    Q_INVOKABLE float get_uiData_lowCutMotor_current_C() const{return uiData.uiData_lowCutMotor_current_C;}//C电流
    Q_INVOKABLE float get_uiData_lowCutMotor_current() const{return uiData.uiData_lowCutMotor_current;}//电流
    Q_INVOKABLE float get_uiData_lowCutMotor_wind_temp() const{return uiData.uiData_lowCutMotor_wind_temp;}//绕组温度
    Q_INVOKABLE int get_uiData_lowCutMotor_AC_contractor_feedback_status() const{return uiData.uiData_lowCutMotor_AC_contractor_feedback_status;}//交流接触器反馈状态

    //FanMotor 风机
    Q_INVOKABLE int get_uiData_fanMotor_work_status() const{return uiData.uiData_fanMotor_work_status;}//工作状态
    Q_INVOKABLE float get_uiData_fanMotor_current_A() const{return uiData.uiData_fanMotor_current_A;}//A电流
    Q_INVOKABLE float get_uiData_fanMotor_current_B() const{return uiData.uiData_fanMotor_current_B;}//B电流
    Q_INVOKABLE float get_uiData_fanMotor_current_C() const{return uiData.uiData_fanMotor_current_C;}//C电流
    Q_INVOKABLE float get_uiData_fanMotor_current() const{return uiData.uiData_fanMotor_current;}//电流
    Q_INVOKABLE float get_uiData_fanMotor_wind_temp() const{return uiData.uiData_fanMotor_wind_temp;}//绕组温度
    Q_INVOKABLE int get_uiData_fanMotor_AC_contractor_feedback_status() const{return uiData.uiData_fanMotor_AC_contractor_feedback_status;}//交流接触器反馈状态

    //pumpOilMotor  油泵电机
    Q_INVOKABLE int get_uiData_pumpOilMotor_work_status() const{return uiData.uiData_pumpOilMotor_work_status;}//工作状态
    Q_INVOKABLE float get_uiData_pumpOilMotor_current_A() const{return uiData.uiData_pumpOilMotor_current_A;}//A电流
    Q_INVOKABLE float get_uiData_pumpOilMotor_current_B() const{return uiData.uiData_pumpOilMotor_current_B;}//B电流
    Q_INVOKABLE float get_uiData_pumpOilMotor_current_C() const{return uiData.uiData_pumpOilMotor_current_C;}//C电流
    Q_INVOKABLE float get_uiData_pumpOilMotor_current() const{return uiData.uiData_pumpOilMotor_current;}//电流
    Q_INVOKABLE float get_uiData_pumpOilMotor_wind_temp() const{return uiData.uiData_pumpOilMotor_wind_temp;}//绕组温度
    Q_INVOKABLE int get_uiData_pumpOilMotor_AC_contractor_feedback_status() const{return uiData.uiData_pumpOilMotor_AC_contractor_feedback_status;}//交流接触器反馈状态

    //transport2Motor   二运
    Q_INVOKABLE int get_uiData_transport_2_Motor_work_status() const{return uiData.uiData_transport_2_Motor_work_status;}//工作状态
    Q_INVOKABLE float get_uiData_transport_2_Motor_current_A() const{return uiData.uiData_transport_2_Motor_current_A;}//A电流
    Q_INVOKABLE float get_uiData_transport_2_Motor_current_B() const{return uiData.uiData_transport_2_Motor_current_B;}//B电流
    Q_INVOKABLE float get_uiData_transport_2_Motor_current_C() const{return uiData.uiData_transport_2_Motor_current_C;}//C电流
    Q_INVOKABLE float get_uiData_transport_2_Motor_current() const{return uiData.uiData_transport_2_Motor_current;}//电流
    Q_INVOKABLE float get_uiData_transport_2_Motor_wind_temp() const{return uiData.uiData_transport_2_Motor_wind_temp;}//绕组温度
    Q_INVOKABLE int get_uiData_transport_2_Motor_AC_contractor_feedback_status() const{return uiData.uiData_transport_2_Motor_AC_contractor_feedback_status;}//交流接触器反馈状态

    //ModbusTCP接收数据
public:
    static Ui* GetInstance();
    void RegreshViewData(PluginManager* pluginManager);
private:
    void MapInit();
    QString GetText(const int num);
    static void* ViewDataRefreshThread(void *arg);

signals:
    void commStatusChanged();
    void springBackCmdChanged();
    void dataValidFlagChanged();
    void cmdTextChanged();
    void versionChanged();
    //ModbusTCP接收数据
    //_system    系统
    void uiData_system_data_valid_flagChanged();//数据有效标识
    void uiData_system_data_counterChanged();//流水号
    void uiData_system_car_typeChanged();//车型
    void uiData_system_car_numberChanged();//车号
    void uiData_system_ctrl_modeChanged();//控制模式

    void uiData_system_auto_manual_cut_statusChanged();//自动或手动截割状态
    void uiData_system_system_voltageChanged();//系统电压
    void uiData_system_start_timeChanged();//启动时间
    void uiData_system_remote_timeChanged();//远控时间
    void uiData_system_auto_cut_timeChanged();//自动截割时间

    void uiData_system_scramChanged();//急停状态
    void uiData_system_sensor_fault_infoChanged();//传感器、漏电、故障信息
    void uiData_system_hydraulic_pressureChanged();//液压压力

    void uiData_system_environment_tempChanged();//环境温度
    void uiData_system_environment_humidityChanged();//环境湿度
    void uiData_system_gas_densityChanged();//瓦斯浓度
    void uiData_system_dust_densityChanged();//粉尘浓度
    void uiData_system_carbon_densityChanged();//CO浓度

    void uiData_system_pumpOilMotor_work_statusChanged();//油泵工作状态
    void uiData_system_cut_motor_work_statusChanged();//截割电机状态
    void uiData_system_transport_2_motor_work_statusChanged();//二运状态
    void uiData_system_fan_motor_work_statusChanged();//风机状态
    void uiData_system_lubrication_work_statusChanged();//润滑状态

    void uiData_system_waterPump_work_statusChanged();//水泵启停状态
    void uiData_system_spray_valve_work_statusChanged();//喷雾阀状态
    void uiData_system_transport_1_motor_work_statusChanged();//一运状态
    void uiData_system_shoveBlade_work_statusChanged();//铲板状态
    void uiData_system_rearSupport_work_statusChanged();//后支撑状态

    void uiData_system_cutArm_rotation_statusChanged();//截割臂回转状态
    void uiData_system_cutArm_up_down_statusChanged();//截割臂升降状态
    void uiData_system_cutArm_push_pull_statusChanged();//截割臂伸缩状态
    void uiData_system_left_tract_work_statusChanged();//左行走状态
    void uiData_system_right_tract_work_statusChanged();//右行走状态

    void uiData_system_star_wheel_motor_work_statusChanged();//星轮状态
    void uiData_system_left_star_wheel_motor_work_statusChanged();//左星轮状态
    void uiData_system_right_star_wheel_motor_work_statusChanged();//右星轮状态

    void uiData_system_fuel_tank_tempChanged();//油箱温度

    void uiData_system_fuel_tank_oil_levelChanged();//油箱油位
    void uiData_system_cool_water_flow_calculateChanged();//冷却水流量
    void uiData_system_cool_water_pressureChanged();//冷却水水压
    void uiData_system_fuselage_angle_XChanged();//机身倾角X
    void uiData_system_fuselage_angle_YChanged();//机身倾角Y

    void uiData_system_fuselage_angle_ZChanged();//机身倾角Z
    void uiData_system_shoveBlade_angle_XChanged();//铲板X倾角
    void uiData_system_shoveBlade_angle_YChanged();//铲板Y倾角
    void uiData_system_shoveBlade_offsetChanged();//铲板位移
    void uiData_system_cutArm_rotation_offsetChanged();//截割臂回转位移

    void uiData_system_cutArm_up_down_offsetChanged();//截割臂升降位移
    void uiData_system_cutArm_push_pull_offsetChanged();//截割臂伸缩位移
    void uiData_system_rearSupport_offsetChanged();//后支撑位移
    void uiData_system_back_car_pressureChanged();//倒车压力
    void uiData_system_rotation_1_pressureChanged();//回转压力1

    void uiData_system_rotation_2_pressureChanged();//回转压力2
    void uiData_system_up_down_1_pressureChanged();//升降压力1
    void uiData_system_up_down_2_pressureChanged();//升降压力2
    void uiData_system_push_pull_1_pressureChanged();//伸缩压力1
    void uiData_system_push_pull_2_pressureChanged();//伸缩压力2

    void uiData_system_left_forward_laser_distanceChanged();//左前激光测距

    void uiData_system_left_backward_laser_distanceChanged();//左后激光测距
    void uiData_system_right_forward_laser_distanceChanged();//右前激光测距
    void uiData_system_right_backward_laser_distanceChanged();//右后激光测距
    void uiData_system_person_detectionChanged();//人员检测

    void uiData_system_cut_motor_currentChanged();//截割电机电流

    //HighCutMotor  截高电机
    void uiData_highCutMotor_work_statusChanged();//工作状态
    void uiData_highCutMotor_current_AChanged();//A电流
    void uiData_highCutMotor_current_BChanged();//B电流
    void uiData_highCutMotor_current_CChanged();//C电流
    void uiData_highCutMotor_currentChanged();//电流
    void uiData_highCutMotor_wind_tempChanged();//绕组温度
    void uiData_highCutMotor_AC_contractor_feedback_statusChanged();//交流接触器反馈状态


    //LowCutMotor   截低电机
    void uiData_lowCutMotor_work_statusChanged();//工作状态
    void uiData_lowCutMotor_current_AChanged();//A电流
    void uiData_lowCutMotor_current_BChanged();//B电流
    void uiData_lowCutMotor_current_CChanged();//C电流
    void uiData_lowCutMotor_currentChanged();//电流
    void uiData_lowCutMotor_wind_tempChanged();//绕组温度
    void uiData_lowCutMotor_AC_contractor_feedback_statusChanged();//交流接触器反馈状态


    //FanMotor 风机
    void uiData_fanMotor_work_statusChanged();//工作状态
    void uiData_fanMotor_current_AChanged();//A电流
    void uiData_fanMotor_current_BChanged();//B电流
    void uiData_fanMotor_current_CChanged();//C电流
    void uiData_fanMotor_currentChanged();//电流
    void uiData_fanMotor_wind_tempChanged();//绕组温度
    void uiData_fanMotor_AC_contractor_feedback_statusChanged();//交流接触器反馈状态


    //pumpOilMotor  油泵电机
    void uiData_pumpOilMotor_work_statusChanged();//工作状态
    void uiData_pumpOilMotor_current_AChanged();//A电流
    void uiData_pumpOilMotor_current_BChanged();//B电流
    void uiData_pumpOilMotor_current_CChanged();//C电流
    void uiData_pumpOilMotor_currentChanged();//电流
    void uiData_pumpOilMotor_wind_tempChanged();//绕组温度
    void uiData_pumpOilMotor_AC_contractor_feedback_statusChanged();//交流接触器反馈状态


    //transport2Motor   二运
    void uiData_transport_2_Motor_work_statusChanged();//工作状态
    void uiData_transport_2_Motor_current_AChanged();//A电流
    void uiData_transport_2_Motor_current_BChanged();//B电流
    void uiData_transport_2_Motor_current_CChanged();//C电流
    void uiData_transport_2_Motor_currentChanged();//电流
    void uiData_transport_2_Motor_wind_tempChanged();//绕组温度
    void uiData_transport_2_Motor_AC_contractor_feedback_statusChanged();//交流接触器反馈状态
    //ModbusTCP接收数据
public slots:
//界面需显示的数据
private:
    //controlplat 操作台
    int m_commStatus;//通信状态
    int m_springBackCmd;//面板指令
    bool m_dataValidFlag;//数据有效标识
    QString m_cmdText;//指令文本
    QString m_version;//版本
    std::map<int,std::string> mapDisplay;//指令文本容器

    //ModbusTCP
    FrameRxData* frameRxData;//ModbusTCP获取数据
    UiData uiData;//Ui显示数据
};
//操作台指令
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
    E_CMD_POWERON,//开机
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
    E_CMD_REMOTE_CRTL,//远控
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

#endif // UI_H
