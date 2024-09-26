import QtQuick 2.9

Rectangle {
    id: root
    width: 1920
    height: 1200
    visible: true

    BorderImage {
        id: borderImage
        x: 0
        y: 0
        width: 1920
        height: 1200
        source: "qrc:/Image/background.png"

        Image {
            x: 21
            y: 12
            width: 200
            height: 52
            z: 1
            source: "qrc:/Image/title_com.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            x: 0
            y: 0
            width: 1920
            height: 80
            source: "qrc:/Image/title_first.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image
            x: 1843
            y: 3
            width: 56
            height: 56
            source: "../Image/menu_yes.png"
            fillMode: Image.PreserveAspectFit
        }
    }
}
