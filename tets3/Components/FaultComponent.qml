import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle {
    width: 1920
    height: 72
    color: "#00000000"
    property string faultText: ""
    property int faultNum: 0
    property string shieldText: ""
    property int shieldNum: 0
    property string alarmMessage: ""

    Image {
        anchors.fill: parent
        source: "qrc:/Image/back.png"

        Image {
            id: image
            x: 16
            y: 16
            width: 42
            height: 39
            fillMode: Image.PreserveAspectFit
            source: "qrc:/Image/notice.png"
        }

        Text {
            x: 76
            y: 18
            width: 112
            height: 40
            id: fault_Text
            text: qsTr(faultText)
            verticalAlignment: Text.AlignVCenter
            color: "#FFFFFF"
            font.pixelSize: 28
            font.bold: true
        }
        Text {
            x: 208
            y: 16
            width: 19
            height: 45
            id: fault_Num
            text: faultNum
            verticalAlignment: Text.AlignVCenter
            color: "#FF5757"
            font.pixelSize: 32
            font.bold: true
        }

        Rectangle {
            x: 273
            y: 3
            width: 1
            height: 66
            color: Qt.rgba(1, 1, 1, 0.24)
        }

        Text {
            x: 290
            y: 18
            width: 112
            height: 40
            id: shield_Text
            text: qsTr(shieldText)
            verticalAlignment: Text.AlignVCenter
            color: "#FFFFFF"
            font.pixelSize: 28
            font.bold: true
        }
        Text {
            x: 422
            y: 16
            width: 19
            height: 45
            id: shield_Num
            text: shieldNum
            verticalAlignment: Text.AlignVCenter
            color: "#E6B926"
            font.pixelSize: 32
            font.bold: true
        }

        Rectangle {
            x: 490
            y: 3
            width: 1
            height: 66
            color: Qt.rgba(1, 1, 1, 0.24)
        }

        // 报警信息
        Rectangle {
            id: alarmRectangle
            x: 490
            width: 1430
            height: 72
            color: "#00000000"
            border.width: 2
            border.color: "#00000000"
            Text {
                id: alarm_Message
                text: qsTr(alarmMessage)
                font.pixelSize: 20
                color: "#FFFFFF"
                anchors.verticalCenter: parent.verticalCenter
                x: 340

                // 使用一个定时器来实现移动
                Timer {
                    id: moveTimer
                    interval: 20 // 每20毫秒更新一次
                    running: true
                    repeat: true
                    onTriggered: {
                        alarm_Message.x -= 2; // 每次移动2个像素
                        // 当文本完全移出左边界时，重置位置到右边
                        if (alarm_Message.x < 0) {
                            alarm_Message.x = 1300;
                        }
                    }
                }
            }

            // 定时器用于每2秒切换颜色
            Timer {
                id: colorTimer
                interval: 800
                running: true
                repeat: true
                onTriggered: {
                    // 切换颜色
                    if (alarmRectangle.color === Qt.rgba(0, 0, 0, 0)) {
                        alarmRectangle.color = Qt.rgba(0.458824, 0.094118, 0.094118, 1);
                    } else {
                        alarmRectangle.color = Qt.rgba(0, 0, 0, 0);
                    }
                    if (alarmRectangle.border.color === Qt.rgba(0, 0, 0, 0)) {
                        alarmRectangle.border.color = Qt.rgba(1, 0.341176, 0.341176, 1);
                    } else {
                        alarmRectangle.border.color = Qt.rgba(0, 0, 0, 0);
                    }
                }
            }
        }
    }
}
