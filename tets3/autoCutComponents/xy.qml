import QtQuick 2.0

Item {

    property var xyTextArray: [

        "航角/半径",
        "A点坐标(x, y)",
        "B点坐标(x, y)",
        "C点坐标(x, y)",
        "D点坐标(x, y)",
        "O点坐标(x, y)"
    ]

    property var xyValueArray: [

         1500, 1500 ,
         0500, 0800 ,
         3500, 0800 ,
         3500, 1800 ,
         0500, 1800 ,
         2000, 1800
    ]

    Repeater{
        model: 6

        Rectangle{
            x: 180
            y: 76 + (index * 66)
            color: "#00000000"
            width: 160
            height: 33
            Text {
                y: 9
                text: xyTextArray[index]
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
        model: 12

        Rectangle{
            x: 373 + 244 * (index % 2)
            y: 76 + Math.floor(index / 2) * 66
            width: 227
            height: 53
            border.color: Qt.rgba(1,1,1,0.32)
            border.width: 1.5
            color: "#00000000"
            radius: 8

            Text {
                text: xyValueArray[index]
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
