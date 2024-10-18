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

    Loader {    //标题组件
        id: set
        x: 801
        y: 87
        z: 1
        source: "qrc:/normalCtrlComponents/title.qml"
        onLoaded: {
            item.titleText = qsTr("参数设置")
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

    Rectangle {
        id: rectangle_left_sign
        x: 200
        y: 300
        width: 160
        height: 160
        color: "#00000000"
        border.color: Qt.rgba(1,1,1,0.24)
        radius: 8
        border.width: 2

        Image {
            x: 30
            y: 30
            id: image_left
            width: 100
            height: 100
            source: "qrc:/Image/left.png"
            fillMode: Image.PreserveAspectFit

        }
    }

    Rectangle {
        id: rectangle_right_sign
        x: 200
        y: 500
        width: 160
        height: 160
        color: "#00000000"
        border.color: Qt.rgba(1,1,1,0.24)
        radius: 8
        border.width: 2

        Image {
            x: 30
            y: 30
            id: image_right
            width: 100
            height: 100
            source: "qrc:/Image/right.png"
            fillMode: Image.PreserveAspectFit

        }
    }

    Rectangle {
        id: rectangle_add_sign
        x: 200
        y: 700
        width: 160
        height: 160
        color: "#00000000"
        border.color: Qt.rgba(1,1,1,0.24)
        radius: 8
        border.width: 2

        Image {
            x: 30
            y: 30
            id: image_add
            width: 100
            height: 100
            source: "qrc:/Image/add.png"
            fillMode: Image.PreserveAspectFit

        }
    }


    Rectangle {
        id: rectangle_sub_sign
        x: 200
        y: 900
        width: 160
        height: 160
        color: "#00000000"
        border.color: Qt.rgba(1,1,1,0.24)
        radius: 8
        border.width: 2

        Image {
            x: 30
            y: 30
            id: image_sub
            width: 100
            height: 100
            source: "qrc:/Image/sub.png"
            fillMode: Image.PreserveAspectFit

        }
    }

    Text {
        id: mw_nub
        x: 500
        y: 450
        color: "#ffffff"
        text: qsTr("MW_NUB:")
        font.bold: true
        font.family: "PingFang SC, PingFang SC"
        font.pixelSize: 50
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
    }

    Rectangle {
        id: mw_nub_rectangle
        x: 850
        y: 420
        width: 300
        height: 100
        border.color: Qt.rgba(1,1,1,0.24)
        border.width: 2
        color: Qt.rgba(1,1,1,0.02)
        radius: 6
        Text {
            font.bold: true
            font.family: "PingFang SC, PingFang SC"
            font.pixelSize: 50
            id: mw_nub_text
            text: qsTr("0 0 0")
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            color: "#FFFFFF"
        }
    }

    Text {
        id: mw_value
        x: 500
        y: 800
        color: "#ffffff"
        text: qsTr("MW_VALUE:")
        font.bold: true
        font.family: "PingFang SC, PingFang SC"
        font.pixelSize: 50
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
    }

    Rectangle {
        id: mw_value_rectangle
        x: 850
        y: 770
        width: 300
        height: 100
        border.color: Qt.rgba(1,1,1,0.24)
        border.width: 2
        color: Qt.rgba(1,1,1,0.02)
        radius: 6
        Text {
            font.bold: true
            font.family: "PingFang SC, PingFang SC"
            font.pixelSize: 50
            id: mw_value_text
            text: qsTr("0 0 0 0 0")
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            color: "#FFFFFF"
        }
    }

    Rectangle {
        id: read_rectangle
        x: 1500
        y: 330
        width: 200
        height: 100
        border.color: Qt.rgba(1,1,1,0.24)
        color: Qt.rgba(1,1,1,0.02)
        radius: 6
        Text {
            id: read_text
            color: "#ffffff"
            text: qsTr("READ")
            font.pointSize: 30
            font.bold: true
            font.family: "PingFang SC, PingFang SC"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
        }
    }

    Rectangle {
        id: write_rectangle
        x: 1500
        y: 540
        width: 200
        height: 100
        border.color: Qt.rgba(1,1,1,0.24)
        color: Qt.rgba(1,1,1,0.02)
        radius: 6
        Text {
            id: write_text
            color: "#ffffff"
            text: qsTr("WRITE")
            font.pointSize: 30
            font.bold: true
            font.family: "PingFang SC, PingFang SC"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
        }
    }

    Rectangle {
        id: bei_rectangle
        x: 1500
        y: 750
        width: 200
        height: 100
        border.color: Qt.rgba(1,1,1,0.24)
        color: Qt.rgba(1,1,1,0.02)
        radius: 6
        Text {
            id: bei_text
            color: "#ffffff"
            text: qsTr("备用")
            font.pointSize: 30
            font.bold: true
            font.family: "PingFang SC, PingFang SC"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
        }
    }

    Rectangle {
        id: hui_rectangle
        x: 1500
        y: 960
        width: 200
        height: 100
        border.color: Qt.rgba(1,1,1,0.24)
        color: Qt.rgba(1,1,1,0.02)
        radius: 6
        Text {
            id: hui_text
            color: "#ffffff"
            text: qsTr("恢复")
            font.pointSize: 30
            font.bold: true
            font.family: "PingFang SC, PingFang SC"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
        }
    }


}
