#include "commmbtcpplugin.h"
#include "tools/HashString/HashString.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <qmetatype.h>
void CommMbTCPPlugin::close_sigint(int dummy)
{
    if(server_socket != -1)
        close(server_socket);
    modbus_free(serverCtx);
    modbus_mapping_free(mb_mapping);
    exit(dummy);

}
//更新发送的modbusTCP数据
void CommMbTCPPlugin::RefreshModbusTCPTransmitData(unsigned long long switchCmd,Rock_t& rock,int dataValidFlag)
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
int CommMbTCPPlugin::ModbusTCPInit()
{
    serverCtx = modbus_new_tcp(serverIP.c_str(), serverPort);
    clientCtx = modbus_new_tcp(clientIP.c_str(),clientPort);
    if(serverCtx == nullptr || clientCtx == nullptr)
    {
        fprintf(stderr,"modbus_new_tcp failed\n");
        return -1;
    }
    mb_mapping = modbus_mapping_new(0,0,serverHoldRegistersSize,0);
    if (mb_mapping == nullptr) {
        fprintf(stderr, "Failed to allocate the mapping: %s\n", modbus_strerror(errno));
        modbus_free(serverCtx);
        return -1;
    }
    server_socket = modbus_tcp_listen(serverCtx, pollSize);//server_socket
    if(server_socket == -1)
    {
        printf("Unable to listen modbus_tcp_listen!\n");
        modbus_free(serverCtx);
        return -1;
    }    
    void (CommMbTCPPlugin::*p_close_sigint)(int) =&CommMbTCPPlugin::close_sigint;
    signal(SIGINT, (__sighandler_t)p_close_sigint);
    FD_ZERO(&refset);//清空fd_set
    FD_SET(server_socket,&refset);//FD_SET(int,fd_set*)将一个给定的文件描述符server_socket加入到集合之中
    fdmax = server_socket;//keep track of the max file descriptor
    //debug
//    modbus_set_debug(serverCtx, TRUE);
    return 0;
}
//更新发送缓存区
void CommMbTCPPlugin::RefreshModbusTCPTransmitBuff()
{
    memcpy(&mb_mapping->tab_registers[0*4],&frameTxData.Frame0,sizeof(frameTxData.Frame0));
    memcpy(&mb_mapping->tab_registers[1*4],&frameTxData.Frame1,sizeof(frameTxData.Frame1));
    memcpy(&mb_mapping->tab_registers[2*4],&frameTxData.Frame2,sizeof(frameTxData.Frame2));
    memcpy(&mb_mapping->tab_registers[3*4],&frameTxData.Frame3,sizeof(frameTxData.Frame3));
    memcpy(&mb_mapping->tab_registers[4*4],&frameTxData.Frame4,sizeof(frameTxData.Frame4));
}
//更新接收缓存区
void CommMbTCPPlugin::RefreshModbusTCPReceiveBuff()
{
    memcpy(&frameRxData,tab_reg,sizeof(frameRxData));
}
CommMbTCPPlugin::CommMbTCPPlugin()
{
    server_socket = -1;
    serverIP = "0.0.0.0";
    serverPort = 502;
    serverHoldRegistersSize = MODBUS_MAX_READ_REGISTERS;
    clientIP = "192.168.128.129";
    clientPort = 502;
    clientHoldRegistersSize = MODBUS_TCP_MAX_CLIENT_LENGTH;
    pollSize = 5;
    serverCtx = nullptr;
    clientCtx = nullptr;
    mb_mapping = nullptr;
    memset(&frameTxData,0,sizeof(frameTxData));
    memset(&frameRxData,0,sizeof(frameRxData));
    rc = 0;
    memset(query,0,sizeof(query));
    commMbTCPStatus = 0;
}
CommMbTCPPlugin::~CommMbTCPPlugin()
{
    if(serverCtx)
    {
        modbus_free(serverCtx);
        serverCtx = nullptr;
    }
    if(clientCtx)
    {
        modbus_free(clientCtx);
        clientCtx = nullptr;
    }
    if(mb_mapping != nullptr)
    {
        modbus_mapping_free(mb_mapping);
        mb_mapping = nullptr;
    }
}

void* CommMbTCPPlugin::ModbusTCPWriteThread(void *arg)
{
    CommMbTCPPlugin* myCommMbTCP = (CommMbTCPPlugin*)arg;
    PluginInterface* controlPanelPlugin = static_cast<PluginInterface*>(myCommMbTCP->pluginList->getPluginByName("ControlPanelPlugin"));
    unsigned long long KeyValue = 0;
    uint32_t DataValidFlag = 0;
    int master_socket;
    fd_set rdset;
    Rock_t Rock = {0,0,0,0};
    while(1)
    {
        rdset = myCommMbTCP->refset;
        //run through the existing connecting looking for data to be read,检查多个文件描述符状态
        if(select(myCommMbTCP->fdmax + 1,&rdset,NULL,NULL,NULL) == -1)//断开连接会阻塞
        {
            perror("server select() failure");
            myCommMbTCP->close_sigint(1);
        }


        for(master_socket = 0;master_socket <= myCommMbTCP->fdmax;master_socket++)
        {
            if(!FD_ISSET(master_socket,&rdset))//检查集合中指定的文件描述符是否可以读写
            {
                continue;
            }

            if(master_socket == myCommMbTCP->server_socket)//a client is asking a new connection
            {
                socklen_t addrlen;
                struct sockaddr_in clientaddr;
                int newfd;

                addrlen = sizeof(clientaddr);
                memset(&clientaddr,0,sizeof(clientaddr));
                //当服务器监听到一个连接请求时，使用accept()函数来接受该连接并创建一个新的套接字，以便与客户端进行通信。
                newfd = accept(myCommMbTCP->server_socket,(struct sockaddr*)&clientaddr,&addrlen);
                if(newfd == -1)
                {
                    perror("server accept error");
                }
                else
                {
                    //设置文件描述符集fdset中对应于文件描述符fd的位(设置为1)
                    FD_SET(newfd,&myCommMbTCP->refset);
                    if(newfd > myCommMbTCP->fdmax)
                    {
                        myCommMbTCP->fdmax = newfd;
                    }
                    printf("new connection form %s:%d on socket %d\n",inet_ntoa(clientaddr.sin_addr),clientaddr.sin_port,newfd);
                }
            }
            else
            {

                modbus_set_socket(myCommMbTCP->serverCtx,master_socket);
                myCommMbTCP->rc = modbus_receive(myCommMbTCP->serverCtx,(uint8_t*)myCommMbTCP->query);
                if(myCommMbTCP->rc > 0)
                {
                    KeyValue = (controlPanelPlugin->read("ALL_KEY",0)).toULongLong();
                    DataValidFlag = (controlPanelPlugin->read("KEY_VALID_FLAG",0)).toUInt();
                    myCommMbTCP->RefreshModbusTCPTransmitData(KeyValue,Rock,DataValidFlag);    //1、更新发送的modbus数据
                    myCommMbTCP->RefreshModbusTCPTransmitBuff();    //2、更新发送缓冲区
                    myCommMbTCP->rc = modbus_reply(myCommMbTCP->serverCtx, (uint8_t*)myCommMbTCP->query, myCommMbTCP->rc, myCommMbTCP->mb_mapping);

                    myCommMbTCP->commMbTCPStatus = 1;
                    //延时20ms
                    usleep(20000);
                }
                else if(myCommMbTCP->rc == -1)
                {

                    myCommMbTCP->commMbTCPStatus = 0;
                    close(master_socket);
                    FD_CLR(master_socket,&myCommMbTCP->refset);
                    if(master_socket == myCommMbTCP->fdmax)
                        myCommMbTCP->fdmax--;
                }
            }
        }
    }
    return nullptr;
}

void* CommMbTCPPlugin::modbusTCP_read_thread(void *arg)
{
//    printf("ModbusTCP 读取总字节数 = %d\n",sizeof(FrameRxData));
    CommMbTCPPlugin* myCommMbTCP = (CommMbTCPPlugin*)arg;
    int res = 0;
    int rd[10] = {0};
    while(1)
    {
modbusConnectAgain:
        res = modbus_connect(myCommMbTCP->clientCtx);//建立连接
        if(res == -1)
        {
            if(myCommMbTCP->commMbTCPStatus == 1)
                myCommMbTCP->commMbTCPStatus = 0;
            memset(&myCommMbTCP->frameRxData,0,sizeof(frameRxData));//通信失败，清空
            sleep(1);//每秒检测一次连接
            goto modbusConnectAgain;
        }
        if(myCommMbTCP->commMbTCPStatus == 0)
            myCommMbTCP->commMbTCPStatus = 1;
        while(1)
        {
            for(int i =0;i < MODBUS_TCP_MAX_CLIENT_LENGTH / 64;i++)
            {
                rd[i] = modbus_read_registers(myCommMbTCP->clientCtx,i * 64,64,&myCommMbTCP->tab_reg[i * 64]);
                if(rd[i] == -1)
                {
                    fprintf(stderr,"无法读取modbus寄存器：%s\n",modbus_strerror(errno));
                    goto modbusConnectAgain;
                }
            }
            myCommMbTCP->RefreshModbusTCPReceiveBuff();    //通讯正常，更新数据
            usleep(20000);
        }
    }
    return nullptr;
}
void* CommMbTCPPlugin::modbusTCP_fixComm_thread(void *arg)
{
    CommMbTCPPlugin* myCommMbTCP = (CommMbTCPPlugin*)arg;
    PluginInterface* controlPanelPlugin = static_cast<PluginInterface*>(myCommMbTCP->pluginList->getPluginByName("ControlPanelPlugin"));
    while(1)
    {
        bool lastCommMbTCPStatus = myCommMbTCP->commMbTCPStatus;
        usleep(20000);
        if(lastCommMbTCPStatus != myCommMbTCP->commMbTCPStatus)
        {
            controlPanelPlugin->write("SYS_COMM",1,myCommMbTCP->commMbTCPStatus);//通信正常
            lastCommMbTCPStatus = myCommMbTCP->commMbTCPStatus;
        }
    }
    return nullptr;
}
void CommMbTCPPlugin::run()
{
    ModbusTCPInit();
    pthread_t modbusTCP_write_tid;
    int ret = pthread_create(&modbusTCP_write_tid,NULL,ModbusTCPWriteThread,this);
    if(ret == 0)
    {
        printf("ModbusTCPWriteThread created successfully.\n" );
    }
    else
    {
        fprintf(stderr,"Failed to create ModbusTCPWriteThread\n");
    }
    pthread_t modbusTCP_read_tid;
    ret = pthread_create(&modbusTCP_read_tid,NULL,modbusTCP_read_thread,this);
    if(ret == 0)
    {
        printf("modbusTCP_read_thread created successfully.\n" );
    }
    else
    {
        fprintf(stderr,"Failed to create modbusTCP_read_thread\n");
    }
    pthread_t modbusTCP_fixComm_tid;
    ret = pthread_create(&modbusTCP_fixComm_tid,NULL,modbusTCP_fixComm_thread,this);
    if(ret == 0)
    {
        printf("modbusTCP_fixComm_thread created successfully.\n" );
    }
    else
    {
        fprintf(stderr,"Failed to create modbusTCP_fixComm_thread\n");
    }
}
QVariant CommMbTCPPlugin::read(const QString &type, quint16 channel)
{
    int typeTemp = hashString(type.toStdString());
    QVariant getValueTemp;
    getValueTemp.clear();
    if(typeTemp == RECEIVE_DATA)
    {
        unsigned long long addrOfReceiveData = reinterpret_cast<unsigned long long>(&frameRxData);
        getValueTemp.setValue(addrOfReceiveData);
    }
    return getValueTemp;
}
QVariant CommMbTCPPlugin::write(const QString &type,quint16 channel,const QVariant &value)
{
    qDebug() << "CommMbTCPPlugin::write(const QString &type,QVariant channel,const QVariant &value) is called";
    return 0;
}
QVariant CommMbTCPPlugin::ctrl(const QString &type,const QVariant &value)
{
    qDebug() << "CommMbTCPPlugin::ctrl(const QString &type,const QVariant &value) is called";
    return 0;
}
