#include "commmbrtuplugin.h"
#include "tools/HashString/HashString.h"

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

#include <qmetatype.h>
//更新发送的modbusRTU数据
void CommMbRTUPlugin::refresh_modbusRTU_transmitData(unsigned long long switchCmd,Rock_t& rock)
{    
    bool temp = (bool)frameTxData.Frame0.Word0.heartBead;
    memset(&frameTxData,0,sizeof(frameTxData));
    frameTxData.Frame0.Word0.heartBead =!temp;
    unsigned int switchCmd1 = switchCmd & 0x00000000ffffffff;//自锁定开关
    unsigned int switchCmd2 = switchCmd >> 32;//回弹开关

    //自锁定开关
    if(switchCmd1 & SCRAM)
        frameTxData.Frame0.Word0.scram = 0;
    else
        frameTxData.Frame0.Word0.scram = 1;

    if(switchCmd1 & AUTOCUT)
        frameTxData.Frame0.Word2.autoCut = 1;
    else
        frameTxData.Frame0.Word2.autoCut = 0;
    if(switchCmd1 & STARWHEELFWD)
        frameTxData.Frame0.Word2.starWheelFWD = 1;
    else
        frameTxData.Frame0.Word2.starWheelFWD = 0;
    if(switchCmd1 & STARWHEELREV)
        frameTxData.Frame0.Word2.starWheelREV = 1;
    else
        frameTxData.Frame0.Word2.starWheelREV = 0;
    if(switchCmd1 & TRANSPORT1FWD)
        frameTxData.Frame0.Word2.transport1FWD = 1;
    else
        frameTxData.Frame0.Word2.transport1FWD = 0;
    if(switchCmd1 & TRANSPORT1REV)
        frameTxData.Frame0.Word2.transport1REV = 1;
    else
        frameTxData.Frame0.Word2.transport1REV = 0;
    if(switchCmd1 & LOCALSWITCH)
        frameTxData.Frame0.Word2.localSwitch = 1;
    else
        frameTxData.Frame0.Word2.localSwitch = 0;
    if(switchCmd1 & WATERPUMPSTART)
        frameTxData.Frame0.Word1.waterPump = 1;
    else
        frameTxData.Frame0.Word1.waterPump = 0;

    //自复位开关
    if(switchCmd2 & FULLSCREENSWITCH)
        frameTxData.Frame0.Word0.fullScreenSwitch = 1;
    else
        frameTxData.Frame0.Word0.fullScreenSwitch = 0;
    if(switchCmd2 & PICTURESWITCH)
        frameTxData.Frame0.Word0.pictureSwitch = 1;
    else
        frameTxData.Frame0.Word0.pictureSwitch = 0;
    if(switchCmd2 & POWERON)
        frameTxData.Frame0.Word1.powerOn = 1;
    else
        frameTxData.Frame0.Word1.powerOn = 0;
    if(switchCmd2 & ALARMBELLSTART)
        frameTxData.Frame0.Word1.alarmBellStart = 1;
    else
        frameTxData.Frame0.Word1.alarmBellStart = 0;
    if(switchCmd2 & AUTOCUTINTERVENE)
        frameTxData.Frame0.Word2.autoCutIntervene = 1;
    else
        frameTxData.Frame0.Word2.autoCutIntervene = 0;
    if(switchCmd2 & ONEKEYSTARTSTOP)
        frameTxData.Frame0.Word2.oneKeyStartStop = 1;
    else
        frameTxData.Frame0.Word2.oneKeyStartStop = 0;
    if(switchCmd2 & OILPUMPSTART)
        frameTxData.Frame0.Word1.oilPumpStart = 1;
    else
        frameTxData.Frame0.Word1.oilPumpStart = 0;

    if(switchCmd2 & TRANSPORT2FWD)
        frameTxData.Frame0.Word1.transport2FWD = 1;
    else
        frameTxData.Frame0.Word1.transport2FWD = 0;

    if(switchCmd2 & CUTHIGHSTART)
        frameTxData.Frame0.Word1.cutHighStart = 1;
    else
        frameTxData.Frame0.Word1.cutHighStart = 0;

    if(switchCmd2 & CUTLOWSTART)
        frameTxData.Frame0.Word1.cutLowStart = 1;
    else
        frameTxData.Frame0.Word1.cutLowStart = 0;

    if(switchCmd2 & FANSTART)
        frameTxData.Frame0.Word1.fanStart = 1;
    else
        frameTxData.Frame0.Word1.fanStart = 0;

    if(switchCmd2 & SPADEBLADEUP)
        frameTxData.Frame0.Word2.spadeBladeUp = 1;
    else
        frameTxData.Frame0.Word2.spadeBladeUp = 0;
    if(switchCmd2 & SPADEBLADEDOWN)
        frameTxData.Frame0.Word2.spadeBladeDown = 1;
    else
        frameTxData.Frame0.Word2.spadeBladeDown = 0;
    if(switchCmd2 & BACKSUPPORTUP)
        frameTxData.Frame0.Word2.backSupportUp = 1;
    else
        frameTxData.Frame0.Word2.backSupportUp = 0;
    if(switchCmd2 & BACKSUPPORTDOWN)
        frameTxData.Frame0.Word2.backSupportDown = 1;
    else
        frameTxData.Frame0.Word2.backSupportDown = 0;
    if(switchCmd2 & CUTUP)
        frameTxData.Frame0.Word2.cutUp = 1;
    else
        frameTxData.Frame0.Word2.cutUp = 0;
    if(switchCmd2 & CUTDOWN)
        frameTxData.Frame0.Word2.cutDown = 1;
    else
        frameTxData.Frame0.Word2.cutDown = 0;
    if(switchCmd2 & SPARE1)
        frameTxData.Frame0.Word3.spare1 = 1;
    else
        frameTxData.Frame0.Word3.spare1 = 0;
    if(switchCmd2 & SPARE2)
        frameTxData.Frame0.Word3.spare2 = 1;
    else
        frameTxData.Frame0.Word3.spare2 = 0;
    if(switchCmd2 & SPARE3)
        frameTxData.Frame0.Word3.spare3 = 1;
    else
        frameTxData.Frame0.Word3.spare3 = 0;
    if(switchCmd2 & SPARE4)
        frameTxData.Frame0.Word3.spare4 = 1;
    else
        frameTxData.Frame0.Word3.spare4 = 0;

//    //摇杆
    frameTxData.Frame1.Word0.LeftTrack = rock.LeftTrack;
    frameTxData.Frame1.Word0.RightTrack = rock.RightTrack;
    frameTxData.Frame1.Word1.CutLeftRight = rock.CutLeftRight;
    frameTxData.Frame1.Word1.CutUpDown = rock.CutUpDown;
}
int CommMbRTUPlugin::open_port()
{
    int fd;
    fd = open(slaveName.c_str(),O_RDWR | O_NOCTTY);
    if( -1 == fd)
    {
        return -1;
    }
    if( fcntl(fd,F_SETFL,0) < 0)//设置串口为阻塞状态
    {
        printf("fcntl failed\n");
        return -1;
    }
    return fd;
}
int CommMbRTUPlugin::set_opt(int fd,int nSpeed,int nBits,char nEvent,int nStop)
{
    struct termios newtio,oldtio;
    if(tcgetattr(fd,&oldtio) != 0)
    {
        perror("setupserial 1");
        return -1;
    }
    bzero(&newtio,sizeof(newtio));
    newtio.c_cflag |= CLOCAL | CREAD;
    newtio.c_cflag &= ~CSIZE;

    newtio.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    newtio.c_oflag &= ~OPOST;

    switch( nBits )//设置数据位的个数
    {
    case 7:
        newtio.c_cflag |= CS7;
    break;
    case 8:
        newtio.c_cflag |= CS8;
    break;
    }
    switch( nEvent )//设置校验位
    {
    case 'O':
        newtio.c_cflag |= PARENB;
        newtio.c_cflag |= PARODD;
        newtio.c_iflag |= (INPCK | ISTRIP);
    break;
    case 'E':
        newtio.c_iflag |= (INPCK | ISTRIP);
        newtio.c_cflag |= PARENB;
        newtio.c_cflag &= ~PARODD;
    break;
    case 'N':
        newtio.c_cflag &= ~PARENB;
    break;
    }
    switch( nSpeed )//设置波特率
    {
    case 2400:
        cfsetispeed(&newtio, B2400);
        cfsetospeed(&newtio, B2400);
    break;
    case 4800:
        cfsetispeed(&newtio, B4800);
        cfsetospeed(&newtio, B4800);
    break;
    case 9600:
        cfsetispeed(&newtio, B9600);
        cfsetospeed(&newtio, B9600);
    break;
    case 38400:
        cfsetispeed(&newtio, B38400);
        cfsetospeed(&newtio, B38400);
    break;
    case 115200:
        cfsetispeed(&newtio, B115200);
        cfsetospeed(&newtio, B115200);
    break;
    default:
        cfsetispeed(&newtio, B115200);
        cfsetospeed(&newtio, B115200);
    break;
    }
    if( nStop == 1 )//设置停止位
        newtio.c_cflag &= ~CSTOPB;
    else if ( nStop == 2 )
        newtio.c_cflag |= CSTOPB;

    newtio.c_cc[VMIN]  = 0;  /* 读数据时的最小字节数: 没读到这些数据我就不返回! */
    newtio.c_cc[VTIME] = 0; /* 等待第1个数据的时间:
                             * 比如VMIN设为10表示至少读到10个数据才返回,
                             * 但是没有数据总不能一直等吧? 可以设置VTIME(单位是10秒)
                             * 假设VTIME=1，表示:
                             *    10秒内一个数据都没有的话就返回
                             *    如果10秒内至少读到了1个字节，那就继续等待，完全读到VMIN个数据再返回
                             */
    tcflush(fd,TCIFLUSH);
    if((tcsetattr(fd,TCSANOW,&newtio))!=0)//tcsetattr函数设置行规程
    {
        perror("com set error");
        return -1;
    }
    return 0;
}
int CommMbRTUPlugin::modbusRTU_init()
{
    mbRTU_fd = open_port();
    if (mbRTU_fd < 0)
    {
        printf("open %s err!\n", slaveName.c_str());
        return -1;
    }
     int iRet = set_opt(mbRTU_fd, bitRate, dataBits, dataEvent, dataStop);//设置比特率位38400，数据位为8，没有校验位，停止位的个数是1。
     if (iRet)
     {
         printf("set port err!\n");
         return -1;
     }
     ctx = modbus_new_rtu(slaveName.c_str(),bitRate,dataEvent,dataBits,dataStop);
     if(ctx == nullptr)
     {
         fprintf(stderr,"Unable to allocate libmodbus contex\n");
         return -1;
     }
     modbus_rtu_set_serial_mode(ctx,MODBUS_RTU_RS485);//使用RS485
     //测试debug
//     modbus_set_debug(ctx,TRUE);
     modbus_set_slave(ctx,slaveID);
    mb_mapping = modbus_mapping_new(0,0,holdRegistersSize,0);
    if (mb_mapping == nullptr) {
        fprintf(stderr, "Failed to allocate the mapping: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return -1;
    }
    return 0;
}
//更新发送缓存区
void CommMbRTUPlugin::refresh_modbusRTU_transmitBuff()
{
    memcpy(&mb_mapping->tab_registers[0*4],&frameTxData.Frame0,sizeof(frameTxData.Frame0));
    memcpy(&mb_mapping->tab_registers[1*4],&frameTxData.Frame1,sizeof(frameTxData.Frame1));
    memcpy(&mb_mapping->tab_registers[2*4],&frameTxData.Frame2,sizeof(frameTxData.Frame2));
    memcpy(&mb_mapping->tab_registers[3*4],&frameTxData.Frame3,sizeof(frameTxData.Frame3));
    memcpy(&mb_mapping->tab_registers[4*4],&frameTxData.Frame4,sizeof(frameTxData.Frame4));
}
//更新接收缓存区
void CommMbRTUPlugin::refresh_modbusRTU_ReceiveBuff()
{
    memcpy(&frameRxData.Frame0,&mb_mapping->tab_registers[5*4],sizeof(frameRxData.Frame0));
    memcpy(&frameRxData.Frame1,&mb_mapping->tab_registers[6*4],sizeof(frameRxData.Frame1));
    memcpy(&frameRxData.Frame2,&mb_mapping->tab_registers[7*4],sizeof(frameRxData.Frame2));
    memcpy(&frameRxData.Frame3,&mb_mapping->tab_registers[8*4],sizeof(frameRxData.Frame3));
    memcpy(&frameRxData.Frame4,&mb_mapping->tab_registers[9*4],sizeof(frameRxData.Frame4));
}
CommMbRTUPlugin::CommMbRTUPlugin()
{
    slaveName = "/dev/ttyS0";
    mbRTU_fd = -1;
    bitRate = 38400;
    dataBits = 8;
    dataEvent = 'N';
    dataStop = 1;
    ctx = nullptr;
    slaveID = 0x0b;
    mb_mapping = nullptr;
    holdRegistersSize = 125;
    rc = 0;
    memset(&frameTxData,0,sizeof(frameTxData));
    memset(&frameRxData,0,sizeof(frameRxData));
    memset(query,0,sizeof(query));
    commMbRTUStatus = 0;
    counter = 0;
}
CommMbRTUPlugin::~CommMbRTUPlugin()
{
    if(ctx)
    {
        modbus_free(ctx);
        ctx = nullptr;
    }
    if(mb_mapping)
    {
        delete(mb_mapping);
        mb_mapping = nullptr;
    }
    if (mbRTU_fd)
    {
        close(mbRTU_fd);
    }
}

void* CommMbRTUPlugin::modbusRTU_write_thread(void *arg)
{
    unsigned long long KeyValue = 0;
    Rock_t Rock = {0,0,0,0};
    CommMbRTUPlugin* myCommMbRTU = (CommMbRTUPlugin*)arg;
    PluginInterface* controlPanelPlugin = static_cast<PluginInterface*>(myCommMbRTU->pluginList->getPluginByName("ControlPanelPlugin"));
    if(modbus_connect(myCommMbRTU->ctx) == -1)
    {
        fprintf(stderr,"connect filed %s\n",modbus_strerror(errno));
        modbus_free(myCommMbRTU->ctx);
        return NULL;
    }
    while(1)
    {
        do
        {
            myCommMbRTU->rc = modbus_receive(myCommMbRTU->ctx,(uint8_t*)myCommMbRTU->query);
        }while(myCommMbRTU->rc == 0);

        KeyValue = (controlPanelPlugin->read("ALL_KEY",0)).toULongLong();
        Rock.LeftTrack = (controlPanelPlugin->read("LEFT_TRAVAL",0)).toUInt();
        Rock.RightTrack = (controlPanelPlugin->read("RIGHT_TRAVAL",0)).toUInt();
        Rock.CutLeftRight = (controlPanelPlugin->read("CUT_LEFT_RIGHT_VLAUE",0)).toUInt();
        Rock.CutUpDown = (controlPanelPlugin->read("CUT_UP_DOWN_VALUE",0)).toUInt();
        myCommMbRTU->refresh_modbusRTU_transmitData(KeyValue,Rock);    //1、更新发送的modbus数据
        myCommMbRTU->refresh_modbusRTU_transmitBuff();    //2、更新发送缓冲区

        myCommMbRTU->rc = modbus_reply(myCommMbRTU->ctx, (uint8_t*)myCommMbRTU->query, myCommMbRTU->rc, myCommMbRTU->mb_mapping);
        if (myCommMbRTU->rc == -1)
            break;
        myCommMbRTU->counter = 0;
        //延时20ms
        usleep(20000);
    }
    return nullptr;
}
void* CommMbRTUPlugin::modbusRTU_read_thread(void *arg)
{
    CommMbRTUPlugin* myCommMbRTU = (CommMbRTUPlugin*)arg;
    PluginInterface* controlPanelPlugin = static_cast<PluginInterface*>(myCommMbRTU->pluginList->getPluginByName("ControlPanelPlugin"));
    while(1)
    {
        //业务逻辑
        //1、更新通信状态
        ++myCommMbRTU->counter;
        bool lastCommStatus = myCommMbRTU->commMbRTUStatus;
        if(myCommMbRTU->counter < 50)
        {
            myCommMbRTU->commMbRTUStatus = 1;
            //更新接收缓存区
            myCommMbRTU->refresh_modbusRTU_ReceiveBuff();
        }

        else
        {
            if(myCommMbRTU->commMbRTUStatus)
            {
                myCommMbRTU->commMbRTUStatus = 0;
                memset(&myCommMbRTU->frameRxData,0,sizeof(frameRxData));//通信失败，清空
            }
        }
        //测试接收值
//        printf("word0 = %x  word1 = %x  word2 = %x  word3 = %x\n",myCommMbRTU->frameRxData.Frame0.Word0,myCommMbRTU->frameRxData.Frame0.Word1,myCommMbRTU->frameRxData.Frame0.Word2,myCommMbRTU->frameRxData.Frame0.Word3);
        if(lastCommStatus != myCommMbRTU->commMbRTUStatus)
        {
            lastCommStatus = myCommMbRTU->commMbRTUStatus;
            controlPanelPlugin->write("SYS_COMM",2,myCommMbRTU->commMbRTUStatus);
        }

        //延时20ms
        usleep(20000);
    }
    return nullptr;
}
void CommMbRTUPlugin::run()
{
    modbusRTU_init();
    pthread_t modbusRTU_write_tid;
    int ret = pthread_create(&modbusRTU_write_tid,NULL,modbusRTU_write_thread,this);
    if(ret == 0)
    {
        printf("modbusRTU_write_thread created successfully.\n" );
    }
    else
    {
        fprintf(stderr,"Failed to create modbusRTU_write_thread\n");
    }

    pthread_t modbusRTU_read_tid;
    ret = pthread_create(&modbusRTU_read_tid,NULL,modbusRTU_read_thread,this);
    if(ret == 0)
    {
        printf("modbusRTU_read_thread created successfully.\n" );
    }
    else
    {
        fprintf(stderr,"Failed to create modbusRTU_read_thread\n");
    }
}
QVariant CommMbRTUPlugin::read(const QString &type, quint16 channel)
{
    qDebug() << "CommMbRTUPlugin::read(const QString &type, quint16 channel) is called";
    return 0;
}
QVariant CommMbRTUPlugin::write(const QString &type,quint16 channel,const QVariant &value)
{
    qDebug() << "CommMbRTUPlugin::write(const QString &type,QVariant channel,const QVariant &value) is called";
    return 0;
}
QVariant CommMbRTUPlugin::ctrl(const QString &type,const QVariant &value)
{
    qDebug() << "CommMbRTUPlugin::ctrl(const QString &type,const QVariant &value) is called";
    return 0;
}
