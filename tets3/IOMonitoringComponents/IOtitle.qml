import QtQuick 2.0

Item {

    Repeater{
        model: 6
        Rectangle{
            x: index * 315
            width: 260
            height: 48
            color: Qt.rgba(1,1,1,0.06)
            radius: 6
            Text {
                id: channel_text
                x: 35
                y: 9
                text: qsTr("通道")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: "PingFang SC, PingFang SC"
                color: Qt.rgba(1,1,1,0.5)
                font.pixelSize: 21
                font.bold: true
                width: 42
                height: 30
            }
            Text {
                id: channel_value
                x: 170
                y: 9
                text: qsTr("当前值")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: "PingFang SC, PingFang SC"
                color: Qt.rgba(1,1,1,0.5)
                font.pixelSize: 21
                font.bold: true
                width: 42
                height: 30
            }
        }
    }
}


/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
