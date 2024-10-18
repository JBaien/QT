import QtQuick 2.0

Item {

    property int outputValue: [
        // 接入数据
    ]

    Repeater{
        model: 60
        Rectangle{
            x: Math.floor(index / 10) * 315
            y: (index % 10) * 36
            width: 260
            height: 48
            color: "#00000000"
            Text {
                id: channel_text
                x: 35
                y: 9
                text: qsTr("C")+(index + 1)
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.family: "PingFang SC, PingFang SC"
                color: Qt.rgba(1,1,1,0.6)
                font.pixelSize: 21
                font.bold: true
                width: 42
                height: 30
            }
            Text {
                id: channel_value
                x: 170
                y: 9
                text: "01"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Arial"
                color: "#26E677"
                font.pixelSize: 21
                font.bold: true
                width: 42
                height: 30
            }
        }
    }
}
