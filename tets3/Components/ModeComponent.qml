import QtQuick 2.9
Rectangle {
    width: 360
    height: 64
    radius: 8
    border.width: 1

    property string textValue: ""
    property int modeValue: 0

    border.color: modeValue == 0 ? Qt.rgba(1, 1, 1, 0.24) : "#26E677"
    gradient: Gradient {
        // 根据 mode 选择不同的渐变
        GradientStop { position: 0.0; color: modeValue == 0 ? "#0081FE" : "#00000000" }
        GradientStop { position: 1.0; color: modeValue == 0 ? "#0098FB" : "#00000000" }
    }
    Text {
        x: 120
        y: 10
        width: 120
        height: 42
        text: qsTr(textValue)
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter  // 使用 textValue
        font.family: "PingFang SC-Bold"
        font.pixelSize: 30
        font.bold: true
        color: modeValue == 0 ? "#ECECEC": "#26E677"
    }
}
