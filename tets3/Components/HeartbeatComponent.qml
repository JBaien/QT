import QtQuick 2.9
Rectangle {
    width: 300
    height: 64
    color: Qt.rgba(1, 1, 1, 0.08)
    radius: 8
    border.color: Qt.rgba(1, 1, 1, 0.24)
    border.width: 1

    property string textValue: ""
    property int heartbeatValue: 0

    Text {
        x: 100
        y: 12
        width: 140
        height: 40
        text: qsTr(textValue)  // 使用 textValue
        font.family: "PingFang SC-Bold"
        font.pixelSize: 28
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        color: "#ECECEC"
    }

    // 根据 heartbeatValue 选择不同的图片
    Image {
        x: 60
        y: 17
        width: 30
        height: 30
        source: heartbeatValue === 1 ? "qrc:/Image/status_green.png" : "qrc:/Image/status_red.png"
        fillMode: Image.PreserveAspectFit
    }
}
