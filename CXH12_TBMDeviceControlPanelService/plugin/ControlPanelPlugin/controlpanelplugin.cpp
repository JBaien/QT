#include "controlpanelplugin.h"
#include "tools/HashString/HashString.h"
#include <unistd.h>
#include <mutex>
#include <ctime>
std::mutex CommMutex;//通信值互斥锁
std::mutex ControlPanelReadMutex;//操作台读取
ControlPanelPlugin::ControlPanelPlugin()
{
    system_string_time = "Wed Jul  3 14:01:40 CST 2024";
    system_int_time = 0;
    system_version = "Ver:1.0.0.20240401";
    system_status_ID = 0;
    system_error_message = "";
    system_comm_status = 0;
    back_key = 0;
    not_back_key = 0;
    key = 0;
    key_command = E_CMD_NONE;
    key_value_valid_falg = 1;
    memset(&rock_original_value,0,sizeof(Rock_t));
    memset(&rock_calibration_value,0,sizeof(Rock_t));
}
ControlPanelPlugin::~ControlPanelPlugin()
{
    qDebug() << "ControlPanelPlugin::~ControlPanelPlugin() is called";
}

uint8_t ControlPanelPlugin::CmdResolve(const uint64_t& switchCmd,const Rock_t& rock)
{
    Ecmd cmd = E_CMD_NONE;
    if(switchCmd & SCRAM)//急停未操作
    {
        uint32_t switchCmd1= (uint32_t)(switchCmd & 0x00000000ffffffff);//自锁定开关
        uint32_t switchCmd2 = (uint32_t)(switchCmd >> 32);//回弹开关
        //自锁定型开关指令解析
        if(switchCmd1 & RMT_CTRL)//遥控
            cmd = E_CMD_RMT_CTRL;
        if(switchCmd1 & REMOTE_CTRL)//远控
            cmd = E_CMD_REMOTE_CTRL;
        if(switchCmd1 & AUTO_CUT)//自动截割
            cmd = E_CMD_AUTO_CUT;
        if(switchCmd1 & BACK_SUPPLY)//备用/支护
            cmd = E_CMD_BACK_SUPPLY;
        if(switchCmd1 & ANCHOR_RMT_CTRL)//锚杆遥控
            cmd = E_CMD_ANCHOR_RMT_CTRL;
        if(switchCmd1 & ANCHOR_SUPPLY)//锚支
            cmd = E_CMD_ANCHOR_SUPPLY;

        //回弹型开关指令解析
        if(switchCmd2 & RESET)//复位
            cmd =E_CMD_RESET;
        if(switchCmd2 & POWER_ON)//开机
            cmd =E_CMD_POWER_ON;
        if(switchCmd2 & ALARM_BELL_START)//警铃
            cmd =E_CMD_ALARM_BELL_START;
        if(switchCmd2 & LUBRICATION)//润滑
            cmd =E_CMD_LUBRICATION;
        if(switchCmd2 & AUTO_CUT_INTERVENE)//截割干预
            cmd =E_CMD_AUTO_CUT_INTERVENE;
        if(switchCmd2 & OIL_PUMP_START)//油泵
            cmd =E_CMD_OIL_PUMP_START;
        if(switchCmd2 & TRANSPORT_2_FWD)//二运
            cmd =E_CMD_TRANSPORT_2_FWD;
        if(switchCmd2 & CUT_HIGH_START)//截高
            cmd =E_CMD_CUT_HIGH_START;
        if(switchCmd2 & CUT_LOW_START)//截低
            cmd =E_CMD_CUT_LOW_START;
        if(switchCmd2 & FIRST_1_FAN)//风机1
            cmd =E_CMD_1_FAN;
        if(switchCmd2 & SECOND_2_FAN)//风机2
            cmd =E_CMD_2_FAN;
        if(switchCmd2 & PAGE_UP)//上翻页
            cmd =E_CMD_PAGE_UP;
        if(switchCmd2 & PAGE_DOWN)//下翻页
            cmd =E_CMD_PAGE_DOWN;
        if(switchCmd2 & UP)//上
            cmd =E_CMD_UP;
        if(switchCmd2 & DOWN)//下
            cmd =E_CMD_DOWN;
        if(switchCmd2 & ADD)//加
            cmd =E_CMD_ADD;
        if(switchCmd2 & SUBTRAC)//减
            cmd =E_CMD_SUBTRAC;
        if(switchCmd2 & CONFIRM)//确认
            cmd =E_CMD_CONFIRM;
        if(switchCmd2 & GO_BACK)//返回
            cmd =E_CMD_GO_BACK;

    }
    else
        cmd = E_CMD_SCRAM;
    return cmd;
}
uint8_t ControlPanelPlugin::RockCalibration(const int& originalValue,int minValue,int midMinValue,int midMaxValue,int maxValue,uint8_t type)
{
    if(type)//正向获取，随模拟量的增大而增大
    {
        if(originalValue <= minValue){
            return 0x00;
        }else if(originalValue <= midMinValue){
            return (uint8_t)((float)(originalValue - minValue) / (float)(midMinValue - minValue) * 0x80);
        }else if(originalValue <= midMaxValue){
            return 0x80;
        }else if(originalValue <= maxValue){
            return (uint8_t)(((float)(originalValue - midMaxValue) / (float)(maxValue - midMaxValue) * 0x80) + 0x7f);
        }else{
            return 0xFF;
        }
    }
    else//反向获取，随模拟量的增大而减小
    {
        if(originalValue <= minValue){
            return 0xFF;
        }else if(originalValue <= midMinValue){
            return (uint8_t)((1.0 - (float)(originalValue - minValue) / (float)(midMinValue - minValue)) * 0x80 + 0x7f);
        }else if(originalValue <= midMaxValue){
            return 0x80;
        }else if(originalValue <= maxValue){
            return (uint8_t)(((1 - (float)(originalValue - midMaxValue) / (float)(maxValue - midMaxValue)) * 0x80));
        }else{
            return 0x00;
        }
    }

}
bool ControlPanelPlugin::DataValidityDetection(const uint64_t& switchCmd)//数据有效性检测，有效返回1,无效返回0
{
    bool dataValidityFlag = 1;
    static uint32_t sysStartCounter = 0;
    static bool scramClickOrNotFlag = 0;//急停按下又恢复
    uint32_t switchCmd1 = switchCmd & 0x00000000ffffffff;//自锁定开关
    /*急停处理*/
    if(switchCmd1 & SCRAM)
        switchCmd1 = switchCmd1 & 0xfffffffe;
    else
        switchCmd1 = switchCmd1 | 0x01;

    //上电启动
    if(!sysStartCounter)
    {
        if(switchCmd1)
        {
            dataValidityFlag = 0;
            return dataValidityFlag;
        }
        else
        {
            ++sysStartCounter;
            dataValidityFlag = 1;
            return dataValidityFlag;
        }
    }
    if(switchCmd1 & SCRAM)//急停按下
    {
        //数据一直有效
        scramClickOrNotFlag = 1;
    }
    else
    {
        if(scramClickOrNotFlag)//按下又松开
        {
            if(switchCmd1)
            {
                dataValidityFlag = 0;
                return dataValidityFlag;
            }
            else
            {
                scramClickOrNotFlag = 0;
                dataValidityFlag = 1;
                return dataValidityFlag;
            }
        }
    }
    return dataValidityFlag;
}
void* ControlPanelPlugin::ControlPanelThread(void *arg)
{
    ControlPanelPlugin* myControlPanel = (ControlPanelPlugin*)arg;
    PluginInterface* switchPlugin = static_cast<PluginInterface*>(myControlPanel->pluginList->getPluginByName("SwitchPlugin"));
    int32_t springBackValue[64] = {0};
    int32_t notSpringBackValue[64] = {0};
    uint64_t cmdValueTemp1 = 0;
    uint64_t cmdValueTemp2 = 0;
    time_t timeTemp;
    while(1)
    {
        //所有回弹型开关值获取
        cmdValueTemp1 = 0;
        memset(springBackValue,0,sizeof(springBackValue));
        for(int i = 0;i < E_BACK_KEY_END;i++)
        {
            springBackValue[i] = (switchPlugin->read("SPRINGBACK",i)).toInt();
            springBackValue[i] &= 1;
            cmdValueTemp1 |= (uint64_t)springBackValue[i] << i;
        }
        myControlPanel->back_key = cmdValueTemp1;
        //所有非回弹型开关值获取
        cmdValueTemp2 = 0;
        memset(notSpringBackValue,0,sizeof(notSpringBackValue));        
        for(int i = 0;i < E_NOT_BACK_KEY_END;i++)
        {
            notSpringBackValue[i] = (switchPlugin->read("NOT_SPRINGBACK",i)).toInt();
            notSpringBackValue[i] &= 1;
            cmdValueTemp2 |= (uint64_t)notSpringBackValue[i] << i;
        }
        myControlPanel->not_back_key = cmdValueTemp2;

        myControlPanel->key = (myControlPanel->back_key << 32) | myControlPanel->not_back_key;

        //操作台业务逻辑
        myControlPanel->key_command = CmdResolve(myControlPanel->key,myControlPanel->rock_calibration_value);
        //按键有效性检测
        myControlPanel->key_value_valid_falg = DataValidityDetection(myControlPanel->key);
//        printf("myControlPanel->key_value_valid_falg = %d\n",myControlPanel->key_value_valid_falg);

        //更新系统时间
        timeTemp = time(0);
        myControlPanel->system_int_time = timeTemp;
        myControlPanel->system_string_time = ctime(&timeTemp);

        //延时20ms
        usleep(20000);
    }
    return nullptr;
}
void ControlPanelPlugin::run()
{
    pthread_t springBack_tid;
    int ret = pthread_create(&springBack_tid,NULL,ControlPanelThread,this);
    if(ret == 0)
    {
        qDebug() << "springBack_tid created successfully";
    }
    else
    {
        qDebug() << "Failed to create springBack_tid";
    }
}
QVariant ControlPanelPlugin::read(const QString &type, quint16 channel)
{
    ControlPanelReadMutex.lock();
    int typeTemp = hashString(type.toStdString());
    QVariant getValueTemp;
    getValueTemp.clear();
    switch(typeTemp)
    {
    case VERSION:
        getValueTemp.setValue(QString::fromStdString(system_version));
        break;
    case SYS_STATUS:
        getValueTemp.setValue(system_status_ID);
        break;
    case SYS_COMM:
        getValueTemp.setValue(system_comm_status);
        break;
    case ERR_MESSAGE:
        getValueTemp.setValue(QString::fromStdString(system_error_message));
        break;
    case ERR_ID:
        getValueTemp.setValue(system_error_ID);
        break;
    case SPRINT_BACK_KEY:
        getValueTemp.setValue(static_cast<unsigned long long>(back_key ));
        break;
    case NOT_SPRING_BACK_KEY:
        getValueTemp.setValue(static_cast<unsigned long long>(not_back_key ));
        break;
    case ALL_KEY:
        getValueTemp.setValue(static_cast<unsigned long long>(key));
        break;
    case KEY_CMD:
        getValueTemp.setValue(static_cast<unsigned long long>(key_command ));
        break;
    case LEFT_TRAVAL:
        getValueTemp.setValue(rock_calibration_value.LeftTrack);
        break;
    case RIGHT_TRAVAL:
        getValueTemp.setValue(rock_calibration_value.RightTrack);
        break;
    case CUT_LEFT_RIGHT_VLAUE:
        getValueTemp.setValue(rock_calibration_value.CutLeftRight);
        break;
    case CUT_UP_DOWN_VALUE:
        getValueTemp.setValue(rock_calibration_value.CutUpDown);
        break;
    case KEY_VALID_FLAG:
        getValueTemp.setValue(key_value_valid_falg);
        break;
    case SYS_INT_DATE:
        getValueTemp.setValue(system_int_time);
        break;
    case SYS_STR_DATE:
        getValueTemp.setValue(QString::fromStdString(system_string_time));
        break;
    default:
        break;
    }
    ControlPanelReadMutex.unlock();
    return getValueTemp;
}
QVariant ControlPanelPlugin::write(const QString &type,quint16 channel,const QVariant &value)
{
    int typeTemp = hashString(type.toStdString());
    uint16_t channelTemp = channel;
    int iSetValueTemp = 0;
    switch(typeTemp)
    {
    case VERSION:
        system_version = value.toString().toStdString();
        break;
    case SYS_STATUS:
        system_status_ID = value.toInt();
        break;
    case SYS_COMM:
        iSetValueTemp = value.toInt();
        CommMutex.lock();
        switch(iSetValueTemp)
        {
        case 0:
            iSetValueTemp = (~(0x01 << channelTemp)) & 0x0F;
            system_comm_status &= iSetValueTemp;
            break;
        case 1:
            iSetValueTemp = 0x01 << channelTemp;
            system_comm_status |= iSetValueTemp;
            break;
        }
        CommMutex.unlock();
        break;
    case ERR_MESSAGE:
        system_error_message = value.toString().toStdString();
        break;
    case ERR_ID:
        system_error_ID = value.toInt();
        break;
    default:
        return -1;
    }
    return 0;
}
QVariant ControlPanelPlugin::ctrl(const QString &type,const QVariant &value)
{
    qDebug() << "ControlPanelPlugin::ctrl(const QString &type,const QVariant &value) is called";
    return 0;
}
