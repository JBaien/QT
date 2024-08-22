import QtQuick 2.9
import QtQuick.Window 2.2
import Qt.labs.qmlmodels 1.0

Window {
    id: window
    width: 1280
    height: 800
    visible: true
    color: "#00000000"
    title: qsTr("main")



    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 300
        height: 150
        color: "#00000000"

        Text {
            id: element3
            x: 10
            y: 111
            width: 175
            height: 37
            text: qsTr("环境湿度：")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            textFormat: Text.PlainText
            color: "#ffffff"
            font.family: "Arial"
            font.pixelSize: 22
        }

        Text {
            id: element2
            x: 10
            y: 74
            width: 175
            height: 37
            color: "#ffffff"
            text: qsTr("环境温度：")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.family: "Arial"
            lineHeight: 0.5
            fontSizeMode: Text.FixedSize
            font.pixelSize: 22
        }

        Text {
            id: element1
            x: 10
            y: 37
            width: 175
            height: 37
            color: "#ffffff"
            text: qsTr("已屏蔽数量：")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            lineHeight: 1.6
            renderType: Text.QtRendering
            font.family: "Arial"
            textFormat: Text.AutoText
            elide: Text.ElideNone
            font.pixelSize: 22
        }

        Text {
            id: element
            x: 10
            y: 0
            width: 175
            height: 37
            color: "#ffffff"
            text: qsTr("当前故障数量：")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            textFormat: Text.AutoText
            font.family: "Arial"
            font.pixelSize: 22
        }

        Text {
            id: element68
            x: 170
            width: 30
            height: 37
            color: "#ffffff"
            text: qsTr("1")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 22
        }

        Text {
            id: element69
            x: 170
            y: 37
            width: 30
            height: 37
            color: "#ffffff"
            text: qsTr("0")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 25
        }

        Text {
            id: element70
            x: 150
            y: 74
            height: 37
            color: "#ffffff"
            text: qsTr("0.0 ℃")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 22
        }

        Text {
            id: element71
            x: 150
            y: 111
            width: 77
            height: 37
            color: "#ffffff"
            text: qsTr("0.0 %")
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 22
        }
    }

    Rectangle {
        id: rectangle1
        x: 300
        y: 0
        width: 680
        height: 150
        color: "#00000000"

        Text {
            id: element4
            x: 0
            y: 80
            width: 680
            height: 40
            color: "#ffffff"
            text: qsTr("电控系统主界面")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: "Arial"
            font.pixelSize: 35
        }

        Image {
            id: image
            x: 175
            y: 82
            width: 35
            height: 35
            source: "image/greedCycle.png"
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: element7
            y: 10
            width: 680
            height: 50
            color: "#ffffff"
            text: qsTr("EBZ160E悬臂式掘进机")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: "Arial"
            font.pixelSize: 35
        }
    }

    Rectangle {
        id: rectangle2
        x: 980
        y: 0
        width: 300
        height: 150
        color: "#00000000"

        Text {
            id: timeText
            x: 22
            y: 25
            width: 300
            height: 20 // 添加 ID 以便更新
            // 显示到秒
            font.pixelSize: 25
            color: "white"
            text: "2024-08-20 14:39:52"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: element8
            x: -50
            y: 90
            width: 350
            height: 25
            color: "#ffffff"
            text: qsTr("锁车日期：2024年8月27日10时")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 25
        }
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

    BorderImage {
        id: borderImage1
        anchors.fill: parent
        z: -1
        source: "image/menuBc.png"
    }

    BorderImage {
        id: borderImage
        x: 0
        y: 150
        width: 1280
        height: 50
        source: "image/fault.png"

        Text {
            id: element6
            x: 0
            y: 0
            width: 1280
            height: 50
            color: "#ff0000"
            text: qsTr("警告信息")
            verticalAlignment: Text.AlignVCenter
            renderType: Text.NativeRendering
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 30
        }
    }

    Rectangle {
        id: rectangle3
        x: 0
        y: 200
        width: 1280
        height: 100
        color: "#00000000"

        Grid {
            id: grid2
            width: 640
            height: 100
            columns: 8
            rows: 2







            Text {
                id: element40
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("系统电压")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }
            Text {
                id: element42
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("液压油温")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }
            Text {
                id: element43
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("液压油位")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }
            Text {
                id: element44
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("横摆角")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }
            Text {
                id: element45
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("纵摆角")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }
            Text {
                id: element46
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("泵1压力")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }

            Text {
                id: element47
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("泵2压力")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }





            Text {
                id: element48
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("行走压力")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }
            Text {
                id: element49
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("751 V")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }
            Text {
                id: element50
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("39 ℃")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }
            Text {
                id: element51
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("100 %")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }
            Text {
                id: element52
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("0.0 度")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }

            Text {
                id: element53
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("0.0 度")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }

            Text {
                id: element54
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("0.0 MPa")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 22
            }

            Text {
                id: element55
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("0.0 MPa")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }

            Text {
                id: element67
                x: 80
                width: 160
                height: 50
                color: "#ffffff"
                text: qsTr("0.0 MPa")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }
        }


    }

    Rectangle {
        id: rectangle4
        x: 0
        y: 300
        width: 1280
        height: 360
        color: "#00000000"
        border.width: 0


        Grid {
            id: grid
            x: 40
            y: 0
            width: 900
            height: 360
            rows: 6
            columns: 5

            Text {
                id: element9
                width: 180
                height: 60
                text: qsTr("电机状态")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element10
                width: 180
                height: 60
                text: qsTr("U相")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element11
                width: 180
                height: 60
                text: qsTr("V相")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element12
                width: 180
                height: 60
                text: qsTr("W相")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element13
                width: 180
                height: 60
                text: qsTr("温度")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            //第二行
            Text {
                id: element14
                width: 180
                height: 60
                text: qsTr("油泵运行")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element15
                width: 180
                height: 60
                text: qsTr("19.1 A")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element16
                width: 180
                height: 60
                text: qsTr("54.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element17
                width: 180
                height: 60
                text: qsTr("36.1 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element18
                width: 180
                height: 60
                text: qsTr("34 ℃")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            //第三行
            Text {
                id: element19
                width: 180
                height: 60
                text: qsTr("截低停止")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element20
                width: 180
                height: 60
                text: qsTr("0.0 A")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element21
                width: 180
                height: 60
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element22
                width: 180
                height: 60
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element23
                width: 180
                height: 60
                text: qsTr("34 ℃")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            //第四行
            Text {
                id: element24
                width: 180
                height: 60
                text: qsTr("截高停止")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element25
                width: 180
                height: 60
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element26
                width: 180
                height: 60
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element27
                width: 180
                height: 60
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element28
                width: 180
                height: 60
                text: qsTr("34 ℃")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            //第五行
            Text {
                id: element29
                width: 180
                height: 60
                text: qsTr("二运停止")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element30
                width: 180
                height: 60
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element31
                width: 180
                height: 60
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element32
                width: 180
                height: 60
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element33
                width: 180
                height: 60
                text: qsTr("34 ℃")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            //第六行
            Text {
                id: element34
                width: 180
                height: 60
                text: qsTr("风机停止")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element35
                width: 180
                height: 60
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element36
                width: 180
                height: 60
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element37
                width: 180
                height: 60
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }

            Text {
                id: element38
                width: 180
                height: 60
                text: qsTr("34 ℃")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 22
            }
        }

        Grid {
            id: grid3
            x: 940
            y: 0
            width: 340
            height: 100
            rows: 2
            columns: 2

            Text {
                id: element56
                width: 170
                height: 50
                color: "#ffffff"
                text: qsTr("钻锚前进距离")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }

            Text {
                id: element57
                width: 170
                height: 50
                color: "#ffffff"
                text: qsTr("左/右")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }

            Text {
                id: element58
                width: 170
                height: 50
                color: "#ffffff"
                text: "0 mm"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }

            Text {
                id: element59
                x: 95
                width: 170
                height: 50
                color: "#ffffff"
                text: "0 mm"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 22
            }
        }

        Rectangle {
            id: rectangle6
            x: 940
            y: 100
            width: 340
            height: 260
            color: "#00000000"

            Text {
                id: element60
                width: 160
                height: 60
                color: "#000000"
                text: qsTr("本地模式")
                font.family: "Tahoma"
                styleColor: "#00000000"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22

                Rectangle {
                    id: rectangle13
                    color: "#ffff00"
                    border.color: "#ffffff"
                    z: -1
                    anchors.fill: parent
                }
            }

            Text {
                id: element61
                x: 170
                width: 160
                height: 60
                color: "#ff0000"
                text: qsTr("工作模式")
                font.bold: true
                z: 1
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                lineHeight: 1.1
                fontSizeMode: Text.Fit
                renderType: Text.NativeRendering
                font.pixelSize: 20

                Rectangle {
                    id: rectangle14
                    color: "#4af570"
                    border.color: "#ffffff"
                    z: -1
                    anchors.fill: parent
                }
            }

            Text {
                id: element62
                x: 0
                y: 65
                width: 160
                height: 60
                color: "#4af570"
                text: qsTr("正在润滑")
                font.bold: true
                font.weight: Font.ExtraLight
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 22

                Rectangle {
                    id: rectangle11
                    height: 60
                    color: "#d31515"
                    radius: 0
                    border.color: "#ffffff"
                    border.width: 1
                    z: -1
                    anchors.fill: parent
                }
            }

            Text {
                id: element63
                x: 170
                y: 65
                width: 160
                height: 60
                color: "#ff0000"
                text: qsTr("掘进模式")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 22

                Rectangle {
                    id: rectangle12
                    color: "#4af570"
                    border.color: "#ffffff"
                    border.width: 1
                    z: -1
                    anchors.fill: parent
                }
            }

            Text {
                id: element64
                x: 40
                y: 130
                width: 260
                height: 60
                color: "red"
                text: qsTr("截割手动模式")
                font.family: "Times New Roman"
                font.bold: false
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22

                Rectangle {
                    id: rectangle10
                    x: 0
                    width: 260
                    color: "#4af570"
                    radius: 0
                    border.color: "#ffffff"
                    border.width: 1
                    z: -1
                    anchors.fill: parent
                }
            }

            Text {
                id: element65
                x: 40
                y: 195
                width: 260
                height: 60
                color: "#4af570"
                text: qsTr("照明已开启")
                font.bold: true
                font.family: "Times New Roman"
                styleColor: "#00000000"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 22

                Rectangle {
                    id: rectangle9
                    color: "#d31515"
                    radius: 0
                    border.color: "#ffffff"
                    border.width: 1
                    z: -1
                    anchors.fill: parent
                }
            }
        }


    }

    Rectangle {
        id: rectangle7
        x: 700
        y: 720
        width: 300
        height: 60
        color: "#00000000"

        Text {
            id: element41
            color: "#ffffff"
            text: qsTr("24小时锁车倒计时：970分")
            anchors.fill: parent
            font.family: "Times New Roman"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 22
        }
    }

    Rectangle {
        id: rectangle5
        x: 0
        y: 660
        width: 940
        height: 60
        color: "#00000000"

        Grid {
            id: grid1
            x: 40
            y: 0
            width: 900
            height: 60
            rows: 1
            columns: 2

            Text {
                id: element5
                width: 450
                height: 60
                color: "#ffffff"
                text: qsTr("总截割时间：0 时 38分")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }

            Text {
                id: element39
                width: 450
                height: 60
                color: "#ffffff"
                text: qsTr("总工作时间：1 时 25 分")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 22
            }
        }
    }

    Rectangle {
        id: rectangle8
        x: 1060
        y: 740
        width: 220
        height: 60
        color: "#00000000"

        Text {
            id: element66
            width: 220
            color: "#ffffff"
            text: qsTr("远程心跳")
            anchors.fill: parent
            font.family: "Courier"
            renderType: Text.NativeRendering
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 25
        }

        Image {
            id: image1
            x: 170
            y: 10
            width: 35
            height: 35
            fillMode: Image.PreserveAspectFit
            source: "image/greedCycle.png"
        }
    }



}























































/*##^## Designer {
    D{i:14;anchors_height:480;anchors_width:640;anchors_x:0;anchors_y:0}D{i:101;anchors_height:200;anchors_width:200}
D{i:95;anchors_height:200;anchors_width:200}D{i:99;anchors_height:200;anchors_width:200}
D{i:94;anchors_height:200;anchors_width:200}D{i:80;anchors_height:60;anchors_width:220}
D{i:86;anchors_height:30;anchors_width:150;anchors_x:0;anchors_y:0}D{i:87;anchors_height:26;anchors_width:26;anchors_x:160;anchors_y:2}
}
 ##^##*/
