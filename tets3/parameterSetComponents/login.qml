import QtQuick 2.9

Rectangle {
    x: 0
    y: 0
    width: 1000
    height: 608
    color: "#263443"
    radius: 16
    Text {
        id: title
        x: 416
        y: 10
        text: qsTr("参数设置登录")
        font.pixelSize: 28
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        width: 168
        height: 40
        color: "#FFFFFF"
        font.family: "PingFang SC, PingFang SC"
        font.bold: true
    }

    Rectangle {
        id: rectangle
        x: 0
        y: 60
        width: 1000
        height: 64
        color: Qt.rgba(1,1,1,0.04)

        Text {
            id: carNumText
            x: 211
            y: 17
            width: 102
            height: 33
            color: Qt.rgba(1,1,1,0.8)
            text: qsTr("当前车号:")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 24
            font.family: "PingFang SC, PingFang SC"
            font.bold: true
        }

        Text {
            id: carNumValue
            x: 346
            y: 17
            width: 123
            height: 33
            color: "#FFFFFF"
            text: qsTr("00000000")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 24
            font.family: "PingFang SC, PingFang SC"
            font.bold: true
        }

        Text {
            id: qDText
            x: 625
            y: 17
            width: 66
            height: 33
            text: qsTr("QD值:")
            color: Qt.rgba(1,1,1,0.8)
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: "PingFang SC, PingFang SC"
            font.pixelSize: 24
        }

        Text {
            id: qDValue
            x: 718
            y: 17
            width: 72
            height: 33
            text: qsTr("19731")
            color: "#FFFFFF"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.family: "PingFang SC, PingFang SC"
            font.pixelSize: 24
        }
    }

    Text {
        id: codeText
        x: 374
        y: 210
        width: 252
        height: 40
        color: "#ffffff"
        text: qsTr("请输入参数设置密码")
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 28
        font.family: "PingFang SC, PingFang SC"
    }

    property string codeValue1 : "1"
    property string codeValue2 : "2"
    property string codeValue3 : "3"
    property string codeValue4 : "4"
    property string codeValue5 : "6"
    property string codeValue6 : "5"
    property var codeValue:[
        codeValue1,
        codeValue2,
        codeValue3,
        codeValue4,
        codeValue5,
        codeValue6
    ]

    Rectangle {
        id: code_rectangle
        x: 313
        y: 289
        width: 375
        height: 80
        color: Qt.rgba(1,1,1,0.04)
        radius: 8
        border.width: 2
        border.color: Qt.rgba(1,1,1,0.32)

        Repeater{
            model: 6
            Rectangle{
                id: codeValue_rectangle
                x: 17 + (index * 60)
                y: 6
                width: 40
                height: 68
                color:{
                    if(index == 0) return "#26E677"
                    else return "#00000000"
                }
                opacity: 0.8
                Text {
                    id: codeValue_Text
                    text: codeValue[index]
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 40
                    color: "#FFFFFF"
                    font.bold: true
                    font.family: "PingFang SC, PingFang SC"
                }
            }
        }
    }

    Text {
        id: codeErrorText
        x: 375
        y: 469
        width: 144
        height: 33
        text: qsTr("密码错误次数      次")
        font.bold: true
        color: Qt.rgba(1,1,1,0.8)
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        font.family: "PingFang SC, PingFang SC"
        font.pixelSize: 24
    }

    Text {
        id: codeErrorNum
        x: 553
        y: 469
        width: 14
        height: 33
        color: "#ffffff"
        text: qsTr("0")
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 24
        font.family: "PingFang SC, PingFang SC"
    }

    Text {
        id: codeAlarmText
        x: 276
        y: 511
        width: 448
        height: 30
        color: "#e6b926"
        text: qsTr("注意：密码每输错10次，将暂停输入10分钟！")
        font.pixelSize: 22
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.family: "PingFang SC, PingFang SC"
    }
}

/*##^## Designer {
    D{i:14;anchors_y:6}
}
 ##^##*/
