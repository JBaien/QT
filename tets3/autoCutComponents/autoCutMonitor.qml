import QtQuick 2.0

Item {
    // 左半部分内容

    property var monitorLeftArray: [
        "车体距离过近",
        0,
        704,
        3296,
        11000
    ]
    Rectangle{
        id: left_info_2
        color: Qt.rgba(1,1,1,0.04)
        width: 900
        height: 1048

        Text {
            x: 354
            y: 47
            width: 192
            height: 45
            font.pixelSize: 32
            color: "#FF5757"
            font.bold: true
            text: monitorLeftArray[0]
            verticalAlignment: Text.AlignVCenter
            font.family: "PingFang SC, PingFang SC"
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            x: 391
            y: 136
            width: 118
            height: 33
            font.pixelSize: 24
            color: "#FFFFFF"
            font.bold: true
            text: qsTr("车体航角 ") + monitorLeftArray[1]
            verticalAlignment: Text.AlignVCenter
            font.family: "PingFang SC, PingFang SC"
            horizontalAlignment: Text.AlignHCenter
        }

        Rectangle {
            x: 152
            y: 303
            width: 4
            height: 506
            border.color: Qt.rgba(1,1,1,0.16)
            color: Qt.rgba(1,1,1,0.16)
        }
        Rectangle {
            x: 752
            y: 303
            width: 4
            height: 506
            border.color: Qt.rgba(1,1,1,0.16)
            color: Qt.rgba(1,1,1,0.16)
        }
        Rectangle {
            x: 152
            y: 809
            width: 604
            height: 4
            border.color: Qt.rgba(1,1,1,0.16)
            color: Qt.rgba(1,1,1,0.16)
        }

        Image {
            id: image
            x: 190
            y: 222
            width: 528
            height: 528
            source: "qrc:/Image/model.png"
            fillMode: Image.PreserveAspectFit

            Text {
                id: element
                x: 90
                y: 301
                width: 96
                height: 45
                color: "#ffffff"
                text: monitorLeftArray[2]
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 32
            }

            Text {
                id: element1
                x: 214
                y: 520
                width: 100
                height: 45
                color: "#ffffff"
                text: monitorLeftArray[4]
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
            }

            Text {
                id: element2
                x: 355
                y: 301
                width: 96
                height: 45
                color: "#ffffff"
                text: monitorLeftArray[3]
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
                font.pixelSize: 32
            }
        }
    }


    // 右半部分内容

    property var monitorRightArray:[

        1,
        -0.62,
        -21.77,
        "106° 27.00",
        "38° 27.00",
        -0.62,
        -0.62,
        -0.62,
        -0.89,
        -1.20,
        -2.00,
        0,
        0.00,
        0.00,
        0.00
    ]

    Rectangle {
        id: right_info_2
        x: 900
        width: 1020
        height: 1048
        color: "#00000000"

        //上方文字信息
        Text {
            x: 171
            y: 76
            color: "#ffffff"
            font.family: "PingFang SC, PingFang SC"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 26
            font.bold: true
            text: qsTr("自动截割")
        }

        Rectangle {
            x: 291
            y: 66
            width: 110
            height: 46
            radius: 8
            color: monitorRightArray[0] === 0 ? "#C82B2B" : "#137B40"
            Text {
                color: "#ffffff"
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 28
                text:  monitorRightArray[0] === 0 ? "停止" : "启动"
                anchors.fill: parent
            }
        }

        Text {
            x: 580
            y: 76
            color: "#ffffff"
            font.family: "PingFang SC, PingFang SC"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 26
            font.bold: true
            text: qsTr("陀螺仪经纬度设定")
        }

        //左上1数据信息
        Rectangle {

            x: 86
            y: 137
            width: 400
            height: 166
            border.color: Qt.rgba(1,1,1,0.24)
            border.width: 1
            radius: 8
            color: Qt.rgba(1,1,1,0.02)
            Text {
                x: 16
                y: 30
                color: Qt.rgba(1,1,1,0.8)
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 24
                font.bold: true
                text: qsTr("回转角度")
            }
            Text {
                x: 16
                y: 110
                color: Qt.rgba(1,1,1,0.8)
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 24
                font.bold: true
                text: qsTr("俯仰角度")
            }
            Text {
                x: 145
                y: 25
                width: 85
                height: 37
                color: Qt.rgba(1,1,1,1)
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 26
                font.bold: true
                text: monitorRightArray[1].toFixed(2)
            }
            Text {
                x: 145
                y: 105
                width: 85
                height: 37
                color: Qt.rgba(1,1,1,1)
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 26
                font.bold: true
                text: monitorRightArray[2].toFixed(2)
            }
        }

        //右上2数据信息
        Rectangle {

            x: 510
            y: 137
            width: 400
            height: 166
            border.color: Qt.rgba(1,1,1,0.24)
            border.width: 1
            radius: 8
            color: Qt.rgba(1,1,1,0.02)
            Text {
                x: 16
                y: 30
                color: Qt.rgba(1,1,1,0.8)
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 24
                font.bold: true
                text: qsTr("东经")
            }
            Text {
                x: 16
                y: 110
                color: Qt.rgba(1,1,1,0.8)
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 24
                font.bold: true
                text: qsTr("北纬")
            }
            Rectangle {
                x: 80
                y: 12
                width: 303
                height: 56
                color: "#00000000"
                border.width: 1
                border.color: Qt.rgba(1,1,1,0.24)
                radius: 8
                Text {
                    x: 20
                    width: 85
                    height: 56
                    color: Qt.rgba(1,1,1,1)
                    font.family: "PingFang SC, PingFang SC"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 26
                    font.bold: true
                    text: monitorRightArray[3]
                }
            }
            Rectangle {
                x: 80
                y: 92
                width: 303
                height: 56
                color: "#00000000"
                border.width: 1
                border.color: Qt.rgba(1,1,1,0.24)
                radius: 8
                Text {
                    x: 20
                    width: 85
                    height: 56
                    color: Qt.rgba(1,1,1,1)
                    font.family: "PingFang SC, PingFang SC"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 26
                    font.bold: true
                    text: monitorRightArray[4]
                }
            }
        }


        //中间数据信息
        Rectangle {
            x: 86
            y: 323
            width: 824
            height: 166
            color: Qt.rgba(1,1,1,0.02)
            border.color: Qt.rgba(1,1,1,0.24)
            border.width: 1
            radius: 8
            Text {
                x: 16
                y: 28
                width: 168
                height: 33
                color: Qt.rgba(1,1,1,0.8)
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 26
                font.bold: true
                text: qsTr("截割头当前位置")
            }
            Text {
                x: 16
                y: 108
                width: 168
                height: 33
                color: Qt.rgba(1,1,1,0.8)
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 26
                font.bold: true
                text: qsTr("截割头设定位置")
            }

            Rectangle {
                x: 222
                y: 16
                width: 585
                height: 56
                radius: 8
                color: Qt.rgba(1,1,1,0.02)
                border.width: 1
                border.color: Qt.rgba(1,1,1,0.04)
                Text {
                    x: 16
                    y: 9
                    width: 85
                    height: 37
                    color: Qt.rgba(1,1,1,1)
                    font.family: "PingFang SC, PingFang SC"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 26
                    font.bold: true
                    text: monitorRightArray[5].toFixed(2)
                }
                Text {
                    x: 229
                    y: 9
                    width: 85
                    height: 37
                    color: Qt.rgba(1,1,1,1)
                    font.family: "PingFang SC, PingFang SC"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 26
                    font.bold: true
                    text: monitorRightArray[6].toFixed(2)
                }
                Text {
                    x: 441
                    y: 9
                    width: 85
                    height: 37
                    color: Qt.rgba(1,1,1,1)
                    font.family: "PingFang SC, PingFang SC"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 26
                    font.bold: true
                    text: monitorRightArray[7].toFixed(2)
                }
            }

            Rectangle {
                x: 222
                y: 96
                width: 585
                height: 56
                radius: 8
                color: Qt.rgba(1,1,1,0.02)
                border.width: 1
                border.color: Qt.rgba(1,1,1,0.04)
                Text {
                    x: 16
                    y: 9
                    width: 85
                    height: 37
                    color: Qt.rgba(1,1,1,1)
                    font.family: "PingFang SC, PingFang SC"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 26
                    font.bold: true
                    text: monitorRightArray[8].toFixed(2)
                }
                Text {
                    x: 229
                    y: 9
                    width: 85
                    height: 37
                    color: Qt.rgba(1,1,1,1)
                    font.family: "PingFang SC, PingFang SC"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 26
                    font.bold: true
                    text: monitorRightArray[9].toFixed(2)
                }
                Text {
                    x: 441
                    y: 9
                    width: 85
                    height: 37
                    color: Qt.rgba(1,1,1,1)
                    font.family: "PingFang SC, PingFang SC"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 26
                    font.bold: true
                    text: monitorRightArray[10].toFixed(2)
                }
            }
        }


        //下方数据信息
        Rectangle {
            x: 86
            y: 519
            width: 824
            height: 166
            color: Qt.rgba(1,1,1,0.02)
            border.color: Qt.rgba(1,1,1,0.24)
            border.width: 1
            radius: 8
            Text {
                x: 16
                y: 28
                width: 168
                height: 33
                color: Qt.rgba(1,1,1,0.8)
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 26
                font.bold: true
                text: qsTr("导航状态")
            }
            Text {
                x: 16
                y: 108
                width: 168
                height: 33
                color: Qt.rgba(1,1,1,0.8)
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 26
                font.bold: true
                text: qsTr("加速度(x,y,z)")
            }

            Rectangle {
                x: 222
                y: 16
                width: 585
                height: 56
                radius: 8
                color: Qt.rgba(1,1,1,0.02)
                border.width: 1
                border.color: Qt.rgba(1,1,1,0.04)
                Text {
                    x: 16
                    y: 9
                    width: 85
                    height: 37
                    color: Qt.rgba(1,1,1,1)
                    font.family: "PingFang SC, PingFang SC"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 26
                    font.bold: true
                    text: monitorRightArray[11] === 0 ? "初始化中" : "其他状态"
                }
            }

            Rectangle {
                x: 222
                y: 96
                width: 585
                height: 56
                radius: 8
                color: Qt.rgba(1,1,1,0.02)
                border.width: 1
                border.color: Qt.rgba(1,1,1,0.04)
                Text {
                    x: 16
                    y: 9
                    width: 85
                    height: 37
                    color: Qt.rgba(1,1,1,1)
                    font.family: "PingFang SC, PingFang SC"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 26
                    font.bold: true
                    text: monitorRightArray[12].toFixed(2)
                }
                Text {
                    x: 229
                    y: 9
                    width: 85
                    height: 37
                    color: Qt.rgba(1,1,1,1)
                    font.family: "PingFang SC, PingFang SC"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 26
                    font.bold: true
                    text: monitorRightArray[13].toFixed(2)
                }
                Text {
                    x: 420
                    y: 9
                    width: 85
                    height: 37
                    color: Qt.rgba(1,1,1,1)
                    font.family: "PingFang SC, PingFang SC"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 26
                    font.bold: true
                    text: monitorRightArray[14].toFixed(2)
                }
                Text {
                    x: 510
                    y: 6
                    width: 61
                    height: 37
                    color: Qt.rgba(1,1,1,1)
                    font.family: "PingFang SC, PingFang SC"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 26
                    font.bold: true
                    text: "m/s²"
                }
            }
        }
        Rectangle {
            x: 371
            y: 819
            width: 280
            height: 64
            radius: 8
            color: Qt.rgba(1,1,1,0.08)
            border.width: 2
            border.color: Qt.rgba(1,1,1,0.32)
            Text {
                color: Qt.rgba(1,1,1,1)
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 26
                font.bold: true
                text: qsTr("保存")
                anchors.fill: parent
            }
        }

    }

}
