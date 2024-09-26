import QtQuick 2.0

Rectangle{
    width: 1512
    height: 64
    gradient: Gradient {
        GradientStop { position: 0.0; color: "#21303D" }
        GradientStop { position: 1.0; color: "#203243" }
    }

    // 标题栏
    Text {
        x: 44
        y: 12
        width: 56
        height: 40
        text: qsTr("设备")
        color: "#FFFFFF"
        font.pixelSize: 28
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }
    Text {
        x: 353
        y: 12
        width: 56
        height: 40
        text: qsTr("状态")
        color: "#FFFFFF"
        font.pixelSize: 28
        font.bold: true
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }
    Text {
        x: 609
        y: 12
        width: 48
        height: 40
        text: qsTr("U相")
        color: "#FFFFFF"
        font.pixelSize: 28
        font.bold: true
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }
    Text {
        x: 857
        y: 12
        width: 46
        height: 40
        text: qsTr("V相")
        color: "#FFFFFF"
        font.pixelSize: 28
        font.bold: true
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }
    Text {
        x: 1104
        y: 12
        width: 54
        height: 40
        text: qsTr("V相")
        color: "#FFFFFF"
        font.pixelSize: 28
        font.bold: true
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }
    Text {
        x: 1351
        y: 12
        width: 56
        height: 40
        text: qsTr("温度")
        color: "#FFFFFF"
        font.pixelSize: 28
        font.bold: true
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }
}
