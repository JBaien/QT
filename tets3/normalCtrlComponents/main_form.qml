import QtQuick 2.0

Rectangle {

    id: main_form_1
    width: 1200
    height: 820
    color: Qt.rgba(1,1,1,0.04)
    border.width: 1
    border.color: Qt.rgba(1,1,1,0.16)
    radius: 6

    property var is_selectArray: [
        0,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
    ]

    property var textValueArray: [
        0,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        1
    ]
    property var mainTextArray: [
        "工作/调试模式",
        "照明系统",
        "自动截割使能",
        "系统供电选择",
        "一运正转",
        "一运反转",
        "星轮正转",
        "星轮反转",
        "扫描仪使能",
        "后灯状态",
        "水泵一控制",
        "水泵二控制",
        "水泵三控制",
        "喷雾泵",
        "截割风机连锁",
        "行走低速切换"
    ]
    property var mainValueArray: [
        ["工作","调试"],
        ["关闭","开启"],
        ["关闭","开启"],
        ["AC1140V","AC660V"],
        ["关闭","开启"],
        ["关闭","开启"],
        ["关闭","开启"],
        ["关闭","开启"],
        ["关闭","开启"],
        ["照明","信号"],
        ["关闭","开启"],
        ["关闭","开启"],
        ["关闭","开启"],
        ["关闭","开启"],
        ["关闭","开启"],
        ["关闭","开启"]
    ]

    Repeater{
        model: 16
        Rectangle{

            x: Math.floor(index / 8) * 631   + 38
            y: 50 + (index % 8) * 90
            width: 491
            height: 82
            radius: 4
            color: "#00000000"
            border.color: is_selectArray[index] === 1? "#26E677" : "#00000000"
            border.width: 2
            Text {
                id: main_text
                x: 16
                y: 26
                width: 156
                height: 37
                font.pixelSize: 26
                text: mainTextArray[index]
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.family: "PingFang SC, PingFang SC"
                color: "#FFFFFF"
            }
            Rectangle{
                x: 300
                y: 15
                width: 160
                height:  50
                radius: 6
                border.color: Qt.rgba(1,1,1,0.24)
                gradient: Gradient {
                    GradientStop { position: 0.0; color: textValueArray[index] === 1 ? "#0081FE" : Qt.rgba(1,1,1,0.08) }
                    GradientStop { position: 1.0; color: textValueArray[index] === 1 ? "#0098FB" : Qt.rgba(1,1,1,0.08) }
                }
                Text {
                    id: form_text
                    text: mainValueArray[index][textValueArray[index]]
                    x: 54
                    y: 7
                    width: 52
                    height: 37
                    color: "#FFFFFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 26
                    font.family: "PingFang SC, PingFang SC"
                    font.bold: true
                }
            }
            Rectangle{
                x: 7
                y: 90
                width: 481
                height: 2
                color: "#00000000"
                border.width: 1
                border.color: is_selectArray[index] === 0? Qt.rgba(1,1,1,0.12) : "#00000000"
            }
        }

    }
}
