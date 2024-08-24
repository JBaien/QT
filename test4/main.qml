import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Item {
        id: element
        anchors.fill: parent

        Rectangle {
            id: crazy
            objectName: 'crazy'
            width: 100
            height: 100
            x: 50
            y: 50
            color: "#53d769"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            border.color: Qt.lighter(color, 1.1)
            Text {
                anchors.centerIn: parent
                text: Math.round(parent.x) + '/' + Math.round(parent.y)
            }
            MouseArea {
                anchors.top: parent.top
                anchors.right: parent.right
                anchors.left: parent.left
                drag.target: parent
            }
        }
    }

}

/*##^## Designer {
    D{i:1;anchors_height:400;anchors_width:400}
}
 ##^##*/
