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


    Loader {
        id: set
        x: 460
        y: 296
        source: "qrc:/parameterSetComponents/login.qml"
    }
}
