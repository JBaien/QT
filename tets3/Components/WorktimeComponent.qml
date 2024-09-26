import QtQuick 2.0

Rectangle{

    width: 465
    height: 72
    color: "#00000000"

    property string textValue: ""
    property string time: ""

    Text {
        id: worktext
        x:21
        y:16
        width: 140
        height: 40
        text: qsTr(textValue)
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.family: "PingFang SC, PingFang SC"
        font.pixelSize: 28
        font.bold: true
        color: Qt.rgba(1,1,1,0.9)
    }

    Rectangle{
        x: worktext.x + worktext.width + 40
        width: 280
        height: 72
        color: Qt.rgba(0,0,0,0.24)
        radius: 8
        border.width: 1
        border.color: "#707070"
        Text {
            id: worktime
            text: qsTr(time)
            anchors.centerIn: parent
            color: "#26D9E6"
            font.pixelSize: 32
            font.bold: true
        }
    }


}
