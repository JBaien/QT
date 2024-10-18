import QtQuick 2.0

Item {

    property var gaugeTextArray: [

        "进尺深度/次数",
        "横向修正数值",
        "纵向修正数值",
        "侧向标靶位置",
        "开挖宽度/净宽"
    ];

    property var gaugeValueArray: [

        1500, 0 ,
        "左", 0810 ,
        "上", 0800 ,
        "左", 1800 ,
        4000, 4000
    ]

    Repeater{
        model: 5

        Rectangle{
            x: 180
            y: 584 + (index * 66)
            color: "#00000000"
            width: 160
            height: 33
            Text {
                y: 9
                text: gaugeTextArray[index]
                width: 160
                height: 33
                color: Qt.rgba(1,1,1,0.8)
                font.bold: true
                font.pixelSize: 24
                font.family: "PingFang SC, PingFang SC"
            }
        }
    }

    Repeater{
        model: 10

        Rectangle{
            x: 373 + 244 * (index % 2)
            y: 584 + Math.floor(index / 2) * 66
            width: 227
            height: 53
            border.color: Qt.rgba(1,1,1,0.32)
            border.width: 1.5
            color: "#00000000"
            radius: 8

            Text {
                text: gaugeValueArray[index]
                color: Qt.rgba(1,1,1,0.9)
                font.bold: true
                font.pixelSize: 26
                width: 227
                height: 53
                font.family: "PingFang SC, PingFang SC"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }
    }
}
