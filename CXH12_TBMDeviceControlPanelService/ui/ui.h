#ifndef UI_H
#define UI_H
#include "tools/pluginmanager/pluginmanager.h"
#include "tools/plugininterface/plugininterface.h"
#include <QObject>
#include <map>
#include <string>
using namespace std;
//需要和ModbusTCP保持一致
typedef struct
{
    int8_t                               dataType;           // 0 uint16_t 1 int16_t 2 char
    int16_t                              calculationMethod;  // 0 无需计算  1 缩放  2 数据匹配
    float                                scale;              // 缩放比例 默认为1
    std::string                          unit;               // 单位
    std::map<std::uint16_t, std::string> infoMap;            //{{0,"停止"},{1,"运行"}，{9,"故障"}}

} SDataInfo;

typedef struct
{
    uint16_t addr;
    uint16_t bitAddr;  // 按位取值  0xFFFF表示整个数据
    union
    {
        int16_t  i;
        uint16_t ui;
        char     str[2];
    } data;
    std::string dataName;
    SDataInfo   info;

    std::string outStr;

} SRegisterInfo;

std::map<std::string, SRegisterInfo> FrameRxData;

typedef struct 
{
    uint16_t addr;
    uint16_t bitAddr;
    std::string outStr;
}UiDataInfo;

std::map<std::string, UiDataInfo> UiData;

    UiData["system_ctrl_mode"] = {40, 0xFFFF, ""};
    UiData["system_auto_manual_cut_status"] = {41, 0xFFFF, ""};
    UiData["system_system_voltage"] = {42, 0xFFFF, ""};
    UiData["uiData_system_start_time"] = {43, 0xFFFF, ""};
    UiData["uiData_system_remote_time"] = {44, 0xFFFF, ""};
    UiData["system_auto_cut_time"] = {45, 0xFFFF, ""};
    UiData["system_scram"] = {46, 0xFFFF, ""};

#define UI_DATA_PROPERTY(name) \
    Q_PROPERTY(QString uiData_##name READ get_uiData_##name WRITE set_uiData_##name NOTIFY uiData_##name##Changed) \
    Q_INVOKABLE QString get_uiData_##name() const { return get_uiData(#name); } \
    Q_INVOKABLE void set_uiData_##name(const QString &value) { set_uiData(#name, value); } \
    void uiData_##name##Changed();
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
    UI_DATA_PROPERTY(system_data_valid_flag)
    UI_DATA_PROPERTY(system_ctrl_mode)
    UI_DATA_PROPERTY(system_auto_manual_cut_status)
    UI_DATA_PROPERTY(system_system_voltage)
    UI_DATA_PROPERTY(system_start_time)
    UI_DATA_PROPERTY(system_remote_time)
    UI_DATA_PROPERTY(system_auto_cut_time)
    UI_DATA_PROPERTY(system_scram)
    UI_DATA_PROPERTY(system_sensor_fault_info)
    UI_DATA_PROPERTY(system_hydraulic_pressure)
    UI_DATA_PROPERTY(system_environment_temp)
    UI_DATA_PROPERTY(system_environment_humidity)
    UI_DATA_PROPERTY(system_gas_density)
    UI_DATA_PROPERTY(system_dust_density)
    UI_DATA_PROPERTY(system_carbon_density)
    UI_DATA_PROPERTY(system_pumpOilMotor_work_status)
    UI_DATA_PROPERTY(system_cut_motor_work_status)
    UI_DATA_PROPERTY(system_transport_2_motor_work_status)
    UI_DATA_PROPERTY(system_fan_motor_work_status)
    UI_DATA_PROPERTY(system_lubrication_work_status)
    UI_DATA_PROPERTY(system_waterPump_work_status)
    UI_DATA_PROPERTY(system_spray_valve_work_status)
    UI_DATA_PROPERTY(system_transport_1_motor_work_status)
    UI_DATA_PROPERTY(system_shoveBlade_work_status)
    UI_DATA_PROPERTY(system_rearSupport_work_status)
    UI_DATA_PROPERTY(system_cutArm_rotation_status)
    UI_DATA_PROPERTY(system_cutArm_up_down_status)
    UI_DATA_PROPERTY(system_cutArm_push_pull_status)
    UI_DATA_PROPERTY(system_left_tract_work_status)
    UI_DATA_PROPERTY(system_right_tract_work_status)
    UI_DATA_PROPERTY(system_star_wheel_motor_work_status)
    UI_DATA_PROPERTY(system_left_star_wheel_motor_work_status)
    UI_DATA_PROPERTY(system_right_star_wheel_motor_work_status)
    UI_DATA_PROPERTY(system_fuel_tank_temp)
    UI_DATA_PROPERTY(system_fuel_tank_oil_level)
    UI_DATA_PROPERTY(system_cool_water_flow_calculate)
    UI_DATA_PROPERTY(system_cool_water_pressure)
    UI_DATA_PROPERTY(system_fuselage_angle_X)
    UI_DATA_PROPERTY(system_fuselage_angle_Y)
    UI_DATA_PROPERTY(system_fuselage_angle_Z)
    UI_DATA_PROPERTY(system_shoveBlade_angle_X)
    UI_DATA_PROPERTY(system_shoveBlade_angle_Y)
    UI_DATA_PROPERTY(system_shoveBlade_offset)
    UI_DATA_PROPERTY(system_cutArm_rotation_offset)
    UI_DATA_PROPERTY(system_cutArm_up_down_offset)
    UI_DATA_PROPERTY(system_cutArm_push_pull_offset)
    UI_DATA_PROPERTY(system_rearSupport_offset)
    UI_DATA_PROPERTY(system_back_car_pressure)
    UI_DATA_PROPERTY(system_rotation_1_pressure)
    UI_DATA_PROPERTY(system_rotation_2_pressure)
    UI_DATA_PROPERTY(system_up_down_1_pressure)
    UI_DATA_PROPERTY(system_up_down_2_pressure)
    UI_DATA_PROPERTY(system_push_pull_1_pressure)
    UI_DATA_PROPERTY(system_push_pull_2_pressure)
    UI_DATA_PROPERTY(system_left_forward_laser_distance)
    UI_DATA_PROPERTY(system_left_backward_laser_distance)
    UI_DATA_PROPERTY(system_right_forward_laser_distance)
    UI_DATA_PROPERTY(system_right_backward_laser_distance)
    UI_DATA_PROPERTY(system_person_detection)
    UI_DATA_PROPERTY(system_cut_motor_current)
    UI_DATA_PROPERTY(highCutMotor_work_status)
    UI_DATA_PROPERTY(highCutMotor_current_A)
    UI_DATA_PROPERTY(highCutMotor_current_B)
    UI_DATA_PROPERTY(highCutMotor_current_C)
    UI_DATA_PROPERTY(highCutMotor_current)
    UI_DATA_PROPERTY(highCutMotor_wind_temp)
    UI_DATA_PROPERTY(highCutMotor_AC_contractor_feedback_status)
    UI_DATA_PROPERTY(lowCutMotor_work_status)
    UI_DATA_PROPERTY(lowCutMotor_current_A)
    UI_DATA_PROPERTY(lowCutMotor_current_B)
    UI_DATA_PROPERTY(lowCutMotor_current_C)
    UI_DATA_PROPERTY(lowCutMotor_current)
    UI_DATA_PROPERTY(lowCutMotor_wind_temp)
    UI_DATA_PROPERTY(lowCutMotor_AC_contractor_feedback_status)
    UI_DATA_PROPERTY(fanMotor_work_status)
    UI_DATA_PROPERTY(fanMotor_current_A)
    UI_DATA_PROPERTY(fanMotor_current_B)
    UI_DATA_PROPERTY(fanMotor_current_C)
    UI_DATA_PROPERTY(fanMotor_current)
    UI_DATA_PROPERTY(fanMotor_wind_temp)
    UI_DATA_PROPERTY(fanMotor_AC_contractor_feedback_status)
    UI_DATA_PROPERTY(pumpOilMotor_work_status)
    UI_DATA_PROPERTY(pumpOilMotor_current_A)
    UI_DATA_PROPERTY(pumpOilMotor_current_B)
    UI_DATA_PROPERTY(pumpOilMotor_current_C)
    UI_DATA_PROPERTY(pumpOilMotor_current)
    UI_DATA_PROPERTY(pumpOilMotor_wind_temp)
    UI_DATA_PROPERTY(pumpOilMotor_AC_contractor_feedback_status)
    UI_DATA_PROPERTY(transport_2_Motor_work_status)
    UI_DATA_PROPERTY(transport_2_Motor_current_A)
    UI_DATA_PROPERTY(transport_2_Motor_current_B)
    UI_DATA_PROPERTY(transport_2_Motor_current_C)
    UI_DATA_PROPERTY(transport_2_Motor_current)
    UI_DATA_PROPERTY(transport_2_Motor_wind_temp)
    UI_DATA_PROPERTY(transport_2_Motor_AC_contractor_feedback_status)

    Q_INVOKABLE QString get_uiData(const QString &key) const {
        auto it = uiData.find(key.toStdString());
        if (it != uiData.end()) {
            return QString::fromStdString(it->second.outStr);
        }
        return QString();
    }

    Q_INVOKABLE void set_uiData(const QString &key, const QString &value) {
        auto it = uiData.find(key.toStdString());
        if (it != uiData.end()) {
            if (it->second.outStr == value.toStdString())
                return;
            it->second.outStr = value.toStdString();
            emit_uiDataChanged(key);
        }
    }

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
    void emit_uiDataChanged(const QString &key) {
        static const std::map<QString, void (Ui::*)()> signalMap = {
            {"uiData_system_data_valid_flag", &Ui::uiData_system_data_valid_flagChanged},
            {"system_ctrl_mode", &Ui::uiData_system_ctrl_modeChanged},
            {"system_auto_manual_cut_status", &Ui::uiData_system_auto_manual_cut_statusChanged},
            {"system_system_voltage", &Ui::uiData_system_system_voltageChanged},
            {"system_start_time", &Ui::uiData_system_start_timeChanged},
            {"system_remote_time", &Ui::uiData_system_remote_timeChanged},
            {"system_auto_cut_time", &Ui::uiData_system_auto_cut_timeChanged},
            {"system_scram", &Ui::uiData_system_scramChanged},
            {"system_sensor_fault_info", &Ui::uiData_system_sensor_fault_infoChanged},
            {"system_hydraulic_pressure", &Ui::uiData_system_hydraulic_pressureChanged},
            {"system_environment_temp", &Ui::uiData_system_environment_tempChanged},
            {"system_environment_humidity", &Ui::uiData_system_environment_humidityChanged},
            {"system_gas_density", &Ui::uiData_system_gas_densityChanged},
            {"system_dust_density", &Ui::uiData_system_dust_densityChanged},
            {"system_carbon_density", &Ui::uiData_system_carbon_densityChanged},
            {"system_pumpOilMotor_work_status", &Ui::uiData_system_pumpOilMotor_work_statusChanged},
            {"system_cut_motor_work_status", &Ui::uiData_system_cut_motor_work_statusChanged},
            {"system_transport_2_motor_work_status", &Ui::uiData_system_transport_2_motor_work_statusChanged},
            {"system_fan_motor_work_status", &Ui::uiData_system_fan_motor_work_statusChanged},
            {"system_lubrication_work_status", &Ui::uiData_system_lubrication_work_statusChanged},
            {"system_waterPump_work_status", &Ui::uiData_system_waterPump_work_statusChanged},
            {"system_spray_valve_work_status", &Ui::uiData_system_spray_valve_work_statusChanged},
            {"system_transport_1_motor_work_status", &Ui::uiData_system_transport_1_motor_work_statusChanged},
            {"system_shoveBlade_work_status", &Ui::uiData_system_shoveBlade_work_statusChanged},
            {"system_rearSupport_work_status", &Ui::uiData_system_rearSupport_work_statusChanged},
            {"system_cutArm_rotation_status", &Ui::uiData_system_cutArm_rotation_statusChanged},
            {"system_cutArm_up_down_status", &Ui::uiData_system_cutArm_up_down_statusChanged},
            {"system_cutArm_push_pull_status", &Ui::uiData_system_cutArm_push_pull_statusChanged},
            {"system_left_tract_work_status", &Ui::uiData_system_left_tract_work_statusChanged},
            {"system_right_tract_work_status", &Ui::uiData_system_right_tract_work_statusChanged},
            {"system_star_wheel_motor_work_status", &Ui::uiData_system_star_wheel_motor_work_statusChanged},
            {"system_left_star_wheel_motor_work_status", &Ui::uiData_system_left_star_wheel_motor_work_statusChanged},
            {"system_right_star_wheel_motor_work_status", &Ui::uiData_system_right_star_wheel_motor_work_statusChanged},
            {"system_fuel_tank_temp", &Ui::uiData_system_fuel_tank_tempChanged},
            {"system_fuel_tank_oil_level", &Ui::uiData_system_fuel_tank_oil_levelChanged},
            {"system_cool_water_flow_calculate", &Ui::uiData_system_cool_water_flow_calculateChanged},
            {"system_cool_water_pressure", &Ui::uiData_system_cool_water_pressureChanged},
            {"system_fuselage_angle_X", &Ui::uiData_system_fuselage_angle_XChanged},
            {"system_fuselage_angle_Y", &Ui::uiData_system_fuselage_angle_YChanged},
            {"system_fuselage_angle_Z", &Ui::uiData_system_fuselage_angle_ZChanged},
            {"system_shoveBlade_angle_X", &Ui::uiData_system_shoveBlade_angle_XChanged},
            {"system_shoveBlade_angle_Y", &Ui::uiData_system_shoveBlade_angle_YChanged},
            {"system_shoveBlade_offset", &Ui::uiData_system_shoveBlade_offsetChanged},
            {"system_cutArm_rotation_offset", &Ui::uiData_system_cutArm_rotation_offsetChanged},
            {"system_cutArm_up_down_offset", &Ui::uiData_system_cutArm_up_down_offsetChanged},
            {"system_cutArm_push_pull_offset", &Ui::uiData_system_cutArm_push_pull_offsetChanged},
            {"system_rearSupport_offset", &Ui::uiData_system_rearSupport_offsetChanged},
            {"system_back_car_pressure", &Ui::uiData_system_back_car_pressureChanged},
            {"system_rotation_1_pressure", &Ui::uiData_system_rotation_1_pressureChanged},
            {"system_rotation_2_pressure", &Ui::uiData_system_rotation_2_pressureChanged},
            {"system_up_down_1_pressure", &Ui::uiData_system_up_down_1_pressureChanged},
            {"system_up_down_2_pressure", &Ui::uiData_system_up_down_2_pressureChanged},
            {"system_push_pull_1_pressure", &Ui::uiData_system_push_pull_1_pressureChanged},
            {"system_push_pull_2_pressure", &Ui::uiData_system_push_pull_2_pressureChanged},
            {"system_left_forward_laser_distance", &Ui::uiData_system_left_forward_laser_distanceChanged},
            {"system_left_backward_laser_distance", &Ui::uiData_system_left_backward_laser_distanceChanged},
            {"system_right_forward_laser_distance", &Ui::uiData_system_right_forward_laser_distanceChanged},
            {"system_right_backward_laser_distance", &Ui::uiData_system_right_backward_laser_distanceChanged},
            {"system_person_detection", &Ui::uiData_system_person_detectionChanged},
            {"system_cut_motor_current", &Ui::uiData_system_cut_motor_currentChanged},
            {"highCutMotor_work_status", &Ui::uiData_highCutMotor_work_statusChanged},
            {"highCutMotor_current_A", &Ui::uiData_highCutMotor_current_AChanged},
            {"highCutMotor_current_B", &Ui::uiData_highCutMotor_current_BChanged},
            {"highCutMotor_current_C", &Ui::uiData_highCutMotor_current_CChanged},
            {"highCutMotor_current", &Ui::uiData_highCutMotor_currentChanged},
            {"highCutMotor_wind_temp", &Ui::uiData_highCutMotor_wind_tempChanged},
            {"highCutMotor_AC_contractor_feedback_status", &Ui::uiData_highCutMotor_AC_contractor_feedback_statusChanged},
            {"lowCutMotor_work_status", &Ui::uiData_lowCutMotor_work_statusChanged},
            {"lowCutMotor_current_A", &Ui::uiData_lowCutMotor_current_AChanged},
            {"lowCutMotor_current_B", &Ui::uiData_lowCutMotor_current_BChanged},
            {"lowCutMotor_current_C", &Ui::uiData_lowCutMotor_current_CChanged},
            {"lowCutMotor_current", &Ui::uiData_lowCutMotor_currentChanged},
            {"lowCutMotor_wind_temp", &Ui::uiData_lowCutMotor_wind_tempChanged},
            {"lowCutMotor_AC_contractor_feedback_status", &Ui::uiData_lowCutMotor_AC_contractor_feedback_statusChanged},
            {"fanMotor_work_status", &Ui::uiData_fanMotor_work_statusChanged},
            {"fanMotor_current_A", &Ui::uiData_fanMotor_current_AChanged},
            {"fanMotor_current_B", &Ui::uiData_fanMotor_current_BChanged},
            {"fanMotor_current_C", &Ui::uiData_fanMotor_current_CChanged},
            {"fanMotor_current", &Ui::uiData_fanMotor_currentChanged},
            {"fanMotor_wind_temp", &Ui::uiData_fanMotor_wind_tempChanged},
            {"fanMotor_AC_contractor_feedback_status", &Ui::uiData_fanMotor_AC_contractor_feedback_statusChanged},
            {"pumpOilMotor_work_status", &Ui::uiData_pumpOilMotor_work_statusChanged},
            {"pumpOilMotor_current_A", &Ui::uiData_pumpOilMotor_current_AChanged},
            {"pumpOilMotor_current_B", &Ui::uiData_pumpOilMotor_current_BChanged},
            {"pumpOilMotor_current_C", &Ui::uiData_pumpOilMotor_current_CChanged},
            {"pumpOilMotor_current", &Ui::uiData_pumpOilMotor_currentChanged},
            {"pumpOilMotor_wind_temp", &Ui::uiData_pumpOilMotor_wind_tempChanged},
            {"pumpOilMotor_AC_contractor_feedback_status", &Ui::uiData_pumpOilMotor_AC_contractor_feedback_statusChanged},
            {"transport_2_Motor_work_status", &Ui::uiData_transport_2_Motor_work_statusChanged},
            {"transport_2_Motor_current_A", &Ui::uiData_transport_2_Motor_current_AChanged},
            {"transport_2_Motor_current_B", &Ui::uiData_transport_2_Motor_current_BChanged},
            {"transport_2_Motor_current_C", &Ui::uiData_transport_2_Motor_current_CChanged},
            {"transport_2_Motor_current", &Ui::uiData_transport_2_Motor_currentChanged},
            {"transport_2_Motor_wind_temp", &Ui::uiData_transport_2_Motor_wind_tempChanged},
            {"transport_2_Motor_AC_contractor_feedback_status", &Ui::uiData_transport_2_Motor_AC_contractor_feedback_statusChanged},
            // Add other mappings here
        };
        auto it = signalMap.find(key);
        if (it != signalMap.end()) {
            (this->*(it->second))();
        }
    }



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
    // FrameRxData* frameRxData;//ModbusTCP获取数据
    // UiData uiData;//Ui显示数据
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
