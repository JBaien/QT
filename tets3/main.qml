import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    id: window
    width: 1920
    height: 1200
    visible: true
    color: "#00000000"
    title: qsTr("报警查询")

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

            Text {
                id: element1
                x: 127
                y: 199
                width: 48
                height: 33
                color: "#ffffff"
                text: qsTr("序号")
                z: 1
                font.family: "Courier"
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
                color: "#26333f"
            }

            Rectangle {
                id: rectangle
                x: 105
                y: 187
                width: 1710
                height: 1000
                color: "#00000000"
                radius: 6
                border.width: 0

                Column {
                    width: parent.width
                    height: parent.height

                    // 标题栏

                    // 内容区域
                    ScrollView {
                        width: parent.width
                        height: parent.height - grid.height
                        clip: true  // 确保内容不会超出 ScrollView 的边界

                        ListView {
                            id: listView
                            width: parent.width
                            model: alarmModel
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
                                            text: alarm_date
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
                                            text: alarm_time
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
                                            text: recover_time
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
                                            text: alarm_message
                                            font.pixelSize: 30
                                            color:  is_fault ? "red" : "yellow"
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

                    //                    Text {
                    //                        id: timeText
                    //                        x: 1400
                    //                        y: 0
                    //                        width: 520
                    //                        height: 200 // 添加 ID 以便更新
                    //                        // 显示到秒
                    //                        font.pixelSize: 50
                    //                        color: "#5bed31"
                    //                        text: "2024-08-20 14:39:52"
                    //                        verticalAlignment: Text.AlignVCenter
                    //                        horizontalAlignment: Text.AlignHCenter
                    //                    }

                    // 定时器每秒更新一次时间
                    //                    Timer {
                    //                        interval: 1000 // 每秒更新
                    //                        running: true
                    //                        repeat: true
                    //                        onTriggered: {
                    //                            timeText.text = Qt.formatDateTime(new Date(), "yyyy-MM-dd hh:mm:ss"); // 更新文本
                    //                        }
                    //                    }
                }
            }

            Rectangle{
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
                y: 1
                width: 200
                height: 52
                fillMode: Image.PreserveAspectFit
                source: "Image/title_com.png"
            }

            Text {
                id: element2
                x: 290
                y: 199
                width: 96
                height: 33
                color: "#ffffff"
                text: qsTr("触发日期")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: "Times New Roman"
                font.pixelSize: 21
            }

            Text {
                id: element3
                x: 591
                y: 199
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
                width: 312
                height: 33
                color: "#ffffff"
                text: qsTr("报警消息（报警红，恢复白）")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 24
            }



        }
    }
}
