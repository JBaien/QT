import QtQuick 2.2
import QtQuick.Window 2.2

Window {
    id: root
    width: 1920
    height: 1200
    visible: true
    title: "HDZK ControlPanel"

    Loader {    //背景组件
        id: backgroundLoader
        x: 0
        y: 0
        source: "qrc:/Components/BackgroundComponent.qml"
    }

    Rectangle { //主要内容
        id: rectangle
        x: 10
        y: 79
        width: 1900
        height: 957
        color: "#0E1821"

        //心跳组件
        ListModel {
            id: heartbeat
            ListElement { text: "控制器心跳"; heartbeatValue: 1 }
            ListElement { text: "远控心跳"; heartbeatValue: 0 }
        }
        Repeater {
            model: heartbeat
            delegate: Loader {
                x: 30 + (index * 340)  // 根据需要调整位置
                y: 24
                source: "qrc:/Components/HeartbeatComponent.qml"
                onLoaded: {
                    item.textValue = qsTr(model.text);
                    item.heartbeatValue = model.heartbeatValue;
                }
            }
        }


        // 工作状态组件
        ListModel {
            id: modeModel
            ListElement { text: "本地模式"; modeValue: 0 }
            ListElement { text: "截割手动模式"; modeValue: 1 }
            ListElement { text: "掘进模式"; modeValue: 0 }
        }
        Repeater {
            model: modeModel
            delegate: Loader {
                x: 710 + (index * 400)  // 根据需要调整位置
                y: 24
                source: "qrc:/Components/ModeComponent.qml"
                onLoaded: {
                    item.textValue = qsTr(model.text);
                    item.modeValue = model.modeValue;
                }
            }
        }

        // 间隔线
        Rectangle{
            x:19
            y:98
            width: 1877
            height: 2
            color: "#41454B"
        }

        //系统电压组件
        Loader{
            id: systemvoltage
            x:10
            y:167
            source: "qrc:/Components/SystemvoltageComponent.qml"
            onLoaded: {
                item.textValue = qsTr("1140V");
            }
        }

        // 间隔线
        Rectangle{
            x:20
            y:550
            width: 342
            height: 2
            color: Qt.rgba(1,1,1,0.2)
        }
        // 间隔线
        Rectangle{
            x:371
            y:98
            width: 2
            height: 861
            color: Qt.rgba(1,1,1,0.2)
        }

        // 各种工作时间
        ListModel {
            id: cuttime
            ListElement { worktext: "总工作时间"; worktime: "12 时 24 分" }
            ListElement { worktext: "总截割时间"; worktime: "10 时 30 分" }
            ListElement { worktext: "自动截割时间"; worktime: "6 时 18 分" }
        }
        Repeater {
            model: cuttime
            delegate: Loader {
                x: 383 + (index * 500)  // 根据需要调整位置
                y: 118
                source: "qrc:/Components/WorktimeComponent.qml"
                onLoaded: {
                    item.textValue = qsTr(model.worktext);
                    item.time = qsTr(model.worktime);
                }
            }
        }


        // 粉尘等数据
        ListModel {
            id: somedata
            ListElement { datatext1: "粉尘浓度"; datatext2: "瓦斯浓度"; dataValue1: "0.05 %"; dataValue2: "0.2 %";}
            ListElement { datatext1: "液压油温"; datatext2: "液压油位"; dataValue1: "39 ℃"; dataValue2: "98 %";}
            ListElement { datatext1: "水压力"; datatext2: "水流量"; dataValue1: "0.0 MPa"; dataValue2: "0.0 L/min";}
            ListElement { datatext1: "本体倾角X"; datatext2: "Y"; dataValue1: "0.0 °"; dataValue2: "0.0 °";}
            ListElement { datatext1: "铲板倾角X"; datatext2: "Y"; dataValue1: "2.4 °"; dataValue2: "15 °";}
            ListElement { datatext1: "钻锚前进距离 左"; datatext2: "右"; dataValue1: "5 mm"; dataValue2: "6 mm";}
        }
        Repeater {
            model: somedata
            delegate: Loader {
                x: 387 + (index % 3) * 502  // 每三个一行，确定 x 坐标
                y: 206 + Math.floor(index / 3) * 172  // 每行高度为 172，确定 y 坐标
                source: "qrc:/Components/DataComponent.qml"
                onLoaded: {
                    item.dataText1 = qsTr(model.datatext1);
                    item.dataText2 = qsTr(model.datatext2);
                    item.dataValue1 = qsTr(model.dataValue1);
                    item.dataValue2 = qsTr(model.dataValue2);
                }
            }
        }


        // 电机状态标题栏
        Loader{
            id: moter
            x: 372
            y: 555
            source: "qrc:/Components/MoterTitleComponent.qml"
        }

        // 电机参数数据
        ListModel {
            id: moterdata
            ListElement { device: "油泵电机"; status: 4; UA: "36.2 A"; VA: "38.2 A"; WA: "38.6 A"; temp: "60 ℃";}
            ListElement { device: "截低电机"; status: 0; UA: "28.2 A"; VA: "38.2 A"; WA: "38.6 A"; temp: "50 ℃";}
            ListElement { device: "截高电机"; status: 1; UA: "46.8 A"; VA: "38.2 A"; WA: "38.6 A"; temp: "56 ℃";}
            ListElement { device: "二运电机"; status: 2; UA: "32.9 A"; VA: "38.2 A"; WA: "38.6 A"; temp: "49 ℃";}
            ListElement { device: "风机电机"; status: 5; UA: "45.2 A"; VA: "38.2 A"; WA: "38.6 A"; temp: "31 ℃";}
        }
        Repeater {
            model: moterdata
            delegate: Loader {
                x: 377
                y: 624 + index * 65
                source: "qrc:/Components/MoterComponent.qml"
                onLoaded: {
                    item.device = qsTr(model.device);
                    item.status = model.status;
                    item.ua = qsTr(model.UA);
                    item.va = qsTr(model.VA);
                    item.wa = qsTr(model.WA);
                    item.temp = qsTr(model.temp)
                }
            }
        }
        // 左下工作相关信息
        Loader{
            id: workStatus
            x: 44
            y: 577
            source: "qrc:/Components/StatusComponent.qml"
            onLoaded: {
                item.someStatus1 = 1;
                item.someStatus2 = 2;
            }
        }

    }

    // 故障屏蔽栏
    Loader{
        x: 0
        y: 1039
        id: fault
        source: "qrc:/Components/FaultComponent.qml"
        onLoaded: {
            item.faultText = qsTr("故障数量");
            item.faultNum = 5
            item.shieldText = qsTr("屏蔽数量")
            item.shieldNum = 3
            item.alarmMessage = qsTr("电机故障！ 温度过高！")
        }
    }

    // 底部信息栏
    // 左下工作相关信息
    Loader{
        id: bottomInfo
        y: 1111
        source: "qrc:/Components/BottomComponent.qml"
    }
}
