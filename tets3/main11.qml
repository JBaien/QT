import QtQuick 2.9
import QtQuick.Window 2.2
import Qt.labs.qmlmodels 1.0

Window {
    id:root
    width: 1920
    height: 1200
    visible:true
    title: "carNumSet"

    property int currentSelect_page: 0

    Loader {    //背景组件
        id: backgroundLoader
        x: 0
        y: 0
        source: "qrc:/Components/BackgroundComponent.qml"
    }

    Image {
        id: title_1
        x: 336
        y: 87
        z: 1
        width: 280
        height: 64
        source: currentSelect_page == 0 ? "qrc:/Image/title_second.png" : ""
        Text {
            id: title_Text
            x: 50
            y: 10
            z: 1
            width: 180
            height: 42
            color: currentSelect_page == 0 ? "#FFFFFF" : Qt.rgba(1,1,1,0.6)
            text: qsTr("自动截割监测")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 30
            font.family: "PingFang SC, PingFang SC"
            font.bold: true
        }
    }

    Image {
        id: title_2
        x: 801
        y: 87
        z: 1
        width: 280
        height: 64
        source: currentSelect_page == 1 ? "qrc:/Image/title_second.png" : ""
        Text {
            x: 50
            y: 10
            z: 1
            width: 180
            height: 42
            color: currentSelect_page == 1 ? "#FFFFFF" : Qt.rgba(1,1,1,0.6)
            text: qsTr("自动截割设置")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 30
            font.family: "PingFang SC, PingFang SC"
            font.bold: true
        }
    }

    Image {
        id: title_3
        x: 1290
        y: 87
        z: 1
        width: 280
        height: 64
        source: currentSelect_page == 2 ? "qrc:/Image/title_second.png" : ""
        Text {
            x: 50
            y: 10
            z: 1
            width: 180
            height: 42
            color: currentSelect_page == 2 ? "#FFFFFF" : Qt.rgba(1,1,1,0.6)
            text: qsTr("自动故障屏蔽")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 30
            font.family: "PingFang SC, PingFang SC"
            font.bold: true
        }
    }
    Rectangle{
        y: 147
        width: 1920
        height: 3
        border.width: 3
        border.color: "#46505B"
        color: "#46505B"
    }

    Timer {
        interval: 3000 // 每3秒更新
        running: true
        repeat: true
        onTriggered: {
            currentSelect_page = (currentSelect_page == 0) ? 1 : (currentSelect_page == 1) ? 2 : 0;
        }
    }

    Loader {
        id: select_page
        y: 150

        source: (currentSelect_page == 0) ? "qrc:/autoCutComponents/autoCutMonitor.qml" :
                                            (currentSelect_page == 1) ? "qrc:/autoCutComponents/autoCut.qml"
                                                                      : "qrc:/autoCutComponents/autoFaultShield.qml";
    }


}
