import QtQuick 2.9
import QtQuick.Window 2.2
import Qt.labs.qmlmodels 1.0

Window {
    id:root
    width: 1920
    height: 1200
    visible:true
    title: "carNumSet"

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
            item.titleText = qsTr("车号设置")
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
        x: 450
        y: 350
        width: 300
        height: 150
        text: qsTr("车号：")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 60
        font.family: "PingFang SC, PingFang SC"
        font.bold: true
        color: "#FFFFFF"
    }

    Rectangle {
        id: rectangle
        x: 850
        y: 350
        width: 500
        height: 150
        color: "#00000000"
        radius: 6
        border.color: "#ffffff"
        border.width: 2

        Text {
            id: element1
            color: "#ffffff"
            text: qsTr("000000")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 100
            font.family: "PingFang SC, PingFang SC"
            font.bold: true
        }
    }

}
