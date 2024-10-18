import QtQuick 2.9
import QtQuick.Window 2.2
import Qt.labs.qmlmodels 1.0

Window {
    id: window
    visible: true
    color: "#00000000"
    title: qsTr("车号界面")
    width: 1920
    height: 1200

    Item
    {
        id:rootItem
        x: -360
        y: 360
        width: 1920
        height: 1200
        scale: 1
        rotation: 270
        visible: true

        BorderImage {
            id: borderImage
            anchors.fill: parent
            source: "image/menuBc.png"

            Rectangle {
                id: rectangle
                x: 0
                y: 0
                width: 1920
                height: 200
                color: "#00000000"

                Text {
                    id: element
                    color: "#ffffff"
                    text: qsTr("车号设置")
                    font.pixelSize: 70
                    styleColor: "#00000000"
                    lineHeight: 0.4
                    font.family: "Arial"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: rectangle1
                x: 0
                y: 200
                width: 1920
                height: 500
                color: "#00000000"
                radius: 1

                Text {
                    id: element1
                    x: 500
                    y: 300
                    width: 260
                    height: 130
                    color: "#ffffff"
                    text: qsTr("车号：")
                    lineHeight: 1.1
                    font.family: "Arial";
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 90
                }

                Rectangle {
                    id: rectangle2
                    x: 800
                    y: 300
                    width: 500
                    height: 130
                    color: "#00000000"
                    radius: 20
                    border.width: 3
                    border.color: "#ffffff"

                    Text {
                        id: element2
                        x: 0
                        y: 0
                        width: 500
                        height: 130
                        color: "#ffffff"
                        text: qsTr("000000")
                        style: Text.Raised
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.family: "Times New Roman"
                        font.pixelSize: 90
                    }
                }
            }
        }

    }
}
