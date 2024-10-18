import QtQuick 2.2
import QtQuick.Window 2.2

Window {
    id: root
    width: 1920
    height: 1200
    visible: true
    title: "HDZK ControlPanel"

    Loader {    //背景组件
        id: backgroundLoader
        x: 0
        y: 0
        source: "qrc:/Components/BackgroundComponent.qml"
    }


    Loader {    //标题组件
        id: set
        x: 801
        y: 87
        z: 1
        source: "qrc:/normalCtrlComponents/title.qml"
        onLoaded: {
            item.titleText = qsTr("常规控制设置")
        }
    }

    Rectangle{
        y: 147
        width: 1920
        height: 4
        border.width: 4
        border.color: "#46505B"
        color: "#46505B"
    }

    Text {
        id: element
        x: 1615
        y: 99
        width: 168
        height: 33
        color: "#FFFFFF"
        text: qsTr("控制器起动状态")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
        font.pixelSize: 24
        font.family: "PingFang SC, PingFang SC";
    }

    Rectangle{
        x: 1799
        y: 85
        width: 100
        height: 56
        radius: 8
        border.width: 2
        color: Qt.rgba(1,1,1,0.02)
        border.color: Qt.rgba(1,1,1,0.32)
        Text {
            x: 35
            y: 10
            width: 31
            height: 37
            text: qsTr("10")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            color: "#26E677"
            font.bold: true
            font.family: "PingFang SC, PingFang SC"
            font.pixelSize: 26
        }
    }

    Loader{
        id: main_form_1
        x: 52
        y: 210
        source: "qrc:/normalCtrlComponents/main_form.qml"
    }

    Loader{
        id: main_form_2
        x: 1308
        y: 210
        source: "qrc:/normalCtrlComponents/main_form_2.qml"
    }

}
