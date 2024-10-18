import QtQuick 2.0

Rectangle{
    width: 560
    height: 820
    color: Qt.rgba(1,1,1,0.04)
    border.width: 1
    border.color: Qt.rgba(1,1,1,0.16)
    radius: 6


    property var mainText2Array: [
        "泵1压力",
        "泵2压力",
        "行走压力",
        "星轮压力",
        "一运压力",
        "回转压力一",
        "回转压力二"
    ]
    property var mainValue2Array: [
        0,
        0,
        0,
        0,
        0,
        0,
        0
    ]
    Repeater{
        model: 7
        Rectangle{

            x: Math.floor(index / 8) * 631   + 38
            y: 50 + (index % 8) * 90
            width: 491
            height: 82
            radius: 4
            color: "#00000000"
            border.color: "#00000000"
            border.width: 2
            Text {
                id: main_text
                x: 16
                y: 26
                width: 156
                height: 37
                font.pixelSize: 26
                text: mainText2Array[index]
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.family: "PingFang SC, PingFang SC"
                color: "#FFFFFF"
            }
            Rectangle{
                x: 230
                y: 15
                width: 140
                height:  50
                radius: 6
                color: Qt.rgba(1,1,1,0.08)
                border.color: Qt.rgba(1,1,1,0.24)
                Text {
                    id: form_text
                    text: mainValue2Array[index].toFixed(1)
                    anchors.fill: parent
                    color: "#FFFFFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 26
                    font.family: "PingFang SC, PingFang SC"
                }
            }
            Text {
                id: unit
                y: 25
                x: 380
                text: qsTr("mpa")
                color: "#FFFFFF"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 26
                font.family: "PingFang SC, PingFang SC"
            }
            Rectangle{
                x: 7
                y: 90
                width: 481
                height: 2
                color: "#00000000"
                border.width: 1
                border.color: Qt.rgba(1,1,1,0.12)
            }
        }

    }

}
