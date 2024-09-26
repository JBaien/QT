import QtQuick 2.0

Rectangle{
    width: 320
    height: 320
    color: "#00000000"
    property string textValue: ""
    Image {
        id: image
        x: 0
        y: 0
        width: 320
        height: 320
        z: 1
        source: "qrc:/Image/voltage.png"
        fillMode: Image.PreserveAspectFit

        Text {
            id: voltagetext
            x: 104
            y: 117
            width: 112
            height: 40
            color: "#ffffff"
            text: qsTr("系统电压")
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 28
            font.family: "PingFang SC-Regular"
        }

        Text {
            id: voltagenum
            x: 93
            y: 158
            width: 134
            height: 62
            text: qsTr(textValue)
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: "PingFang SC, PingFang SC"
            font.pixelSize: 44
            font.bold: true
            color: "#26E677"
        }
    }


}
