#include "commcanplugin.h"
#include "tools/HashString/HashString.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include <sys/stat.h>

#include <pthread.h>
#include <dirent.h>

#include <stddef.h>
CommCANPlugin::CommCANPlugin()
    :can_sockfd(0)
    ,ifname("can0")
    ,bitRate(250000)
    ,baseFrameID(0x0b)
    ,canReceiveTime(200)
    ,commCanStatus(0)

{
    memset(&frameTxData,0,sizeof(frameTxData));
    memset(&frameRxData,0,sizeof(frameRxData));
    memset(canReceiveCounter,0,sizeof(canReceiveCounter));
}
CommCANPlugin::~CommCANPlugin()
{
    if(can_sockfd)
        close(can_sockfd);
}
int CommCANPlugin::canInit()
{
    //设备在位检测
     DIR *dir;
     dir = opendir("/sys/class/net");
     if(dir == nullptr)
     {
         printf("无法打开目录/sys/class/net");
         return -1;
     }
     closedir(dir);

     //can初始化
     struct sockaddr_can addr;
     struct ifreq ifr;
     memset(&addr,0,sizeof(addr));
     memset(&ifr,0,sizeof(ifr));

     //创建套接字
     can_sockfd = socket(PF_CAN,SOCK_RAW,CAN_RAW);
     if(can_sockfd < 0)
     {
         perror("Error while opening socket");
         return -1;
     }

     //设置CAN接口名称
     strcpy(ifr.ifr_name,ifname.c_str());
     //关闭CAN接口
     char ifconfig_down_cmd[256];
     int len_down = snprintf(ifconfig_down_cmd,sizeof(ifconfig_down_cmd),"ifconfig %s down",ifname.c_str());
     if(len_down < 0 || (unsigned)len_down >= sizeof(ifconfig_down_cmd))
     {
         fprintf(stderr,"Error in ifconfig down command genration\n");
         return -1;
     }

     if(system(ifconfig_down_cmd) != 0)
     {
         fprintf(stderr,"Error while bringing down CAN interface\n");
         return -1;
     }
     //设置CAN接口的波特率
     char cmd_set_bitrate[256];
     int len_bierate = snprintf(cmd_set_bitrate,sizeof(cmd_set_bitrate),"ip link set %s type can bitrate %d",ifname.c_str(),bitRate);
     if(len_bierate < 0 || (unsigned)len_bierate >= sizeof(cmd_set_bitrate))
     {
         fprintf(stderr,"Error in ip link set can bitrate command genration\n");
         close(can_sockfd);
         return -1;
     }
     if(system(cmd_set_bitrate) != 0)
     {
         fprintf(stderr,"Error while set can bitrate\n");
         return -1;
     }
     //启动CAN接口
     char ifconfig_up_cmd[256];
     int len_up = snprintf(ifconfig_up_cmd,sizeof(ifconfig_up_cmd),"ifconfig %s up",ifname.c_str());
     if(len_up < 0 || (unsigned)len_up >= sizeof(ifconfig_up_cmd))
     {
         fprintf(stderr,"Error in ifconfig up command generation\n");
         close(can_sockfd);
         return -1;
     }
     if(system(ifconfig_up_cmd) != 0)
     {
         fprintf(stderr,"Error while bringing up CAN interface\n");
         return -1;
     }

     //获取CAN接口索引
     if(ioctl(can_sockfd,SIOCGIFINDEX,&ifr) < 0)
     {
         perror("Error in SIOCGIFINDEX ioctl");
         close(can_sockfd);
         return -1;
     }
     //绑定CAN接口到套接字
     addr.can_family = AF_CAN;
     addr.can_ifindex = ifr.ifr_ifindex;
     if(bind(can_sockfd,(struct sockaddr*)&addr,sizeof(addr)) < 0)
     {
         perror("Error in soket bind\n");
         return -1;
     }
     //构造CAN帧
     int temp[5] = {0x180,0x280,0x380,0x480,0x580};
     for(int i = 0;i < 5;i++)
     {
         frameIDTx[i].can_id = baseFrameID + temp[i];
         frameIDTx[i].can_dlc = 8;
     }

     frameIDRx.can_dlc = 8;
     return 0;
}

//更新发送的CAN数据
void CommCANPlugin::refresh_can_transmitData(unsigned long long switchCmd,Rock_t& rock,int dataValidFlag)
{
    bool temp = (bool)frameTxData.Frame0.Word0.heartBead;
    memset(&frameTxData,0,sizeof(frameTxData));
    frameTxData.Frame0.Word0.heartBead =!temp;
    unsigned int switchCmd1 = switchCmd & 0x00000000ffffffff;//自锁定开关
    unsigned int switchCmd2 = switchCmd >> 32;//回弹开关
    /*急停处理*/
    if(switchCmd1 & SCRAM)
        switchCmd1 = switchCmd1 & 0xfffffffe;
    else
        switchCmd1 = switchCmd1 | 0x01;
    //数据有效标识
    frameTxData.Frame0.Word0.dataValid = dataValidFlag;
    //自锁定开关
    if(switchCmd1 & SCRAM)//急停
        frameTxData.Frame0.Word0.scram = 1;
    else
        frameTxData.Frame0.Word0.scram = 0;
    if(switchCmd1 & RMT_CTRL)//遥控
        frameTxData.Frame0.Word2.RTMCtrl = 1;
    else
        frameTxData.Frame0.Word2.RTMCtrl = 0;
    if(switchCmd1 & REMOTE_CTRL)//远控
        frameTxData.Frame0.Word2.remoteCtrl = 1;
    else
        frameTxData.Frame0.Word2.remoteCtrl = 0;
    if(switchCmd1 & AUTO_CUT)//自动截割
        frameTxData.Frame0.Word2.autoCut = 1;
    else
        frameTxData.Frame0.Word2.autoCut = 0;
    if(switchCmd1 & BACK_SUPPLY)//备用/支护
        frameTxData.Frame0.Word2.backSupply = 1;
    else
        frameTxData.Frame0.Word2.backSupply = 0;
    if(switchCmd1 & ANCHOR_RMT_CTRL)//锚杆遥控
        frameTxData.Frame0.Word1.anchorRMTCtrl = 1;
    else
        frameTxData.Frame0.Word1.anchorRMTCtrl = 0;
    if(switchCmd1 & ANCHOR_SUPPLY)//锚支
        frameTxData.Frame0.Word1.anchorSupply = 1;
    else
        frameTxData.Frame0.Word1.anchorSupply = 0;

    //自复位开关
    if(switchCmd2 & RESET)//复位
        frameTxData.Frame0.Word1.reset = 1;
    else
        frameTxData.Frame0.Word1.reset = 0;
    if(switchCmd2 & POWER_ON)//开机
        frameTxData.Frame0.Word1.powerOn = 1;
    else
        frameTxData.Frame0.Word1.powerOn = 0;
    if(switchCmd2 & ALARM_BELL_START)//警铃
        frameTxData.Frame0.Word1.alarmBellStart = 1;
    else
        frameTxData.Frame0.Word1.alarmBellStart = 0;
    if(switchCmd2 & LUBRICATION)//润滑
        frameTxData.Frame0.Word2.lubrication = 1;
    else
        frameTxData.Frame0.Word2.lubrication = 0;
    if(switchCmd2 & AUTO_CUT_INTERVENE)//截割干预
        frameTxData.Frame0.Word2.autoCutInterVene = 1;
    else
        frameTxData.Frame0.Word2.autoCutInterVene = 0;
    if(switchCmd2 & OIL_PUMP_START)//油泵
        frameTxData.Frame0.Word1.oilPumpStart = 1;
    else
        frameTxData.Frame0.Word1.oilPumpStart = 0;
    if(switchCmd2 & TRANSPORT_2_FWD)//二运
        frameTxData.Frame0.Word1.transport2FWD = 1;
    else
        frameTxData.Frame0.Word1.transport2FWD = 0;
    if(switchCmd2 & CUT_HIGH_START)//截高
        frameTxData.Frame0.Word1.cutHighStart = 1;
    else
        frameTxData.Frame0.Word1.cutHighStart = 0;
    if(switchCmd2 & CUT_LOW_START)//截低
        frameTxData.Frame0.Word1.cutLowStart = 1;
    else
        frameTxData.Frame0.Word1.cutLowStart = 0;
    if(switchCmd2 & FIRST_1_FAN)//风机1
        frameTxData.Frame0.Word1.fan1Start = 1;
    else
        frameTxData.Frame0.Word1.fan1Start = 0;
    if(switchCmd2 & SECOND_2_FAN)//风机2
        frameTxData.Frame0.Word1.fan2Start = 1;
    else
        frameTxData.Frame0.Word1.fan2Start = 0;
    if(switchCmd2 & PAGE_UP)//上翻页
        frameTxData.Frame0.Word0.pageUp = 1;
    else
        frameTxData.Frame0.Word0.pageUp = 0;
    if(switchCmd2 & PAGE_DOWN)//下翻页
        frameTxData.Frame0.Word0.pageDown = 1;
    else
        frameTxData.Frame0.Word0.pageDown = 0;
    if(switchCmd2 & UP)//上
        frameTxData.Frame0.Word2.keyUp = 1;
    else
        frameTxData.Frame0.Word2.keyUp = 0;
    if(switchCmd2 & DOWN)//下
        frameTxData.Frame0.Word2.keyDown = 1;
    else
        frameTxData.Frame0.Word2.keyDown = 0;
    if(switchCmd2 & ADD)//加
        frameTxData.Frame0.Word2.keyAdd = 1;
    else
        frameTxData.Frame0.Word2.keyAdd = 0;
    if(switchCmd2 & SUBTRAC)//减
        frameTxData.Frame0.Word2.keySubtrac = 1;
    else
        frameTxData.Frame0.Word2.keySubtrac = 0;
    if(switchCmd2 & CONFIRM)//确认
        frameTxData.Frame0.Word2.keyConfirm = 1;
    else
        frameTxData.Frame0.Word2.keyConfirm = 0;
    if(switchCmd2 & GO_BACK)//返回
        frameTxData.Frame0.Word2.keyGoBack = 1;
    else
        frameTxData.Frame0.Word2.keyGoBack = 0;

}
//更新发送缓存区
void CommCANPlugin::refresh_can_transmitBuff()
{
    memcpy(&frameIDTx[0].data,&frameTxData.Frame0,sizeof(frameTxData.Frame0));
    memcpy(&frameIDTx[1].data,&frameTxData.Frame1,sizeof(frameTxData.Frame1));
    memcpy(&frameIDTx[2].data,&frameTxData.Frame2,sizeof(frameTxData.Frame2));
    memcpy(&frameIDTx[3].data,&frameTxData.Frame3,sizeof(frameTxData.Frame3));
    memcpy(&frameIDTx[4].data,&frameTxData.Frame4,sizeof(frameTxData.Frame4));
}

int CommCANPlugin::can_write_data()
{
    int ret = 0;
    for(int i = 0;i < 5;i++)
    {
        ret = ::write(can_sockfd,&frameIDTx[i],sizeof(struct can_frame));
        if(ret != sizeof(struct can_frame))
        {
            return -1;
        }
    }
    return 0;
}
void* CommCANPlugin::can_write_thread(void *arg)
{
    CommCANPlugin* myCommCAN = (CommCANPlugin*)arg;
    Rock_t Rock = {0,0,0,0};
    uint64_t KeyValue = 0;
    uint32_t DataValidFlag = 0;
    PluginInterface* controlPanelPlugin = static_cast<PluginInterface*>(myCommCAN->pluginList->getPluginByName("ControlPanelPlugin"));
    while(1)
    {
        bool lastCommStatus = myCommCAN->commCanStatus;
        uint32_t CANStatus = myCommCAN->can_write_data();//3、发送数据
        if(!CANStatus )
        {
            KeyValue = (controlPanelPlugin->read("ALL_KEY",0)).toULongLong();
            Rock.LeftTrack = (controlPanelPlugin->read("LEFT_TRAVAL",0)).toUInt();
            Rock.RightTrack = (controlPanelPlugin->read("RIGHT_TRAVAL",0)).toUInt();
            Rock.CutLeftRight = (controlPanelPlugin->read("CUT_LEFT_RIGHT_VLAUE",0)).toUInt();
            Rock.CutUpDown = (controlPanelPlugin->read("CUT_UP_DOWN_VALUE",0)).toUInt();
            DataValidFlag = (controlPanelPlugin->read("KEY_VALID_FLAG",0)).toUInt();
            myCommCAN->refresh_can_transmitData(KeyValue,Rock,DataValidFlag);    //1、更新发送的CAN数据
            myCommCAN->refresh_can_transmitBuff();    //2、更新发送缓冲区
            myCommCAN->commCanStatus = 1;
        }
        else
        {
            myCommCAN->commCanStatus = 0;
            //延时1s
            sleep(1);
        }
        if(lastCommStatus != myCommCAN->commCanStatus)
        {
            lastCommStatus = myCommCAN->commCanStatus;
            controlPanelPlugin->write("SYS_COMM",0,myCommCAN->commCanStatus);
        }

        //延时20ms
        usleep(20000);
    }
}

//更新接收缓存区
void CommCANPlugin::refresh_can_receiveBuff()
{
    int can_RX_ID =  frameIDRx.can_id;
    if(!can_RX_ID)
        return;
    if(can_RX_ID == 0x200 + baseFrameID)
    {
        memcpy(&frameRxData.Frame0.frame0,&frameIDRx.data,sizeof(frameIDRx.data));
        canReceiveCounter[0] = 0;
    }
    else if(can_RX_ID == 0x300 + baseFrameID)
    {
        memcpy(&frameRxData.Frame1.frame1,&frameIDRx.data,sizeof(frameIDRx.data));
        canReceiveCounter[1] = 0;
    }
    else if(can_RX_ID == 0x400 + baseFrameID)
    {
        memcpy(&frameRxData.Frame2.frame2,&frameIDRx.data,sizeof(frameIDRx.data));
        canReceiveCounter[2] = 0;
    }
    else if(can_RX_ID == 0x500 + baseFrameID)
    {
        memcpy(&frameRxData.Frame3.frame3,&frameIDRx.data,sizeof(frameIDRx.data));
         canReceiveCounter[3] = 0;
    }
    else if(can_RX_ID == 0x600 + baseFrameID)
    {
        memcpy(&frameRxData.Frame4.frame4,&frameIDRx.data,sizeof(frameIDRx.data));
        canReceiveCounter[4] = 0;
    }
    else
        return;
}
//更新接收的CAN数据
void CommCANPlugin::refresh_can_receiveData()
{
    for(int i = 0; i < 5;i++)
        ++canReceiveCounter[i];
    //超时清零
    if(canReceiveCounter[0] > canReceiveTime )
    {
        memset(&frameRxData.Frame0.frame0,0,sizeof(frameRxData.Frame0.frame0));
    }
    if(canReceiveCounter[1] > canReceiveTime )
    {
        memset(&frameRxData.Frame1.frame1,0,sizeof(frameRxData.Frame1.frame1));
    }
    if(canReceiveCounter[2] > canReceiveTime )
    {
        memset(&frameRxData.Frame2.frame2,0,sizeof(frameRxData.Frame2.frame2));
    }
    if(canReceiveCounter[3] > canReceiveTime )
    {
        memset(&frameRxData.Frame3.frame3,0,sizeof(frameRxData.Frame3.frame3));
    }
    if(canReceiveCounter[4] > canReceiveTime )
    {
        memset(&frameRxData.Frame4.frame4,0,sizeof(frameRxData.Frame4.frame4));
    }
}
void CommCANPlugin::can_read_data()
{
    //接收前清零
    memset(&frameIDRx,0,sizeof(frameIDRx));
    //接收数据
    if(::read(can_sockfd,&frameIDRx,sizeof(struct can_frame)) < 0)
        printf("frameIDRx接收失败\n");
}

void* CommCANPlugin::can_read_thread(void *arg)
{
    CommCANPlugin* myCommCAN = (CommCANPlugin*)arg;
    while(1)
    {
        myCommCAN->can_read_data();
        //延时1ms
        usleep(1000);
    }
}
void* CommCANPlugin::can_refrsh_readData_thread(void *arg)
{
    CommCANPlugin* myCommCAN = (CommCANPlugin*)arg;
    while(1)
    {
        myCommCAN->refresh_can_receiveBuff();//1、更新缓存区
        myCommCAN->refresh_can_receiveData();//2、更新数据
        //延时1ms
        usleep(1000);
    }
}
void CommCANPlugin::run()
{
    canInit();
    //can发送
    pthread_t can_write_tid;
    int ret = pthread_create(&can_write_tid,NULL,can_write_thread,this);
    if(ret == 0)
        printf("can_write_thread created successfully.\n" );
    else
        fprintf(stderr,"Failed to create can_write_thread\n");
    //can接收
    pthread_t can_read_tid;
    ret = pthread_create(&can_read_tid,NULL,can_read_thread,this);
    if(ret == 0)
        printf("can_read_thread created successfully.\n" );
    else
        fprintf(stderr,"Failed to create can_read_thread\n");
    //can接收数据刷新
    pthread_t can_refrsh_readData_tid;
    ret = pthread_create(&can_refrsh_readData_tid,NULL,can_refrsh_readData_thread,this);
    if(ret == 0)
        printf("can_refrsh_readData_thread created successfully.\n" );
    else
        fprintf(stderr,"Failed to create can_refrsh_readData_thread\n");
}
QVariant CommCANPlugin::read(const QString &type, quint16 channel)
{
    qDebug() << "QVariant CommCANPlugin::read(const QString &type, quint16 channel) is called";
    return 0;
}
QVariant CommCANPlugin::write(const QString &type,quint16 channel,const QVariant &value)
{

    qDebug() << "CommCANPlugin::write(const QString &type,QVariant channel,const QVariant &value) is called";
    return 0;
}
QVariant CommCANPlugin::ctrl(const QString &type,const QVariant &value)
{
    qDebug() << "CommCANPlugin::ctrl(const QString &type,const QVariant &value) is called";
    return 0;
}
