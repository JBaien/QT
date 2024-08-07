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
        GetInstance()->set_uiData_system_ctrl_mode(GetInstance()->frameRxData->system_ctrl_mode);//控制模式

        GetInstance()->set_uiData_system_auto_manual_cut_status(GetInstance()->frameRxData->system_auto_manual_cut_status);//自动或手动截割状态
        GetInstance()->set_uiData_system_system_voltage(GetInstance()->frameRxData->system_system_voltage);//系统电压
        GetInstance()->set_uiData_system_start_time(GetInstance()->frameRxData->system_start_time);//启动时间
        GetInstance()->set_uiData_system_remote_time(GetInstance()->frameRxData->system_remote_time);//远控时间
        GetInstance()->set_uiData_system_auto_cut_time(GetInstance()->frameRxData->system_auto_cut_time);//自动截割时间


        GetInstance()->set_uiData_system_scram(GetInstance()->frameRxData->system_scram);//急停状态
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
