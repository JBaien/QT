import QtQuick 2.0

Rectangle{

    width: 1509
    height: 64
    color: "#00000000"

    property string device: ""
    property int status: 0
    property string ua: ""
    property string va: ""
    property string wa: ""
    property string temp: ""
    Text {
        id: deviceText
        text: qsTr(device)
        width: 112
        height: 40
        x: 36
        y: 13
        color: "#FFFFFF"
        font.pixelSize: 28
        font.bold: true
    }
    Rectangle{
        id: test
        width: 110
        height: 46
        color: "#137B40"
        x: 327
        y: 9
        radius: 8
        Text {
            id: statusText
            width: 56
            height: 40
            anchors.centerIn: parent
            text: {switch (status) {
                case 0: return " 停状态";
                case 1: return " 预警";
                case 2: return " 声光预警";
                case 3: return " 启动";
                case 4: return " 运行状态";
                case 5: return " 停止";
                case 9: return " 错误";
                default: return "";
                }
            }
            color: "#FFFFFF"
            font.pixelSize: 28
            font.bold: true
        }
    }
    Text {
        id: uaText
        text: qsTr(ua)
        width: 64
        height: 42
        x: 596
        y: 12
        color: "#FFFFFF"
        font.pixelSize: 30
        font.bold: true
    }
    Text {
        id: vaText
        text: qsTr(va)
        width: 64
        height: 42
        x: 845
        y: 12
        color: "#FFFFFF"
        font.pixelSize: 30
        font.bold: true
    }
    Text {
        id: waText
        text: qsTr(wa)
        width: 64
        height: 42
        x: 1094
        y: 12
        color: "#FFFFFF"
        font.pixelSize: 30
        font.bold: true
    }
    Text {
        id: tempText
        text: qsTr(temp)
        width: 64
        height: 42
        x: 1343
        y: 12
        color: "#FFFFFF"
        font.pixelSize: 30
        font.bold: true
    }
}
