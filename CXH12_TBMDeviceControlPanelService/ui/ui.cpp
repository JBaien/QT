#include "ui.h"

#include <QDebug>
#include <unistd.h>
#include <string.h>

Ui::Ui(QObject *parent) : QObject(parent)
    ,m_commStatus(0)
    ,m_springBackCmd(0)
{
    frameRxData = nullptr;
    m_cmdText = "";
    m_version = "";
    memset(&uiData,0,sizeof(uiData));
}
Ui::~Ui()
{

}
void Ui::setCommStatus(int value)
{
    if(m_commStatus == value)
        return;
    m_commStatus = value;
    emit commStatusChanged();
}

void Ui::setSpringBackCmd(int value)
{
    if(m_springBackCmd == value)
        return;

    m_springBackCmd = value;
    emit springBackCmdChanged();
}
void Ui::setDataValidFlag(int value)
{
    if(m_dataValidFlag == value)
        return;
    m_dataValidFlag = value;
    emit dataValidFlagChanged();
}
void Ui::setCmdText(const QString &sStr)
{
    if(m_cmdText == sStr)
        return;
    m_cmdText = sStr;
    emit cmdTextChanged();
}
void Ui::setVersion(const QString &sStr)
{
    if(m_version == sStr)
        return;
    m_version = sStr;
    emit versionChanged();

}

//ModbusTCP数据的set函数，处理数据
//_system    系统
void Ui::set_uiData_system_data_valid_flag (int iVal)//数据有效标识
{
    if(uiData.uiData_system_data_valid_flag == iVal)
        return;
    uiData.uiData_system_data_valid_flag = iVal;
    emit uiData_system_data_valid_flagChanged();
}
void Ui::set_uiData_system_data_counter (int iVal)//流水号
{
    if(uiData.uiData_system_data_counter == iVal)
        return;
    uiData.uiData_system_data_counter = iVal;
    emit uiData_system_data_counterChanged();
}
void Ui::set_uiData_system_car_type (const QString &sStr)//车型
{
    QString qstrCarType = QString::fromUtf8(uiData.uiData_system_car_type);
    if(qstrCarType == sStr)
        return;
    std::string strCarType = sStr.toStdString();
    char* cstr = const_cast<char*>(strCarType.c_str());
    memcpy(uiData.uiData_system_car_type,cstr,sizeof(uiData.uiData_system_car_type));
    memset((char*)uiData.uiData_system_car_type + sizeof(uiData.uiData_system_car_type) - 1,0,sizeof(char));
    emit uiData_system_car_typeChanged();
}
void Ui::set_uiData_system_car_number (const QString &sStr)//车号
{
    QString qstrCarNum = QString::fromUtf8(uiData.uiData_system_car_number);
    if(qstrCarNum == sStr)
        return;
    std::string strCarNum = sStr.toStdString();
    char* cstr = const_cast<char*>(strCarNum.c_str());
    memcpy(uiData.uiData_system_car_number,cstr,sizeof(uiData.uiData_system_car_number));
    memset((char*)uiData.uiData_system_car_number + sizeof(uiData.uiData_system_car_number) - 1,0,sizeof(char));
    emit uiData_system_car_numberChanged();
}
void Ui::set_uiData_system_ctrl_mode (int iVal)//控制模式
{
    if(uiData.uiData_system_ctrl_mode == iVal)
        return;
    uiData.uiData_system_ctrl_mode = iVal;
    emit uiData_system_ctrl_modeChanged();
}
void Ui::set_uiData_system_auto_manual_cut_status (int iVal)//自动或手动截割状态
{
    if(uiData.uiData_system_auto_manual_cut_status == iVal)
        return;
    uiData.uiData_system_auto_manual_cut_status = iVal;
    emit uiData_system_auto_manual_cut_statusChanged();
}
void Ui::set_uiData_system_system_voltage (int iVal)//系统电压
{
    static int system_system_voltage_original = 0;
    if(system_system_voltage_original == iVal)
        return;
    system_system_voltage_original = iVal;
    uiData.uiData_system_system_voltage = iVal / 10.0;
    emit uiData_system_system_voltageChanged();
}
void Ui::set_uiData_system_start_time (int iVal)//启动时间
{
    static int system_start_time_original = 0;
    if(system_start_time_original == iVal)
        return;
    system_start_time_original = iVal;
    uiData.uiData_system_start_time = iVal / 10.0;
    emit uiData_system_start_timeChanged();
}
void Ui::set_uiData_system_remote_time (int iVal)//远控时间
{
    static int system_remote_time_original = 0;
    if(system_remote_time_original == iVal)
        return;
    system_remote_time_original = iVal;
    uiData.uiData_system_remote_time = iVal / 10.0;
    emit uiData_system_remote_timeChanged();
}
void Ui::set_uiData_system_auto_cut_time (int iVal)//自动截割时间
{
    static int system_auto_cut_time_original = 0;
    if(system_auto_cut_time_original == iVal)
        return;
    system_auto_cut_time_original = iVal;
    uiData.uiData_system_auto_cut_time = iVal / 10.0;
    emit uiData_system_auto_cut_timeChanged();
}
void Ui::set_uiData_system_scram (int iVal)//急停状态
{
    if(uiData.uiData_system_scram == iVal)
        return;
    uiData.uiData_system_scram = iVal;
    emit uiData_system_scramChanged();
}
void Ui::set_uiData_system_sensor_fault_info (int iVal)//传感器、漏电、故障信息
{
    if(uiData.uiData_system_sensor_fault_info == iVal)
        return;
    uiData.uiData_system_sensor_fault_info = iVal;
    emit uiData_system_sensor_fault_infoChanged();
}
void Ui::set_uiData_system_hydraulic_pressure (int iVal)//液压压力
{
    static int system_hydraulic_pressure_original = 0;
    if(system_hydraulic_pressure_original == iVal)
        return;
    system_hydraulic_pressure_original = iVal;
    uiData.uiData_system_hydraulic_pressure = iVal / 10.0;
    emit uiData_system_hydraulic_pressureChanged();
}
void Ui::set_uiData_system_environment_temp (int iVal)//环境温度
{
    static int system_environment_temp_original = 0;
    if(system_environment_temp_original == iVal)
        return;
    system_environment_temp_original = iVal;
    uiData.uiData_system_environment_temp = iVal / 10.0;
    emit uiData_system_environment_tempChanged();
}
void Ui::set_uiData_system_environment_humidity (int iVal)//环境湿度
{
    static int system_environment_humidity_original = 0;
    if(system_environment_humidity_original == iVal)
        return;
    system_environment_humidity_original = iVal;
    uiData.uiData_system_environment_humidity = iVal / 100.0;
    emit uiData_system_environment_humidityChanged();
}
void Ui::set_uiData_system_gas_density (int iVal)//瓦斯浓度
{
    static int system_gas_density_original = 0;
    if(system_gas_density_original == iVal)
        return;
    system_gas_density_original = iVal;
    uiData.uiData_system_gas_density = iVal / 100.0;
    emit uiData_system_gas_densityChanged();
}
void Ui::set_uiData_system_dust_density (int iVal)//粉尘浓度
{
    static int system_gas_density_original = 0;
    if(system_gas_density_original == iVal)
        return;
    system_gas_density_original = iVal;
    uiData.uiData_system_dust_density = iVal / 10.0;
    emit uiData_system_dust_densityChanged();
}
void Ui::set_uiData_system_carbon_density (int iVal)//CO浓度
{
    static int system_carbon_density_original = 0;
    if(system_carbon_density_original == iVal)
        return;
    system_carbon_density_original = iVal;
    uiData.uiData_system_carbon_density = iVal / 100.0;
    emit uiData_system_carbon_densityChanged();
}
void Ui::set_uiData_system_pumpOilMotor_work_status (int iVal)//油泵工作状态
{
    if(uiData.uiData_system_pumpOilMotor_work_status == iVal)
        return;
    uiData.uiData_system_pumpOilMotor_work_status = iVal;
    emit uiData_system_pumpOilMotor_work_statusChanged();
}
void Ui::set_uiData_system_cut_motor_work_status (int iVal)//截割电机状态
{
    if(uiData.uiData_system_cut_motor_work_status == iVal)
        return;
    uiData.uiData_system_cut_motor_work_status = iVal;
    emit uiData_system_cut_motor_work_statusChanged();
}
void Ui::set_uiData_system_transport_2_motor_work_status (int iVal)//二运状态
{
    if(uiData.uiData_system_transport_2_motor_work_status == iVal)
        return;
    uiData.uiData_system_transport_2_motor_work_status = iVal;
    emit uiData_system_transport_2_motor_work_statusChanged();
}
void Ui::set_uiData_system_fan_motor_work_status (int iVal)//风机状态
{
    if(uiData.uiData_system_fan_motor_work_status == iVal)
        return;
    uiData.uiData_system_fan_motor_work_status = iVal;
    emit uiData_system_fan_motor_work_statusChanged();
}
void Ui::set_uiData_system_lubrication_work_status (int iVal)//润滑状态
{
    if(uiData.uiData_system_lubrication_work_status == iVal)
        return;
    uiData.uiData_system_lubrication_work_status = iVal;
    emit uiData_system_lubrication_work_statusChanged();
}
void Ui::set_uiData_system_waterPump_work_status (int iVal)//水泵启停状态
{
    if(uiData.uiData_system_waterPump_work_status == iVal)
        return;
    uiData.uiData_system_waterPump_work_status = iVal;
    emit uiData_system_waterPump_work_statusChanged();
}
void Ui::set_uiData_system_spray_valve_work_status (int iVal)//喷雾阀状态
{
    if(uiData.uiData_system_spray_valve_work_status == iVal)
        return;
    uiData.uiData_system_spray_valve_work_status = iVal;
    emit uiData_system_spray_valve_work_statusChanged();
}
void Ui::set_uiData_system_transport_1_motor_work_status (int iVal)//一运状态
{
    if(uiData.uiData_system_transport_1_motor_work_status == iVal)
        return;
    uiData.uiData_system_transport_1_motor_work_status = iVal;
    emit uiData_system_transport_1_motor_work_statusChanged();
}
void Ui::set_uiData_system_shoveBlade_work_status (int iVal)//铲板状态
{
    if(uiData.uiData_system_shoveBlade_work_status == iVal)
        return;
    uiData.uiData_system_shoveBlade_work_status = iVal;
    emit uiData_system_shoveBlade_work_statusChanged();
}
void Ui::set_uiData_system_rearSupport_work_status (int iVal)//后支撑状态

{
    if(uiData.uiData_system_rearSupport_work_status == iVal)
        return;
    uiData.uiData_system_rearSupport_work_status = iVal;
    emit uiData_system_rearSupport_work_statusChanged();
}
void Ui::set_uiData_system_cutArm_rotation_status (int iVal)//截割臂回转状态
{
    if(uiData.uiData_system_cutArm_rotation_status == iVal)
        return;
    uiData.uiData_system_cutArm_rotation_status = iVal;
    emit uiData_system_cutArm_rotation_statusChanged();
}
void Ui::set_uiData_system_cutArm_up_down_status (int iVal)//截割臂升降状态
{
    if(uiData.uiData_system_cutArm_up_down_status == iVal)
        return;
    uiData.uiData_system_cutArm_up_down_status = iVal;
    emit uiData_system_cutArm_up_down_statusChanged();
}
void Ui::set_uiData_system_cutArm_push_pull_status (int iVal)//截割臂伸缩状态
{
    if(uiData.uiData_system_cutArm_push_pull_status == iVal)
        return;
    uiData.uiData_system_cutArm_push_pull_status = iVal;
    emit uiData_system_cutArm_push_pull_statusChanged();
}
void Ui::set_uiData_system_left_tract_work_status (int iVal)//左行走状态
{
    if(uiData.uiData_system_left_tract_work_status == iVal)
        return;
    uiData.uiData_system_left_tract_work_status = iVal;
    emit uiData_system_left_tract_work_statusChanged();
}
void Ui::set_uiData_system_right_tract_work_status (int iVal)//右行走状态
{
    if(uiData.uiData_system_right_tract_work_status == iVal)
        return;
    uiData.uiData_system_right_tract_work_status = iVal;
    emit uiData_system_right_tract_work_statusChanged();
}
void Ui::set_uiData_system_star_wheel_motor_work_status (int iVal)//星轮状态
{
    if(uiData.uiData_system_star_wheel_motor_work_status == iVal)
        return;
    uiData.uiData_system_star_wheel_motor_work_status = iVal;
    emit uiData_system_star_wheel_motor_work_statusChanged();
}
void Ui::set_uiData_system_left_star_wheel_motor_work_status (int iVal)//左星轮状态
{
    if(uiData.uiData_system_left_star_wheel_motor_work_status == iVal)
        return;
    uiData.uiData_system_left_star_wheel_motor_work_status = iVal;
    emit uiData_system_star_wheel_motor_work_statusChanged();
}
void Ui::set_uiData_system_right_star_wheel_motor_work_status (int iVal)//右星轮状态
{
    if(uiData.uiData_system_right_star_wheel_motor_work_status == iVal)
        return;
    uiData.uiData_system_right_star_wheel_motor_work_status = iVal;
    emit uiData_system_right_star_wheel_motor_work_statusChanged();
}
void Ui::set_uiData_system_fuel_tank_temp (int iVal)//油箱温度

{
    static int system_fuel_tank_temp_original = 0;
    if(system_fuel_tank_temp_original == iVal)
        return;
    system_fuel_tank_temp_original = iVal;
    uiData.uiData_system_fuel_tank_temp = iVal / 10.0;
    emit uiData_system_fuel_tank_tempChanged();
}
void Ui::set_uiData_system_fuel_tank_oil_level (int iVal)//油箱油位
{
    static int system_fuel_tank_oil_level_original = 0;
    if(system_fuel_tank_oil_level_original == iVal)
        return;
    system_fuel_tank_oil_level_original = iVal;
    uiData.uiData_system_fuel_tank_oil_level = iVal / 1.0;
    emit uiData_system_fuel_tank_oil_levelChanged();
}
void Ui::set_uiData_system_cool_water_flow_calculate (int iVal)//冷却水流量
{
    static int system_cool_water_flow_calculate_original = 0;
    if(system_cool_water_flow_calculate_original == iVal)
        return;
    system_cool_water_flow_calculate_original = iVal;
    uiData.uiData_system_cool_water_flow_calculate = iVal / 1.0;
    emit uiData_system_cool_water_flow_calculateChanged();
}
void Ui::set_uiData_system_cool_water_pressure (int iVal)//冷却水水压
{
    static int system_cool_water_pressure_original = 0;
    if(system_cool_water_pressure_original == iVal)
        return;
    system_cool_water_pressure_original = iVal;
    uiData.uiData_system_cool_water_pressure = iVal / 10.0;
    emit uiData_system_cool_water_pressureChanged();
}
void Ui::set_uiData_system_fuselage_angle_X (int iVal)//机身倾角X
{
    static int system_fuselage_angle_X_original = 0;
    if(system_fuselage_angle_X_original == iVal)
        return;
    system_fuselage_angle_X_original = iVal;
    uiData.uiData_system_fuselage_angle_X = iVal / 100.0;
    emit uiData_system_fuselage_angle_XChanged();
}
void Ui::set_uiData_system_fuselage_angle_Y (int iVal)//机身倾角Y

{
    static int system_fuselage_angle_Y_original = 0;
    if(system_fuselage_angle_Y_original == iVal)
        return;
    system_fuselage_angle_Y_original = iVal;
    uiData.uiData_system_fuselage_angle_Y = iVal / 100.0;
    emit uiData_system_fuselage_angle_YChanged();
}
void Ui::set_uiData_system_fuselage_angle_Z (int iVal)//机身倾角Z
{
    static int system_fuselage_angle_Z_original = 0;
    if(system_fuselage_angle_Z_original == iVal)
        return;
    system_fuselage_angle_Z_original = iVal;
    uiData.uiData_system_fuselage_angle_Z = iVal / 100.0;
    emit uiData_system_fuselage_angle_ZChanged();
}
void Ui::set_uiData_system_shoveBlade_angle_X (int iVal)//铲板X倾角
{
    static int system_shoveBlade_angle_X_original = 0;
    if(system_shoveBlade_angle_X_original == iVal)
        return;
    system_shoveBlade_angle_X_original = iVal;
    uiData.uiData_system_shoveBlade_angle_X = iVal / 100.0;
    emit uiData_system_shoveBlade_angle_XChanged();
}
void Ui::set_uiData_system_shoveBlade_angle_Y (int iVal)//铲板Y倾角
{
    static int system_shoveBlade_angle_Y_original = 0;
    if(system_shoveBlade_angle_Y_original == iVal)
        return;
    system_shoveBlade_angle_Y_original = iVal;
    uiData.uiData_system_shoveBlade_angle_Y = iVal / 100.0;
    emit uiData_system_shoveBlade_angle_YChanged();
}
void Ui::set_uiData_system_shoveBlade_offset (int iVal)//铲板位移
{
    static int system_shoveBlade_offset_original = 0;
    if(system_shoveBlade_offset_original == iVal)
        return;
    system_shoveBlade_offset_original = iVal;
    uiData.uiData_system_shoveBlade_offset = iVal / 1.0;
    emit uiData_system_shoveBlade_offsetChanged();
}
void Ui::set_uiData_system_cutArm_rotation_offset (int iVal)//截割臂回转位移

{
    static int system_cutArm_rotation_offset_original = 0;
    if(system_cutArm_rotation_offset_original == iVal)
        return;
    system_cutArm_rotation_offset_original = iVal;
    uiData.uiData_system_cutArm_rotation_offset = iVal / 1.0;
    emit uiData_system_cutArm_rotation_offsetChanged();
}
void Ui::set_uiData_system_cutArm_up_down_offset (int iVal)//截割臂升降位移
{
    static int system_cutArm_up_down_offset_original = 0;
    if(system_cutArm_up_down_offset_original == iVal)
        return;
    system_cutArm_up_down_offset_original = iVal;
    uiData.uiData_system_cutArm_up_down_offset = iVal / 1.0;
    emit uiData_system_cutArm_up_down_offsetChanged();
}
void Ui::set_uiData_system_cutArm_push_pull_offset (int iVal)//截割臂伸缩位移
{
    static int system_cutArm_push_pull_offset_original = 0;
    if(system_cutArm_push_pull_offset_original == iVal)
        return;
    system_cutArm_push_pull_offset_original = iVal;
    uiData.uiData_system_cutArm_push_pull_offset = iVal / 1.0;
    emit uiData_system_cutArm_push_pull_offsetChanged();
}
void Ui::set_uiData_system_rearSupport_offset (int iVal)//后支撑位移
{
    static int system_rearSupport_offset_original = 0;
    if(system_rearSupport_offset_original == iVal)
        return;
    system_rearSupport_offset_original = iVal;
    uiData.uiData_system_rearSupport_offset = iVal / 1.0;
    emit uiData_system_rearSupport_offsetChanged();
}
void Ui::set_uiData_system_back_car_pressure (int iVal)//倒车压力
{
    static int system_back_car_pressure_original = 0;
    if(system_back_car_pressure_original == iVal)
        return;
    system_back_car_pressure_original = iVal;
    uiData.uiData_system_back_car_pressure = iVal / 10.0;
    emit uiData_system_back_car_pressureChanged();
}
void Ui::set_uiData_system_rotation_1_pressure (int iVal)//回转压力1
{
    static int system_rotation_1_pressure_original = 0;
    if(system_rotation_1_pressure_original == iVal)
        return;
    system_rotation_1_pressure_original = iVal;
    uiData.uiData_system_rotation_1_pressure = iVal / 10.0;
    emit uiData_system_rotation_1_pressureChanged();
}
void Ui::set_uiData_system_rotation_2_pressure (int iVal)//回转压力2
{
    static int system_rotation_2_pressure_original = 0;
    if(system_rotation_2_pressure_original == iVal)
        return;
    system_rotation_2_pressure_original = iVal;
    uiData.uiData_system_rotation_2_pressure = iVal / 10.0;
    emit uiData_system_rotation_2_pressureChanged();
}
void Ui::set_uiData_system_up_down_1_pressure (int iVal)//升降压力1
{
    static int system_up_down_1_pressure_original = 0;
    if(system_up_down_1_pressure_original == iVal)
        return;
    system_up_down_1_pressure_original = iVal;
    uiData.uiData_system_up_down_1_pressure = iVal / 10.0;
    emit uiData_system_up_down_1_pressureChanged();
}
void Ui::set_uiData_system_up_down_2_pressure (int iVal)//升降压力2
{
    static int system_up_down_2_pressure_original = 0;
    if(system_up_down_2_pressure_original == iVal)
        return;
    system_up_down_2_pressure_original = iVal;
    uiData.uiData_system_up_down_2_pressure = iVal / 10.0;
    emit uiData_system_up_down_2_pressureChanged();
}
void Ui::set_uiData_system_push_pull_1_pressure (int iVal)//伸缩压力1
{
    static int system_push_pull_1_pressure_original = 0;
    if(system_push_pull_1_pressure_original == iVal)
        return;
    system_push_pull_1_pressure_original = iVal;
    uiData.uiData_system_push_pull_1_pressure = iVal / 10.0;
    emit uiData_system_push_pull_1_pressureChanged();
}
void Ui::set_uiData_system_push_pull_2_pressure (int iVal)//伸缩压力2
{
    static int system_push_pull_2_pressure_original = 0;
    if(system_push_pull_2_pressure_original == iVal)
        return;
    system_push_pull_2_pressure_original = iVal;
    uiData.uiData_system_push_pull_2_pressure = iVal / 10.0;
    emit uiData_system_push_pull_2_pressureChanged();
}
void Ui::set_uiData_system_left_forward_laser_distance (int iVal)//左前激光测距

{
    static int system_left_forward_laser_distance_original = 0;
    if(system_left_forward_laser_distance_original == iVal)
        return;
    system_left_forward_laser_distance_original = iVal;
    uiData.uiData_system_left_forward_laser_distance = iVal / 1.0;
    emit uiData_system_left_forward_laser_distanceChanged();
}
void Ui::set_uiData_system_left_backward_laser_distance (int iVal)//左后激光测距
{
    static int system_left_backward_laser_distance_original = 0;
    if(system_left_backward_laser_distance_original == iVal)
        return;
    system_left_backward_laser_distance_original = iVal;
    uiData.uiData_system_left_backward_laser_distance = iVal / 1.0;
    emit uiData_system_left_backward_laser_distanceChanged();
}
void Ui::set_uiData_system_right_forward_laser_distance (int iVal)//右前激光测距
{
    static int system_right_forward_laser_distance_original = 0;
    if(system_right_forward_laser_distance_original == iVal)
        return;
    system_right_forward_laser_distance_original = iVal;
    uiData.uiData_system_right_forward_laser_distance = iVal / 1.0;
    emit uiData_system_right_forward_laser_distanceChanged();
}
void Ui::set_uiData_system_right_backward_laser_distance (int iVal)//右后激光测距
{
    static int system_right_backward_laser_distance_original = 0;
    if(system_right_backward_laser_distance_original == iVal)
        return;
    system_right_backward_laser_distance_original = iVal;
    uiData.uiData_system_right_backward_laser_distance = iVal / 1.0;
    emit uiData_system_right_backward_laser_distanceChanged();
}
void Ui::set_uiData_system_person_detection (int iVal)//人员检测
{
    if(uiData.uiData_system_person_detection == iVal)
        return;
    uiData.uiData_system_person_detection = iVal;
    emit uiData_system_person_detectionChanged();
}
void Ui::set_uiData_system_cut_motor_current (int iVal)//截割电机电流
{
    static int system_cut_motor_current_original = 0;
    if(system_cut_motor_current_original == iVal)
        return;
    system_cut_motor_current_original = iVal;
    uiData.uiData_system_cut_motor_current = iVal / 10.0;
    emit uiData_system_cut_motor_currentChanged();
}
//HighCutMotor  截高电机
void Ui::set_uiData_highCutMotor_work_status (int iVal)//工作状态
{
    if(uiData.uiData_highCutMotor_work_status == iVal)
        return;
    uiData.uiData_highCutMotor_work_status = iVal;
    emit uiData_highCutMotor_work_statusChanged();
}
void Ui::set_uiData_highCutMotor_current_A (int iVal)//A电流
{
    static int highCutMotor_current_A_original = 0;
    if(highCutMotor_current_A_original == iVal)
        return;
    highCutMotor_current_A_original = iVal;
    uiData.uiData_highCutMotor_current_A = iVal / 10.0;
    emit uiData_highCutMotor_current_AChanged();
}
void Ui::set_uiData_highCutMotor_current_B (int iVal)//B电流
{
    static int highCutMotor_current_B_original = 0;
    if(highCutMotor_current_B_original == iVal)
        return;
    highCutMotor_current_B_original = iVal;
    uiData.uiData_highCutMotor_current_B = iVal / 10.0;
    emit uiData_highCutMotor_current_BChanged();
}
void Ui::set_uiData_highCutMotor_current_C (int iVal)//C电流
{
    static int highCutMotor_current_C_original = 0;
    if(highCutMotor_current_C_original == iVal)
        return;
    highCutMotor_current_C_original = iVal;
    uiData.uiData_highCutMotor_current_C = iVal / 10.0;
    emit uiData_highCutMotor_current_CChanged();
}
void Ui::set_uiData_highCutMotor_current (int iVal)//电流
{
    static int highCutMotor_current_original = 0;
    if(highCutMotor_current_original == iVal)
        return;
    highCutMotor_current_original = iVal;
    uiData.uiData_highCutMotor_current = iVal / 10.0;
    emit uiData_highCutMotor_currentChanged();
}
void Ui::set_uiData_highCutMotor_wind_temp (int iVal)//绕组温度
{
    static int highCutMotor_wind_temp_original = 0;
    if(highCutMotor_wind_temp_original == iVal)
        return;
    highCutMotor_wind_temp_original = iVal;
    uiData.uiData_highCutMotor_wind_temp = iVal / 10.0;
    emit uiData_highCutMotor_wind_tempChanged();
}
void Ui::set_uiData_highCutMotor_AC_contractor_feedback_status (int iVal)//交流接触器反馈状态
{
    if(uiData.uiData_highCutMotor_AC_contractor_feedback_status == iVal)
        return;
    uiData.uiData_highCutMotor_AC_contractor_feedback_status = iVal;
    emit uiData_highCutMotor_AC_contractor_feedback_statusChanged();
}
//LowCutMotor   截低电机
void Ui::set_uiData_lowCutMotor_work_status (int iVal)//工作状态
{
    if(uiData.uiData_lowCutMotor_work_status == iVal)
        return;
    uiData.uiData_lowCutMotor_work_status = iVal;
    emit uiData_lowCutMotor_work_statusChanged();
}
void Ui::set_uiData_lowCutMotor_current_A (int iVal)//A电流
{
    static int lowCutMotor_current_A_original = 0;
    if(lowCutMotor_current_A_original == iVal)
        return;
    lowCutMotor_current_A_original = iVal;
    uiData.uiData_lowCutMotor_current_A = iVal / 10.0;
    emit uiData_lowCutMotor_current_AChanged();
}
void Ui::set_uiData_lowCutMotor_current_B (int iVal)//B电流
{
    static int lowCutMotor_current_B_original = 0;
    if(lowCutMotor_current_B_original == iVal)
        return;
    lowCutMotor_current_B_original = iVal;
    uiData.uiData_lowCutMotor_current_B = iVal / 10.0;
    emit uiData_lowCutMotor_current_BChanged();
}
void Ui::set_uiData_lowCutMotor_current_C (int iVal)//C电流
{
    static int lowCutMotor_current_C_original = 0;
    if(lowCutMotor_current_C_original == iVal)
        return;
    lowCutMotor_current_C_original = iVal;
    uiData.uiData_lowCutMotor_current_C = iVal / 10.0;
    emit uiData_lowCutMotor_current_CChanged();
}
void Ui::set_uiData_lowCutMotor_current (int iVal)//电流
{
    static int lowCutMotor_current_original = 0;
    if(lowCutMotor_current_original == iVal)
        return;
    lowCutMotor_current_original = iVal;
    uiData.uiData_lowCutMotor_current = iVal / 10.0;
    emit uiData_lowCutMotor_currentChanged();
}
void Ui::set_uiData_lowCutMotor_wind_temp (int iVal)//绕组温度
{
    static int lowCutMotor_wind_temp_original = 0;
    if(lowCutMotor_wind_temp_original == iVal)
        return;
    lowCutMotor_wind_temp_original = iVal;
    uiData.uiData_lowCutMotor_wind_temp = iVal / 10.0;
    emit uiData_lowCutMotor_wind_tempChanged();
}
void Ui::set_uiData_lowCutMotor_AC_contractor_feedback_status (int iVal)//交流接触器反馈状态
{
    if(uiData.uiData_lowCutMotor_AC_contractor_feedback_status == iVal)
        return;
    uiData.uiData_lowCutMotor_AC_contractor_feedback_status = iVal;
    emit uiData_lowCutMotor_AC_contractor_feedback_statusChanged();
}
//FanMotor 风机
void Ui::set_uiData_fanMotor_work_status (int iVal)//工作状态
{
    if(uiData.uiData_fanMotor_work_status == iVal)
        return;
    uiData.uiData_fanMotor_work_status = iVal;
    emit uiData_fanMotor_work_statusChanged();
}
void Ui::set_uiData_fanMotor_current_A (int iVal)//A电流
{
    static int fanMotor_current_A_original = 0;
    if(fanMotor_current_A_original == iVal)
        return;
    fanMotor_current_A_original = iVal;
    uiData.uiData_fanMotor_current_A = iVal / 10.0;
    emit uiData_fanMotor_current_AChanged();
}
void Ui::set_uiData_fanMotor_current_B (int iVal)//B电流
{
    static int fanMotor_current_B_original = 0;
    if(fanMotor_current_B_original == iVal)
        return;
    fanMotor_current_B_original = iVal;
    uiData.uiData_fanMotor_current_B = iVal / 10.0;
    emit uiData_fanMotor_current_BChanged();
}
void Ui::set_uiData_fanMotor_current_C (int iVal)//C电流
{
    static int fanMotor_current_C_original = 0;
    if(fanMotor_current_C_original == iVal)
        return;
    fanMotor_current_C_original = iVal;
    uiData.uiData_fanMotor_current_C = iVal / 10.0;
    emit uiData_fanMotor_current_CChanged();
}
void Ui::set_uiData_fanMotor_current (int iVal)//电流
{
    static int fanMotor_current_original = 0;
    if(fanMotor_current_original == iVal)
        return;
    fanMotor_current_original = iVal;
    uiData.uiData_fanMotor_current = iVal / 10.0;
    emit uiData_fanMotor_currentChanged();
}
void Ui::set_uiData_fanMotor_wind_temp (int iVal)//绕组温度
{
    static int fanMotor_wind_temp_original = 0;
    if(fanMotor_wind_temp_original == iVal)
        return;
    fanMotor_wind_temp_original = iVal;
    uiData.uiData_fanMotor_wind_temp = iVal / 10.0;
    emit uiData_fanMotor_wind_tempChanged();
}
void Ui::set_uiData_fanMotor_AC_contractor_feedback_status (int iVal)//交流接触器反馈状态
{
    if(uiData.uiData_fanMotor_AC_contractor_feedback_status == iVal)
        return;
    uiData.uiData_fanMotor_AC_contractor_feedback_status = iVal;
    emit uiData_fanMotor_AC_contractor_feedback_statusChanged();
}
//pumpOilMotor  油泵电机
void Ui::set_uiData_pumpOilMotor_work_status (int iVal)//工作状态
{
    if(uiData.uiData_pumpOilMotor_work_status == iVal)
        return;
    uiData.uiData_pumpOilMotor_work_status = iVal;
    emit uiData_pumpOilMotor_work_statusChanged();
}
void Ui::set_uiData_pumpOilMotor_current_A (int iVal)//A电流
{
    static int pumpOilMotor_current_A_original = 0;
    if(pumpOilMotor_current_A_original == iVal)
        return;
    pumpOilMotor_current_A_original = iVal;
    uiData.uiData_pumpOilMotor_current_A = iVal / 10.0;
    emit uiData_pumpOilMotor_current_AChanged();
}
void Ui::set_uiData_pumpOilMotor_current_B (int iVal)//B电流
{
    static int pumpOilMotor_current_B_original = 0;
    if(pumpOilMotor_current_B_original == iVal)
        return;
    pumpOilMotor_current_B_original = iVal;
    uiData.uiData_pumpOilMotor_current_B = iVal / 10.0;
    emit uiData_pumpOilMotor_current_BChanged();
}
void Ui::set_uiData_pumpOilMotor_current_C (int iVal)//C电流
{
    static int pumpOilMotor_current_C_original = 0;
    if(pumpOilMotor_current_C_original == iVal)
        return;
    pumpOilMotor_current_C_original = iVal;
    uiData.uiData_pumpOilMotor_current_C = iVal / 10.0;
    emit uiData_pumpOilMotor_current_CChanged();
}
void Ui::set_uiData_pumpOilMotor_current (int iVal)//电流
{
    static int pumpOilMotor_current_original = 0;
    if(pumpOilMotor_current_original == iVal)
        return;
    pumpOilMotor_current_original = iVal;
    uiData.uiData_pumpOilMotor_current = iVal / 10.0;
    emit uiData_pumpOilMotor_currentChanged();
}
void Ui::set_uiData_pumpOilMotor_wind_temp (int iVal)//绕组温度
{
    static int pumpOilMotor_wind_temp_original = 0;
    if(pumpOilMotor_wind_temp_original == iVal)
        return;
    pumpOilMotor_wind_temp_original = iVal;
    uiData.uiData_pumpOilMotor_wind_temp = iVal / 10.0;
    emit uiData_pumpOilMotor_wind_tempChanged();
}
void Ui::set_uiData_pumpOilMotor_AC_contractor_feedback_status (int iVal)//交流接触器反馈状态
{
    if(uiData.uiData_pumpOilMotor_AC_contractor_feedback_status == iVal)
        return;
    uiData.uiData_pumpOilMotor_AC_contractor_feedback_status = iVal;
    emit uiData_pumpOilMotor_AC_contractor_feedback_statusChanged();
}
//transport2Motor
void Ui::set_uiData_transport_2_Motor_work_status (int iVal)//工作状态
{
    if(uiData.uiData_transport_2_Motor_work_status == iVal)
        return;
    uiData.uiData_transport_2_Motor_work_status = iVal;
    emit uiData_transport_2_Motor_work_statusChanged();
}
void Ui::set_uiData_transport_2_Motor_current_A (int iVal)//A电流
{
    static int transport_2_Motor_current_A_original = 0;
    if(transport_2_Motor_current_A_original == iVal)
        return;
    transport_2_Motor_current_A_original = iVal;
    uiData.uiData_transport_2_Motor_current_A = iVal / 10.0;
    emit uiData_transport_2_Motor_current_AChanged();
}
void Ui::set_uiData_transport_2_Motor_current_B (int iVal)//B电流
{
    static int transport_2_Motor_current_B_original = 0;
    if(transport_2_Motor_current_B_original == iVal)
        return;
    transport_2_Motor_current_B_original = iVal;
    uiData.uiData_transport_2_Motor_current_B = iVal / 10.0;
    emit uiData_transport_2_Motor_current_BChanged();
}
void Ui::set_uiData_transport_2_Motor_current_C (int iVal)//C电流
{
    static int transport_2_Motor_current_C_original = 0;
    if(transport_2_Motor_current_C_original == iVal)
        return;
    transport_2_Motor_current_C_original = iVal;
    uiData.uiData_transport_2_Motor_current_C = iVal / 10.0;
    emit uiData_transport_2_Motor_current_CChanged();
}
void Ui::set_uiData_transport_2_Motor_current (int iVal)//电流
{
    static int transport_2_Motor_current_original = 0;
    if(transport_2_Motor_current_original == iVal)
        return;
    transport_2_Motor_current_original = iVal;
    uiData.uiData_transport_2_Motor_current = iVal / 10.0;
    emit uiData_transport_2_Motor_currentChanged();
}
void Ui::set_uiData_transport_2_Motor_wind_temp (int iVal)//绕组温度
{
    static int transport_2_Motor_wind_temp_original = 0;
    if(transport_2_Motor_wind_temp_original == iVal)
        return;
    transport_2_Motor_wind_temp_original = iVal;
    uiData.uiData_transport_2_Motor_wind_temp = iVal / 10.0;
    emit uiData_transport_2_Motor_wind_tempChanged();
}
void Ui::set_uiData_transport_2_Motor_AC_contractor_feedback_status (int iVal)//交流接触器反馈状态
{
    if(uiData.uiData_transport_2_Motor_AC_contractor_feedback_status == iVal)
        return;
    uiData.uiData_transport_2_Motor_AC_contractor_feedback_status = iVal;
    emit uiData_transport_2_Motor_AC_contractor_feedback_statusChanged();
}
//ModbusTCP数据的set函数


void Ui::RegreshViewData(PluginManager* pluginManager)
{
    pthread_t viewData_tid;
    int ret = pthread_create(&viewData_tid,nullptr,ViewDataRefreshThread,pluginManager);
    if(ret == 0)
        printf("ViewDataRefreshThread created successfully.\n" );
    else
        fprintf(stderr,"Failed to create ViewDataRefreshThread\n");
}

Ui* Ui::GetInstance()
{
    static Ui* ui = new Ui;
    return ui;
}
void* Ui::ViewDataRefreshThread(void *arg)
{
    GetInstance()->MapInit();
    PluginManager* pluginMain = (PluginManager*)arg;
    PluginInterface* controlPanelPlugin = static_cast<PluginInterface*>((pluginMain->getPluginList()).getPluginByName("ControlPanelPlugin"));
    PluginInterface* commMbTCPPlugin = static_cast<PluginInterface*>((pluginMain->getPluginList()).getPluginByName("CommMbTCPPlugin"));
    do
    {
        GetInstance()->frameRxData = (FrameRxData*)((commMbTCPPlugin->read("RECEIVE_DATA",0)).toLongLong());
    }while(!GetInstance()->frameRxData);
    while(1)
    {
        //获取操作箱数据
        GetInstance()->setCommStatus((controlPanelPlugin->read("SYS_COMM",0)).toInt());//获取通讯状态
        GetInstance()->setSpringBackCmd((controlPanelPlugin->read("KEY_CMD",0)).toInt());//获取指令信息
        GetInstance()->setCmdText(GetInstance()->GetText((controlPanelPlugin->read("KEY_CMD",0)).toInt()));//获取指令文本
        GetInstance()->setVersion(QString::fromUtf8((controlPanelPlugin->read("VERSION",0)).toByteArray()));//获取版本信息
        GetInstance()->setDataValidFlag((controlPanelPlugin->read("KEY_VALID_FLAG",0)).toInt());//获取按键有效性标识

        //ModbusTCP接收数据
        //_system    系统
        GetInstance()->set_uiData_system_data_valid_flag(GetInstance()->frameRxData->system_data_valid_flag);//数据有效标识
        GetInstance()->set_uiData_system_data_counter(GetInstance()->frameRxData->system_data_counter);//流水号
        GetInstance()->set_uiData_system_car_type(QString::fromUtf8(GetInstance()->frameRxData->system_car_type));//车型
        GetInstance()->set_uiData_system_car_number(QString::fromUtf8(GetInstance()->frameRxData->system_car_number));//车号
        GetInstance()->set_uiData_system_ctrl_mode(GetInstance()->frameRxData->system_ctrl_mode);//控制模式

        GetInstance()->set_uiData_system_auto_manual_cut_status(GetInstance()->frameRxData->system_auto_manual_cut_status);//自动或手动截割状态
        GetInstance()->set_uiData_system_system_voltage(GetInstance()->frameRxData->system_system_voltage);//系统电压
        GetInstance()->set_uiData_system_start_time(GetInstance()->frameRxData->system_start_time);//启动时间
        GetInstance()->set_uiData_system_remote_time(GetInstance()->frameRxData->system_remote_time);//远控时间
        GetInstance()->set_uiData_system_auto_cut_time(GetInstance()->frameRxData->system_auto_cut_time);//自动截割时间


        GetInstance()->set_uiData_system_scram(GetInstance()->frameRxData->system_scram);//急停状态
        GetInstance()->set_uiData_system_sensor_fault_info(GetInstance()->frameRxData->system_sensor_fault_info);//传感器、漏电、故障信息
        GetInstance()->set_uiData_system_hydraulic_pressure(GetInstance()->frameRxData->system_hydraulic_pressure);//液压压力

        GetInstance()->set_uiData_system_environment_temp(GetInstance()->frameRxData->system_environment_temp);//环境温度
        GetInstance()->set_uiData_system_environment_humidity(GetInstance()->frameRxData->system_environment_humidity);//环境湿度
        GetInstance()->set_uiData_system_gas_density(GetInstance()->frameRxData->system_gas_density);//瓦斯浓度
        GetInstance()->set_uiData_system_dust_density(GetInstance()->frameRxData->system_dust_density);//粉尘浓度
        GetInstance()->set_uiData_system_carbon_density(GetInstance()->frameRxData->system_carbon_density);//CO浓度

        GetInstance()->set_uiData_system_pumpOilMotor_work_status(GetInstance()->frameRxData->system_pumpOilMotor_work_status);//油泵工作状态
        GetInstance()->set_uiData_system_cut_motor_work_status(GetInstance()->frameRxData->system_cut_motor_work_status);//截割电机状态
        GetInstance()->set_uiData_system_transport_2_motor_work_status(GetInstance()->frameRxData->system_transport_2_motor_work_status);//二运状态
        GetInstance()->set_uiData_system_fan_motor_work_status(GetInstance()->frameRxData->system_fan_motor_work_status);//风机状态
        GetInstance()->set_uiData_system_lubrication_work_status(GetInstance()->frameRxData->system_lubrication_work_status);//润滑状态

        GetInstance()->set_uiData_system_waterPump_work_status(GetInstance()->frameRxData->system_waterPump_work_status);//水泵启停状态
        GetInstance()->set_uiData_system_spray_valve_work_status(GetInstance()->frameRxData->system_spray_valve_work_status);//喷雾阀状态
        GetInstance()->set_uiData_system_transport_1_motor_work_status(GetInstance()->frameRxData->system_transport_1_motor_work_status);//一运状态
        GetInstance()->set_uiData_system_shoveBlade_work_status(GetInstance()->frameRxData->system_shoveBlade_work_status);//铲板状态
        GetInstance()->set_uiData_system_rearSupport_work_status(GetInstance()->frameRxData->system_rearSupport_work_status);//后支撑状态

        GetInstance()->set_uiData_system_cutArm_rotation_status(GetInstance()->frameRxData->system_cutArm_rotation_status);//截割臂回转状态
        GetInstance()->set_uiData_system_cutArm_up_down_status(GetInstance()->frameRxData->system_cutArm_up_down_status);//截割臂升降状态
        GetInstance()->set_uiData_system_cutArm_push_pull_status(GetInstance()->frameRxData->system_cutArm_push_pull_status);//截割臂伸缩状态
        GetInstance()->set_uiData_system_left_tract_work_status(GetInstance()->frameRxData->system_left_tract_work_status);//左行走状态
        GetInstance()->set_uiData_system_right_tract_work_status(GetInstance()->frameRxData->system_right_tract_work_status);//右行走状态

        GetInstance()->set_uiData_system_star_wheel_motor_work_status(GetInstance()->frameRxData->system_star_wheel_motor_work_status);//星轮状态
        GetInstance()->set_uiData_system_left_star_wheel_motor_work_status(GetInstance()->frameRxData->system_left_star_wheel_motor_work_status);//左星轮状态
        GetInstance()->set_uiData_system_right_star_wheel_motor_work_status(GetInstance()->frameRxData->system_right_star_wheel_motor_work_status);//右星轮状态

        GetInstance()->set_uiData_system_fuel_tank_temp(GetInstance()->frameRxData->system_fuel_tank_temp);//油箱温度

        GetInstance()->set_uiData_system_fuel_tank_oil_level(GetInstance()->frameRxData->system_fuel_tank_oil_level);//油箱油位
        GetInstance()->set_uiData_system_cool_water_flow_calculate(GetInstance()->frameRxData->system_cool_water_flow_calculate);//冷却水流量
        GetInstance()->set_uiData_system_cool_water_pressure(GetInstance()->frameRxData->system_cool_water_pressure);//冷却水水压
        GetInstance()->set_uiData_system_fuselage_angle_X(GetInstance()->frameRxData->system_fuselage_angle_X);//机身倾角X
        GetInstance()->set_uiData_system_fuselage_angle_Y(GetInstance()->frameRxData->system_fuselage_angle_Y);//机身倾角Y

        GetInstance()->set_uiData_system_fuselage_angle_Z(GetInstance()->frameRxData->system_fuselage_angle_Z);//机身倾角Z
        GetInstance()->set_uiData_system_shoveBlade_angle_X(GetInstance()->frameRxData->system_shoveBlade_angle_X);//铲板X倾角
        GetInstance()->set_uiData_system_shoveBlade_angle_Y(GetInstance()->frameRxData->system_shoveBlade_angle_Y);//铲板Y倾角
        GetInstance()->set_uiData_system_shoveBlade_offset(GetInstance()->frameRxData->system_shoveBlade_offset);//铲板位移
        GetInstance()->set_uiData_system_cutArm_rotation_offset(GetInstance()->frameRxData->system_cutArm_rotation_offset);//截割臂回转位移

        GetInstance()->set_uiData_system_cutArm_up_down_offset(GetInstance()->frameRxData->system_cutArm_up_down_offset);//截割臂升降位移
        GetInstance()->set_uiData_system_cutArm_push_pull_offset(GetInstance()->frameRxData->system_cutArm_push_pull_offset);//截割臂伸缩位移
        GetInstance()->set_uiData_system_rearSupport_offset(GetInstance()->frameRxData->system_rearSupport_offset);//后支撑位移
        GetInstance()->set_uiData_system_back_car_pressure(GetInstance()->frameRxData->system_back_car_pressure);//倒车压力
        GetInstance()->set_uiData_system_rotation_1_pressure(GetInstance()->frameRxData->system_rotation_1_pressure);//回转压力1

        GetInstance()->set_uiData_system_rotation_2_pressure(GetInstance()->frameRxData->system_rotation_2_pressure);//回转压力2
        GetInstance()->set_uiData_system_up_down_1_pressure(GetInstance()->frameRxData->system_up_down_1_pressure);//升降压力1
        GetInstance()->set_uiData_system_up_down_2_pressure(GetInstance()->frameRxData->system_up_down_2_pressure);//升降压力2
        GetInstance()->set_uiData_system_push_pull_1_pressure(GetInstance()->frameRxData->system_push_pull_1_pressure);//伸缩压力1
        GetInstance()->set_uiData_system_push_pull_2_pressure(GetInstance()->frameRxData->system_push_pull_2_pressure);//伸缩压力2

        GetInstance()->set_uiData_system_left_forward_laser_distance(GetInstance()->frameRxData->system_left_forward_laser_distance);//左前激光测距

        GetInstance()->set_uiData_system_left_backward_laser_distance(GetInstance()->frameRxData->system_left_backward_laser_distance);//左后激光测距
        GetInstance()->set_uiData_system_right_forward_laser_distance(GetInstance()->frameRxData->system_right_forward_laser_distance);//右前激光测距
        GetInstance()->set_uiData_system_right_backward_laser_distance(GetInstance()->frameRxData->system_right_backward_laser_distance);//右后激光测距
        GetInstance()->set_uiData_system_person_detection(GetInstance()->frameRxData->system_person_detection);//人员检测

        GetInstance()->set_uiData_system_cut_motor_current(GetInstance()->frameRxData->system_cut_motor_current);//截割电机电流

        //HighCutMotor  截高电机
        GetInstance()->set_uiData_highCutMotor_work_status(GetInstance()->frameRxData->highCutMotor_work_status);//工作状态
        GetInstance()->set_uiData_highCutMotor_current_A(GetInstance()->frameRxData->highCutMotor_current_A);//A电流
        GetInstance()->set_uiData_highCutMotor_current_B(GetInstance()->frameRxData->highCutMotor_current_B);//B电流
        GetInstance()->set_uiData_highCutMotor_current_C(GetInstance()->frameRxData->highCutMotor_current_C);//C电流
        GetInstance()->set_uiData_highCutMotor_current(GetInstance()->frameRxData->highCutMotor_current);//电流
        GetInstance()->set_uiData_highCutMotor_wind_temp(GetInstance()->frameRxData->highCutMotor_wind_temp);//绕组温度
        GetInstance()->set_uiData_highCutMotor_AC_contractor_feedback_status(GetInstance()->frameRxData->highCutMotor_AC_contractor_feedback_status);//交流接触器反馈状态

        //LowCutMotor   截低电机
        GetInstance()->set_uiData_lowCutMotor_work_status(GetInstance()->frameRxData->lowCutMotor_work_status);//工作状态
        GetInstance()->set_uiData_lowCutMotor_current_A(GetInstance()->frameRxData->lowCutMotor_current_A);//A电流
        GetInstance()->set_uiData_lowCutMotor_current_B(GetInstance()->frameRxData->lowCutMotor_current_B);//B电流
        GetInstance()->set_uiData_lowCutMotor_current_C(GetInstance()->frameRxData->lowCutMotor_current_C);//C电流
        GetInstance()->set_uiData_lowCutMotor_current(GetInstance()->frameRxData->lowCutMotor_current);//电流
        GetInstance()->set_uiData_lowCutMotor_wind_temp(GetInstance()->frameRxData->lowCutMotor_wind_temp);//绕组温度
        GetInstance()->set_uiData_lowCutMotor_AC_contractor_feedback_status(GetInstance()->frameRxData->lowCutMotor_AC_contractor_feedback_status);//交流接触器反馈状态


        //FanMotor 风机
        GetInstance()->set_uiData_fanMotor_work_status(GetInstance()->frameRxData->fanMotor_work_status);//工作状态
        GetInstance()->set_uiData_fanMotor_current_A(GetInstance()->frameRxData->fanMotor_current_A);//A电流
        GetInstance()->set_uiData_fanMotor_current_B(GetInstance()->frameRxData->fanMotor_current_B);//B电流
        GetInstance()->set_uiData_fanMotor_current_C(GetInstance()->frameRxData->fanMotor_current_C);//C电流
        GetInstance()->set_uiData_fanMotor_current(GetInstance()->frameRxData->fanMotor_current);//电流
        GetInstance()->set_uiData_fanMotor_wind_temp(GetInstance()->frameRxData->fanMotor_wind_temp);//绕组温度
        GetInstance()->set_uiData_fanMotor_AC_contractor_feedback_status(GetInstance()->frameRxData->fanMotor_AC_contractor_feedback_status);//交流接触器反馈状态

        //pumpOilMotor  油泵电机
        GetInstance()->set_uiData_pumpOilMotor_work_status(GetInstance()->frameRxData->pumpOilMotor_work_status);//工作状态
        GetInstance()->set_uiData_pumpOilMotor_current_A(GetInstance()->frameRxData->pumpOilMotor_current_A);//A电流
        GetInstance()->set_uiData_pumpOilMotor_current_B(GetInstance()->frameRxData->pumpOilMotor_current_B);//B电流
        GetInstance()->set_uiData_pumpOilMotor_current_C(GetInstance()->frameRxData->pumpOilMotor_current_C);//C电流
        GetInstance()->set_uiData_pumpOilMotor_current(GetInstance()->frameRxData->pumpOilMotor_current);//电流
        GetInstance()->set_uiData_pumpOilMotor_wind_temp(GetInstance()->frameRxData->pumpOilMotor_wind_temp);//绕组温度
        GetInstance()->set_uiData_pumpOilMotor_AC_contractor_feedback_status(GetInstance()->frameRxData->pumpOilMotor_AC_contractor_feedback_status);//交流接触器反馈状态

        //transport2Motor
        GetInstance()->set_uiData_transport_2_Motor_work_status(GetInstance()->frameRxData->transport_2_Motor_work_status);//工作状态
        GetInstance()->set_uiData_transport_2_Motor_current_A(GetInstance()->frameRxData->transport_2_Motor_current_A);//A电流
        GetInstance()->set_uiData_transport_2_Motor_current_B(GetInstance()->frameRxData->transport_2_Motor_current_B);//B电流
        GetInstance()->set_uiData_transport_2_Motor_current_C(GetInstance()->frameRxData->transport_2_Motor_current_C);//C电流
        GetInstance()->set_uiData_transport_2_Motor_current(GetInstance()->frameRxData->transport_2_Motor_current);//电流
        GetInstance()->set_uiData_transport_2_Motor_wind_temp(GetInstance()->frameRxData->transport_2_Motor_wind_temp);//绕组温度
        GetInstance()->set_uiData_transport_2_Motor_AC_contractor_feedback_status(GetInstance()->frameRxData->transport_2_Motor_AC_contractor_feedback_status);//交流接触器反馈状态
        usleep(20000);
    }
}
QString Ui::GetText(const int num)
{
    QString temp = "";
    if((num > E_CMD_INVALID) || ( num < E_CMD_NONE))
    {
        temp = "错误";
        return temp;
    }
    auto it = mapDisplay.find(num);
    if(it != mapDisplay.end())
    {
       temp = QString::fromStdString(it->second);
    }
    else
        temp = "未定义";
    return temp;
}
void Ui::MapInit()
{
    //cmd[0]
    mapDisplay[E_CMD_NONE] = "无动作";
    mapDisplay[E_CMD_SCRAM] = "急停";
    mapDisplay[E_CMD_ALARM_BELL_START] = "警铃";
    mapDisplay[E_CMD_AUTO_CUT_INTERVENE] = "自动截割干预";
    mapDisplay[E_CMD_TRANSPORT_2_FWD] = "二运";
    mapDisplay[E_CMD_TRANSPORT_2_REV] = "二运反转";
    mapDisplay[E_CMD_CUT_HIGH_START] = "截高";
    mapDisplay[E_CMD_CUT_HIGH_STOP] = "截高停机";

    //cmd[1]
    mapDisplay[E_CMD_PICTURE_SWITCH] = "画面切换";
    mapDisplay[E_CMD_FULL_SCREEN_SITCH] = "全屏切换";
    mapDisplay[E_CMD_POWER_1_CLOSED] = "动力回路1闭合";
    mapDisplay[E_CMD_POWER_1_BREAK] = "动力回路1分开";
    mapDisplay[E_CMD_POWER_2_CLOSED] = "动力回路2闭合";
    mapDisplay[E_CMD_POWER_2_BREAK] = "动力回路2分开";
    mapDisplay[E_CMD_CUT_LOW_START] = "截低";
    mapDisplay[E_CMD_CUT_LOW_STOP] = "截低停机";


    //cmd[2]
    mapDisplay[E_CMD_POWER_3_CLOSED] = "动力回路3闭合";
    mapDisplay[E_CMD_POWER_3_BREAK] = "动力回路3分开";
    mapDisplay[E_CMD_DUST_REMOVAL_FAN_IN_WATER] = "除尘风机进水";
    mapDisplay[E_CMD_DUST_REMOVAL_FAN_START] = "除尘风机启动";
    mapDisplay[E_CMD_DUST_REMOVAL_FAN_STOP] = "除尘风机停止";
    mapDisplay[E_CMD_AIR_SUPPLY_FAN_START] = "送风风机启动";
    mapDisplay[E_CMD_AIR_SUPPLY_FAN_STOP] = "送风风机停止";
    mapDisplay[E_CMD_AUTO_CUT] = "自动截割";

    //cmd[3]
    mapDisplay[E_CMD_ONEKEY_START_TOP] = "一键启停";
    mapDisplay[E_CMD_SYSTEM_RESET] = "系统复位";
    mapDisplay[E_CMD_POWERON] = "开机";
    mapDisplay[E_CMD_SPADEBLADE_UP] = "铲板升";
    mapDisplay[E_CMD_SPADEBLADE_DOWN] = "铲板降";
    mapDisplay[E_CMD_BACK_SUPPORT_UP] = "后支撑升";
    mapDisplay[E_CMD_BACK_SUPPORT_DOWN] = "后支撑降";
    mapDisplay[E_CMD_FAN_START] = "风机";


    //cmd[4]
    mapDisplay[E_CMD_BELT_1_FWD] = "1号皮带正转";
    mapDisplay[E_CMD_BELT_1_REV] = "1号皮带反转";
    mapDisplay[E_CMD_BELT_2_FWD] = "2号皮带正转";
    mapDisplay[E_CMD_BELT_2_REV] = "2号皮带反转";
    mapDisplay[E_CMD_BELT_3_FWD] = "3号皮带正转";
    mapDisplay[E_CMD_BELT_3_REV] = "3号皮带反转";
    mapDisplay[E_CMD_FWD] = "正转";
    mapDisplay[E_CMD_REV] = "反转";

    //cmd[5]
    mapDisplay[E_CMD_LOCAL_SWITCH] = "地面切换";
    mapDisplay[E_CMD_PUMP_START] = "泵启动";
    mapDisplay[E_CMD_PUMP_STOP] = "泵停机";
    mapDisplay[E_CMD_RESET] = "复位";
    mapDisplay[E_CMD_OIL_PUMP_START] = "油泵";
    mapDisplay[E_CMD_OIL_PUMP_STOP] = "油泵停机";
    mapDisplay[E_CMD_STAR_WHEEL_FWD] = "星轮正转";
    mapDisplay[E_CMD_STAR_WHEEL_REV] = "星轮反转";

    //cmd[6]
    mapDisplay[E_CMD_AUTO_FORWARD] = "自动前进";
    mapDisplay[E_CMD_AUTO_BACKWARD] = "自动后退";
    mapDisplay[E_CMD_PUSHER_PUSH] = "推移伸";
    mapDisplay[E_CMD_PUSHER_PULL] = "推移收";
    mapDisplay[E_CMD_LEFT_SUPPORT_PUSH] = "左支撑伸";
    mapDisplay[E_CMD_LEFT_SUPPORT_PULL] = "左支撑收";
    mapDisplay[E_CMD_RIGHT_SUPPORT_PUSH] = "右支撑伸";
    mapDisplay[E_CMD_RIGHT_SUPPORT_PULL] = "右支撑收";

    //cmd[7]
    mapDisplay[E_CMD_SIDE_1_PUSH] = "侧移1伸";
    mapDisplay[E_CMD_SIDE_1_PULL] = "侧移1收";
    mapDisplay[E_CMD_SIDE_2_PUSH] = "侧移2伸";
    mapDisplay[E_CMD_SIDE_2_PULL] = "侧移2收";
    mapDisplay[E_CMD_SIDE_3_PUSH] = "侧移3伸";
    mapDisplay[E_CMD_SIDE_3_PULL] = "侧移3收";
    mapDisplay[E_CMD_CUT_UP] = "截割伸";
    mapDisplay[E_CMD_CUT_DOWN] = "截割缩";

    //cmd[8]
    mapDisplay[E_CMD_SPARE_1] = "备用1";
    mapDisplay[E_CMD_SPARE_2] = "备用2";
    mapDisplay[E_CMD_SPARE_3] = "备用3";
    mapDisplay[E_CMD_SPARE_4] = "备用4";
    mapDisplay[E_CMD_TRANSPORT_1_FWD] = "一运正转";
    mapDisplay[E_CMD_TRANSPORT_1_REV] = "一运反转";
    mapDisplay[E_CMD_WATER_PUMP_START] = "水泵";
    mapDisplay[E_CMD_WATER_PUMP_STOP] = "水泵停机";

    //cmd[9]
    mapDisplay[E_CMD_LEFT_TRACT_UP] = "左履带前进";
    mapDisplay[E_CMD_LEFT_TRACT_DOWN] = "左履带后退";
    mapDisplay[E_CMD_RIGHT_TRACT_UP] = "右履带前进";
    mapDisplay[E_CMD_RIGHT_TRACT_DOWN] = "右履带后退";
    mapDisplay[E_CMD_CUT_HEAD_UP] = "截割升";
    mapDisplay[E_CMD_CUT_HEAD_DOWN] = "截割降";
    mapDisplay[E_CMD_CUT_HEAD_LEFT] = "截割左";
    mapDisplay[E_CMD_CUT_HEAD_RIGHT] = "截割右";

    //cmd[10]
    mapDisplay[E_CMD_SPARE_5] = "备用5";
    mapDisplay[E_CMD_SPARE_6] = "备用6";
    mapDisplay[E_CMD_SPARE_7] = "备用7";
    mapDisplay[E_CMD_SPARE_8] = "备用8";
    mapDisplay[E_CMD_RMT_CTRL] = "遥控";
    mapDisplay[E_CMD_REMOTE_CRTL] = "远控";
    mapDisplay[E_CMD_BACK_SUPPLY] = "备用/支护";
    mapDisplay[E_CMD_LUBRICATION] = "润滑";

    //cmd[11]
    mapDisplay[E_CMD_ANCHOR_RMT_CTRL] = "锚杆遥控";
    mapDisplay[E_CMD_ANCHOR_SUPPLY] = "锚支";
    mapDisplay[E_CMD_1_FAN] = "1号风机";
    mapDisplay[E_CMD_2_FAN] = "2号风机";
    mapDisplay[E_CMD_PAGE_UP] = "上翻页";
    mapDisplay[E_CMD_PAGE_DOWN] = "下翻页";
    mapDisplay[E_CMD_UP] = "上";
    mapDisplay[E_CMD_DOWN] = "下";


    //cmd[12]
    mapDisplay[E_CMD_ADD] = "加";
    mapDisplay[E_CMD_SUBTRAC] = "减";
    mapDisplay[E_CMD_CONFIRM] = "确认";
    mapDisplay[E_CMD_GO_BACK] = "返回";

    mapDisplay[E_CMD_INVALID] = "无效指令";
}
