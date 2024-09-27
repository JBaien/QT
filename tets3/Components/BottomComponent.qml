import QtQuick 2.0


Rectangle{
    width: 1920
    height: 88
    color: Qt.rgba(1,1,1,0.16)

    Text {
        id: element
        x: 30
        y: 24
        width: 101
        height: 42
        text: qsTr("PC版本")
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 30
        font.bold: true
        color: Qt.rgba(1,1,1,0.8)
        font.family: " PingFang SC, PingFang SC"
    }

    Text {
        id: element1
        x: 147
        y: 22
        width: 259
        height: 45
        text: qsTr("280MT02408029")
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 32
        font.bold: true
        color: "#FFFFFF"
        font.family: " PingFang SC, PingFang SC"
    }

    Image {
        id: image
        x: 856
        y: 18
        width: 52
        height: 52
        fillMode: Image.PreserveAspectFit
        source: "qrc:/Image/lock_blue.png"
    }

    Text {
        id: element2
        x: 924
        y: 23
        width: 120
        height: 42
        text: qsTr("锁车日期")
        font.pixelSize: 30
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        color: Qt.rgba(1,1,1,0.8)
    }

    Text {
        id: element3
        x: 1060
        y: 22
        width: 288
        height: 45
        text: qsTr("2024-10-31 23:00")
        font.pixelSize: 32
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        color: "#E6B926"
    }

    Text {
        id: element4
        x: 1469
        y: 23
        width: 120
        height: 42
        text: qsTr("当前时间")
        font.pixelSize: 30
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        color: Qt.rgba(1,1,1,0.8)
    }


    Text {
        id: timeText
        x: 1602
        y: 22
        width: 288
        height: 45
        font.pixelSize: 32
        color: "#FFFFFF"
        text: "2024-08-20 14:39:52"
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.bold: true
    }
    // 定时器每秒更新一次时间
    Timer {
        interval: 1000 // 每秒更新
        running: true
        repeat: true
        onTriggered: {
            timeText.text = Qt.formatDateTime(new Date(), "yyyy-MM-dd hh:mm:ss"); // 更新文本
        }
    }

}
