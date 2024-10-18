import QtQuick 2.9


Image {
    id: title
    x: 0
    y: 0
    width: 280
    height: 64
    source: "qrc:/Image/title_second.png"

    property string titleText: ""

    Text {
        id: title_Text
        x: 50
        y: 10
        width: 180
        height: 42
        color: "#ffffff"
        text: qsTr(titleText)
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 30
        font.family: "PingFang SC, PingFang SC"
        font.bold: true
    }
}
