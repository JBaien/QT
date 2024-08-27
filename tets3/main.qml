import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    id: window
    width: 1920
    height: 1200
    visible: true
    color: "#00000000"
    title: qsTr("屏蔽界面")

    Item {
        id:rootItem
//        x: -360
//        y: 360
        width: 1920
        height: 1200
        scale: 1
//        rotation: 270
        visible: true

        BorderImage {
            id: borderImage
            width: 1920
            height: 800
            z: 1
            anchors.fill: parent
            source: "image/menuBc.png"

            Rectangle {
                id: rectangle
                x: 10
                y: 200
                width: 1900
                height: 980
                color: "#00000000"
                radius: 5
                border.width: 10

                Column {
                    width: parent.width
                    height: parent.height

                    // 标题栏
                    Grid {
                        id: grid
                        width: 1860
                        height: 120
                        columns: 5

                        Rectangle {
                            id: rectangle2
                            x: 10
                            y: 10
                            width: 250
                            height: 120
                            color: "#00000000"
                            radius: 0
                            border.width: 5

                            Text {
                                id: element1
                                color: "#ffffff"
                                text: qsTr("序号")
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                                anchors.fill: parent
                                font.pixelSize: 50
                            }
                        }

                        Rectangle {
                            id: rectangle3
                            width: 350
                            height: 120
                            color: "#00000000"
                            border.width: 5

                            Text {
                                id: element2
                                color: "#ffffff"
                                text: qsTr("屏蔽日期")
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                                anchors.fill: parent
                                font.pixelSize: 50
                            }
                        }

                        Rectangle {
                            id: rectangle4
                            width: 350
                            height: 120
                            color: "#00000000"
                            border.width: 5

                            Text {
                                id: element4
                                color: "#ffffff"
                                text: "屏蔽时间"
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                                anchors.fill: parent
                                font.pixelSize: 50
                            }
                        }

                        Rectangle {
                            id: rectangle5
                            width: 350
                            height: 120
                            color: "#00000000"
                            border.width: 5

                            Text {
                                id: element3
                                color: "#ffffff"
                                text: qsTr("取消屏蔽")
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                                anchors.fill: parent
                                font.pixelSize: 50
                            }
                        }

                        Rectangle {
                            id: rectangle6
                            width: 600
                            height: 120
                            color: "#00000000"
                            border.width: 5

                            Text {
                                id: element5
                                color: "#ffffff"
                                text: qsTr("屏    蔽    消    息")
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                                anchors.fill: parent
                                font.pixelSize: 50
                            }
                        }
                    }

                    // 内容区域
                    ScrollView {
                        width: parent.width
                        height: parent.height - grid.height
                        clip: true  // 确保内容不会超出 ScrollView 的边界

                        ListView {
                            id: listView
                            width: parent.width
                            model: blockingModel
                            delegate: Rectangle {
                                width: listView.width
                                height: 100
                                color: "#00000000"
                                border.width: 1

                                Grid {
                                    columns: 5
                                    spacing: 10

                                    Rectangle {
                                        width: 225
                                        height: 100
                                        color: "#00000000"

                                        Text {
                                            text: index + 1
                                            font.pixelSize: 30
                                            color: "white"
                                            verticalAlignment: Text.AlignVCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            anchors.fill: parent
                                        }
                                    }

                                    Rectangle {
                                        width: 350
                                        height: 100
                                        color: "#00000000"

                                        Text {
                                            text: blocking_date
                                            font.pixelSize: 30
                                            color: "white"
                                            verticalAlignment: Text.AlignVCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            anchors.fill: parent
                                        }
                                    }

                                    Rectangle {
                                        width: 350
                                        height: 100
                                        color: "#00000000"

                                        Text {
                                            text: blocking_time
                                            font.pixelSize: 30
                                            color: "white"
                                            verticalAlignment: Text.AlignVCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            anchors.fill: parent
                                        }
                                    }

                                    Rectangle {
                                        width: 350
                                        height: 100
                                        color: "#00000000"

                                        Text {
                                            text: is_unblocked ? "已取消" : "未取消"
                                            font.pixelSize: 30
                                            color: "white"
                                            verticalAlignment: Text.AlignVCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            anchors.fill: parent
                                        }
                                    }

                                    Rectangle {
                                        width: 600
                                        height: 100
                                        color: "#00000000"

                                        Text {
                                            text: blocking_message
                                            font.pixelSize: 30
                                            color: "white"
                                            verticalAlignment: Text.AlignVCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            anchors.fill: parent
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            Rectangle {
                id: rectangle1
                x: 0
                y: 0
                width: 1920
                height: 200
                color: "#00000000"

                Text {
                    id: element
                    width: 1920
                    height: 200
                    color: "#ffffff"
                    text: qsTr("故障屏蔽记录")
                    fontSizeMode: Text.Fit
                    font.bold: true
                    font.family: "Tahoma"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 90

                    Text {
                        id: timeText
                        x: 1400
                        y: 0
                        width: 520
                        height: 200 // 添加 ID 以便更新
                        // 显示到秒
                        font.pixelSize: 50
                        color: "#5bed31"
                        text: "2024-08-20 14:39:52"
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                    }

                    // 定时器每秒更新一次时间
                    Timer {
                        interval: 1000 // 每秒更新
                        running: true
                        repeat: true
                        onTriggered: {
                            timeText.text = Qt.formatDateTime(new Date(), "yyyy-MM-dd hh:mm:ss"); // 更新文本
                        }
                    }
                }
            }
        }
    }
}
