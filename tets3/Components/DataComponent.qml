import QtQuick 2.0

Rectangle{
    width: 486
    height: 156
    color: Qt.rgba(1,1,1,0.04);
    radius: 8
    border.width: 1
    border.color: Qt.rgba(1,1,1,0.24);


    property string dataText1: ""
    property string dataText2: ""
    property string dataValue1: ""
    property string dataValue2: ""
    Text {
        id: datatext_1
        x:40
        y:29
        width: 112
        height: 40
        text: qsTr(dataText1)
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 28
        font.bold: true
        font.family: "PingFang SC, PingFang SC"
        color: Qt.rgba(1,1,1,0.9)
    }
    Text {
        id: datatext_2
        x:276
        y:29
        width: 112
        height: 40
        text: qsTr(dataText2)
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 28
        font.bold: true
        font.family: "PingFang SC, PingFang SC"
        color: Qt.rgba(1,1,1,0.9)
    }

    Rectangle{
        x:31
        y:79
        width: 190
        height: 60
        color: Qt.rgba(0,0,0,0.24);
        radius: 8
        border.width: 1
        border.color: "#707070"
        Text {
            id: dataValue_1
            x:9
            y:6
            width: 98
            height: 45
            text: qsTr(dataValue1)
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 32
            font.bold: true
            font.family: "PingFang SC, PingFang SC"
            color: "#26E677"
        }
    }

    Rectangle{
        x:269
        y:79
        width: 190
        height: 60
        color: Qt.rgba(0,0,0,0.24);
        radius: 8
        border.width: 1
        border.color: "#707070"
        Text {
            id: dataValue_2
            x:9
            y:6
            width: 98
            height: 45
            text: qsTr(dataValue2)
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 32
            font.family: "PingFang SC, PingFang SC"
            font.bold: true
            color: "#26E677"
        }
    }
}
