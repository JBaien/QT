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
            item.titleText = qsTr("I O 状态监测")
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

//    Rectangle{
//        id: output_rectangle
//        x: 22
//        y: 140
//        width: 300
//        height: 100
//        color: "#00000000"
//        border.color: "#00000000"

//        Image {
//            id: image
//            x: 20
//            y: 35
//            width: 30
//            height: 30
//            source: "Image/status_green.png"
//        }

//        Text {
//            id: element
//            x: 70
//            y: 25
//            width: 100
//            height: 50
//            color: "#ffffff"
//            text: qsTr("In (60)")
//            verticalAlignment: Text.AlignVCenter
//            horizontalAlignment: Text.AlignLeft
//            font.pixelSize: 36
//        }

//    }

    Loader {    //IO标题
        id: titleLoader_1
        x: 40
        y: 180
        source: "qrc:/IOMonitoringComponents/IOtitle.qml"
    }

    Loader {    //output
        id: outputLoader
        x: 40
        y: 230
        source: "qrc:/IOMonitoringComponents/output_60.qml"
    }

    Loader {    //IO标题
        id: titleLoader_2
        x: 40
        y: 620
        source: "qrc:/IOMonitoringComponents/IOtitle.qml"
    }

    Loader {    //output
        id: inputLoader
        x: 40
        y: 670
        source: "qrc:/IOMonitoringComponents/input_80.qml"
    }
}
