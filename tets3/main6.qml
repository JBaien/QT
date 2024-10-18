import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: window
    width: 1920
    height: 1200
    visible: true
    color: "#00000000"
    title: qsTr("报警查询")

    Item {
        id: rootItem
        width: 1920
        height: 1200
        visible: true

        BorderImage {
            id: borderImage
            width: 1920
            height: 800
            z: 1
            anchors.fill: parent
            source: "Image/background.png"

            Image {
                id: image
                x: 0
                y: 0
                width: 1920
                height: 80
                opacity: 1
                fillMode: Image.PreserveAspectFit
                source: "Image/title_first.png"
            }

            Rectangle {
                x: 0
                y: 150
                width: 1920
                height: 4
                color: "#46505B"
            }

            // 表头元素
            Text {
                id: element1
                x: 127
                y: 199
                z: 1
                width: 48
                height: 33
                color: "#ffffff"
                text: qsTr("序号")
                font.family: "Courier"
                font.pixelSize: 24
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Text {
                id: element2
                x: 290
                y: 199
                z: 1
                width: 96
                height: 33
                color: "#ffffff"
                text: qsTr("触发日期")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: "Times New Roman"
                font.pixelSize: 24
            }

            Text {
                id: element3
                x: 591
                y: 199
                z: 1
                width: 96
                height: 33
                color: "#ffffff"
                text: qsTr("触发时间")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 24
            }

            Text {
                id: element4
                x: 826
                y: 199
                z: 1
                width: 96
                height: 33
                color: "#ffffff"
                text: qsTr("恢复时间")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 24
            }

            Text {
                id: element5
                x: 1095
                y: 199
                z: 1
                width: 312
                height: 33
                color: "#ffffff"
                text: qsTr("报警消息（报警红，恢复白）")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 24
            }

            Rectangle {
                id: rectangle2
                x: 105
                y: 187
                width: 1710
                height: 60
                color: "#26333f";
            }

            Rectangle {
                id: rectangle
                x: 105
                y: 247
                width: 1710
                height: 900
                color: "#00000000"
                radius: 1
                border.width: 0

                // 内容区域
                ScrollView {
                    anchors.fill: parent
                    clip: true

                    ListView {
                        id: listView
                        anchors.fill: parent
                        model: alarmModel
                        delegate: Rectangle {
                            width: listView.width
                            height: 78
                            color: "#00000000"

                            Rectangle {
                                y:11
                                width: 1710
                                height: 56
                                color: is_fault ? "#751919" : "#00000000"
                                border.color: is_fault ? "#FF5757" : "#00000000"
                                border.width: 1.5

                                Row {
                                    spacing: 0
                                    anchors.fill: parent

                                    // 对齐内容列：序号
                                    Rectangle {
                                        width: 80
                                        height: 56
                                        color: "#00000000"

                                        Text {
                                            text: index + 1
                                            font.pixelSize: 26
                                            color: "white"
                                            verticalAlignment: Text.AlignVCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            anchors.fill: parent
                                        }
                                    }

                                    // 对齐内容列：触发日期
                                    Rectangle {
                                        width: 350
                                        height: 56
                                        color: "#00000000"

                                        Text {
                                            text: alarm_date
                                            font.pixelSize: 26
                                            color: "white"
                                            verticalAlignment: Text.AlignVCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            anchors.fill: parent
                                        }
                                    }

                                    // 对齐内容列：触发时间
                                    Rectangle {
                                        width: 210
                                        height: 56
                                        color: "#00000000"

                                        Text {
                                            text: alarm_time
                                            font.pixelSize: 26
                                            color: "white"
                                            verticalAlignment: Text.AlignVCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            anchors.fill: parent
                                        }
                                    }

                                    // 对齐内容列：恢复时间
                                    Rectangle {
                                        width: 260
                                        height: 56
                                        color: "#00000000"

                                        Text {
                                            text: recover_time
                                            font.pixelSize: 26
                                            color: "white"
                                            verticalAlignment: Text.AlignVCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            anchors.fill: parent
                                        }
                                    }

                                    Item {
                                        width: 90
                                        height: 56
                                    }

                                    // 对齐内容列：报警消息
                                    Rectangle {
                                        width: 330
                                        height: 56
                                        color: "#00000000"

                                        Text {
                                            text: alarm_message
                                            font.pixelSize: 26
                                            color: "white"
                                            verticalAlignment: Text.AlignVCenter
                                            horizontalAlignment: Text.AlignLeft
                                            anchors.fill: parent
                                        }
                                    }
                                }
                            }

                            // 分隔线放在内容 Rectangle 的下方
                            Rectangle {
                                y:78
                                width: 1710
                                height: 1
                                color: Qt.rgba(1, 1, 1, 0.05)
                                border.width: 1
                                border.color: Qt.rgba(1, 1, 1, 0.05)
                            }
                        }
                    }
                }
            }

            // 保持顶部的标题栏不变
            Rectangle {
                id: rectangle1
                x: 0
                y: 0
                width: 1920
                height: 150
                color: "#00000000"

                Text {
                    id: element
                    x: 881
                    y: 97
                    width: 120
                    height: 42
                    color: "#ffffff"
                    text: qsTr("报警查询")
                    fontSizeMode: Text.Fit
                    font.bold: true
                    font.family: "PingFang SC-Bold"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 30
                }
            }

            Rectangle {
                x: 801
                y: 90
                width: 280
                height: 64
                color: "#00000000"
                radius: 4
                Image {
                    id: image1
                    x: 0
                    y: 0
                    width: 280
                    height: 64
                    clip: false
                    fillMode: Image.PreserveAspectFit
                    source: "Image/title_second.png"
                }
            }

            Image {
                id: image2
                x: 21
                y: 12
                width: 200
                height: 52
                fillMode: Image.PreserveAspectFit
                source: "Image/title_com.png"
            }
        }
    }
}
