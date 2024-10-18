import QtQuick 2.0

Item {
    height: 1048
    width: 1920

    // 左半部分内容
    Rectangle{
        id: left_info
        color: Qt.rgba(1,1,1,0.04)
        width: 900
        height: 1048

        Text {
            id: element
            x: 286
            y: 56
            width: 329
            height: 33
            color: "#ffffff"
            text: qsTr("航角单位 0.01°   其他 1mm")
            font.family: "PingFang SC, PingFang SC"
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 24
        }

        Rectangle{
            x: 60
            y: 843
            width: 780
            height: 160
            radius: 8
            border.width: 1
            border.color: Qt.rgba(1,1,1,0.24)
            color: "#00000000"
            Text {
                x: 24
                y: 15
                width: 120
                height: 33
                color: "#ffffff"
                text: qsTr("操作提示：")
                font.family: "PingFang SC, PingFang SC"
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 24
            }
            Text {
                x: 24
                y: 72
                width: 506
                height: 30
                color: "#ffffff"
                text: qsTr("切换到自动截割使能请首先调整截割头至水平中位！")
                font.family: "Times New Roman"
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 22
            }
            Text {
                x: 24
                y: 116
                width: 440
                height: 30
                color: "#ffffff"
                text: qsTr("截割头位于最左下摆动位置定义为坐标原点！")
                font.family: "PingFang SC, PingFang SC"
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 22
            }
        }
    }


    // 右半部分内容
    Rectangle {
        id: right_info
        x: 900
        width: 1020
        height: 1048
        color: "#00000000"

        Rectangle {
            id: title_01
            x: 160
            y: 43
            width: 240
            height: 2
            color: Qt.rgba(1,1,1,0.15)
            border.color: Qt.rgba(1,1,1,0.15)
            border.width: 2
        }
        Text {
            id: text_01
            x: 438
            y: 25
            width: 144
            height: 33
            color: "#ffffff"
            text: qsTr("目标断面设置")
            font.family: "PingFang SC, PingFang SC"
            font.pixelSize: 24
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
        }

        Rectangle {
            id: title_02
            x: 619
            y: 43
            width: 240
            height: 2
            color: Qt.rgba(1,1,1,0.15)
            border.color: Qt.rgba(1,1,1,0.15)
            border.width: 2
        }



        Loader {
            source: "qrc:/autoCutComponents/xy.qml"
        }




        Rectangle {
            id: title_11
            x: 160
            y: 484
            width: 240
            height: 2
            color: Qt.rgba(1,1,1,0.15)
            border.color: Qt.rgba(1,1,1,0.15)
            border.width: 2
        }
        Text {
            id: text_11
            x: 438
            y: 469
            width: 144
            height: 33
            color: "#ffffff"
            text: qsTr("进尺设定")
            font.family: "PingFang SC, PingFang SC"
            font.pixelSize: 24
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
        }

        Rectangle {
            id: title_22
            x: 619
            y: 484
            width: 240
            height: 2
            color: Qt.rgba(1,1,1,0.15)
            border.color: Qt.rgba(1,1,1,0.15)
            border.width: 2
        }

        Rectangle {
            x: 182
            y: 518
            width: 455
            height: 53
            color: "#00000000"
            Text {
                y: 15
                text: qsTr("循环进尺使能")
                color: Qt.rgba(1,1,1,0.8)
                font.family: "PingFang SC, PingFang SC"
                font.pixelSize: 24
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.bold: true
            }
            Rectangle{
                x: 191
                width: 120
                height: 53
                border.width: 2
                radius: 8
                border.color: Qt.rgba(1,1,1,0.08)
                color: "#137B40"
                Text {
                    width: 120
                    height: 53
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    text: qsTr("开启")
                    font.bold: true
                    font.pixelSize: 24
                    font.family: "PingFang SC, PingFang SC"
                    color: "#FFFFFF"

                }
            }
            Rectangle{
                x: 335
                width: 120
                height: 53
                border.width: 2
                radius: 8
                border.color: Qt.rgba(1,1,1,0.22)
                color: "#00000000"
                Text {
                    width: 120
                    height: 53
                    verticalAlignment: Text.AlignVCenter
                    text: qsTr("关闭")
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    font.pixelSize: 24
                    font.family: "PingFang SC, PingFang SC"
                    color: Qt.rgba(1,1,1,0.56)

                }
            }

        }

        Loader {
            source: "qrc:/autoCutComponents/gaugeSetting.qml"
        }

        Rectangle {
            id: rectangle
            x: 371
            y: 952
            width: 280
            height: 64
            radius: 8
            border.width: 2
            border.color: Qt.rgba(1,1,1,0.32)
            color: Qt.rgba(1,1,1,0.08)
            Text {
                text: qsTr("保存")
                font.pixelSize: 28
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#FFFFFF"
                font.bold: true

            }
        }

    }

}
