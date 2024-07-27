#ifndef UI_H
#define UI_H
#include "tools/pluginmanager/pluginmanager.h"
#include "tools/plugininterface/plugininterface.h"
#include <QObject>
#include <string>
#include <map>
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
    Q_PROPERTY(int uiData_system_ctrl_mode READ get_uiData_system_ctrl_mode WRITE set_uiData_system_ctrl_mode NOTIFY uiData_system_ctrl_modeChanged)//控制模式

    Q_PROPERTY(int uiData_system_auto_manual_cut_status READ get_uiData_system_auto_manual_cut_status WRITE set_uiData_system_auto_manual_cut_status NOTIFY uiData_system_auto_manual_cut_statusChanged)//自动或手动截割状态
    Q_PROPERTY(float uiData_system_system_voltage READ get_uiData_system_system_voltage WRITE set_uiData_system_system_voltage NOTIFY uiData_system_system_voltageChanged)//系统电压
    Q_PROPERTY(float uiData_system_start_time READ get_uiData_system_start_time WRITE set_uiData_system_start_time NOTIFY uiData_system_start_timeChanged)//启动时间
    Q_PROPERTY(float uiData_system_remote_time READ get_uiData_system_remote_time WRITE set_uiData_system_remote_time NOTIFY uiData_system_remote_timeChanged)//远控时间
    Q_PROPERTY(float uiData_system_auto_cut_time READ get_uiData_system_auto_cut_time WRITE set_uiData_system_auto_cut_time NOTIFY uiData_system_auto_cut_timeChanged)//自动截割时间

    Q_PROPERTY(int uiData_system_scram READ get_uiData_system_scram WRITE set_uiData_system_scram NOTIFY uiData_system_scramChanged)//急停状态

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
    Q_INVOKABLE void set_uiData_system_ctrl_mode (int iVal);//控制模式

    Q_INVOKABLE void set_uiData_system_auto_manual_cut_status (int iVal);//自动或手动截割状态
    Q_INVOKABLE void set_uiData_system_system_voltage (int iVal);//系统电压
    Q_INVOKABLE void set_uiData_system_start_time (int iVal);//启动时间
    Q_INVOKABLE void set_uiData_system_remote_time (int iVal);//远控时间
    Q_INVOKABLE void set_uiData_system_auto_cut_time (int iVal);//自动截割时间


    Q_INVOKABLE void set_uiData_system_scram (int iVal);//急停状态
    //_system    系统
    Q_INVOKABLE int get_uiData_system_ctrl_mode() const{return uiData.uiData_system_ctrl_mode;}//控制模式

    Q_INVOKABLE int get_uiData_system_auto_manual_cut_status() const{return uiData.uiData_system_auto_manual_cut_status;}//自动或手动截割状态
    Q_INVOKABLE float get_uiData_system_system_voltage() const{return uiData.uiData_system_system_voltage;}//系统电压
    Q_INVOKABLE float get_uiData_system_start_time() const{return uiData.uiData_system_start_time;}//启动时间
    Q_INVOKABLE float get_uiData_system_remote_time() const{return uiData.uiData_system_remote_time;}//远控时间
    Q_INVOKABLE float get_uiData_system_auto_cut_time() const{return uiData.uiData_system_auto_cut_time;}//自动截割时间

    Q_INVOKABLE int get_uiData_system_scram() const{return uiData.uiData_system_scram;}//急停状态
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
    void uiData_system_ctrl_modeChanged();//控制模式

    void uiData_system_auto_manual_cut_statusChanged();//自动或手动截割状态
    void uiData_system_system_voltageChanged();//系统电压
    void uiData_system_start_timeChanged();//启动时间
    void uiData_system_remote_timeChanged();//远控时间
    void uiData_system_auto_cut_timeChanged();//自动截割时间

    void uiData_system_scramChanged();//急停状态
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
