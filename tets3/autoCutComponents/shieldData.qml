import QtQuick 2.0

Item {

    property var shieldDataArray: [
        ["标靶数据异常", 1],
        ["车身防撞功能", 1],
        ["截割步进失败", 1],
        ["热红外1故障", 0],
        ["热红外2故障", 1],
        ["热红外3故障", 1],
        ["热红外4故障", 1]

    ]
    property var gradient1: Gradient {
        GradientStop { position: 0.0; color: "#0081FE" }
        GradientStop { position: 1.0; color: "#0098FB" }
    }

    property var gradient2: Gradient {
        GradientStop { position: 0.0; color: Qt.rgba(1, 1, 1, 0.08) }
        GradientStop { position: 1.0; color: Qt.rgba(1, 1, 1, 0.08) }
    }

    Repeater{
        model: 7


        Rectangle {
            x: 106
            y: 58 + (index * 83)
            width: 727
            height: 50
            color: "#00000000"
            Text {
                y: 11
                width: 156
                height: 37
                color: "#ffffff"
                text: shieldDataArray[index][0]
                font.pixelSize: 26
                font.bold: true
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }
            Rectangle {
                x: 377
                width: 160
                height: 50
                radius: 6
                border.color: Qt.rgba(1,1,1,0.16)
                border.width: 1
                gradient: shieldDataArray[index][1] === 1 ? gradient1 : gradient2
                Text {
                    color: "#ffffff"
                    font.family: "PingFang SC, PingFang SC"
                    font.pixelSize: 26
                    text: qsTr("已屏蔽")
                    font.bold: true
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }

            }

            Rectangle {
                x: 567
                width: 160
                height: 50
                radius: 6
                border.color: Qt.rgba(1,1,1,0.16)
                border.width: 1
                gradient: shieldDataArray[index][1] === 0 ? gradient1 : gradient2
                Text {
                    color: "#ffffff"
                    font.family: "PingFang SC, PingFang SC"
                    font.pixelSize: 26
                    text: qsTr("未屏蔽")
                    font.bold: true
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }

            }
            Rectangle {
                y: 67
                width: 727
                height: 2
                border.color: Qt.rgba(1,1,1,0.1)
                border.width: 2
                color: Qt.rgba(1,1,1,0.1)

            }
        }
    }

}
