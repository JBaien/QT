import QtQuick 2.0

Item {
    height: 1048
    width: 1920

    Rectangle {

        x: 490
        y: 60
        width: 940
        height: 780
        radius: 6
        color: Qt.rgba(1,1,1,0.04)
        border.color: Qt.rgba(1,1,1,0.16)
        border.width: 1

        Loader{
            source: "qrc:/autoCutComponents/shieldData.qml"
        }
    }


}
