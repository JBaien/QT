import QtQuick 2.9
import QtQuick.Window 2.2
import Qt.labs.qmlmodels 1.0

Window {
    id: window
    visible: true
    color: "#00000000"
    title: qsTr("Hello World")



    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 170
        height: 120
        color: "#00000000"

        Text {
            id: element3
            x: 5
            y: 87
            width: 105
            height: 20
            text: qsTr("环境湿度：")
            textFormat: Text.PlainText
            color: "#ffffff"
            font.family: "Arial"
            font.pixelSize: 15
        }

        Text {
            id: element2
            x: 5
            y: 60
            width: 105
            height: 20
            color: "#ffffff"
            text: qsTr("环境温度：")
            font.family: "Arial"
            lineHeight: 0.5
            fontSizeMode: Text.FixedSize
            font.pixelSize: 15
        }

        Text {
            id: element1
            x: 5
            y: 35
            width: 105
            height: 20
            color: "#ffffff"
            text: qsTr("已屏蔽数量：")
            lineHeight: 1.6
            renderType: Text.QtRendering
            font.family: "Arial"
            textFormat: Text.AutoText
            elide: Text.ElideNone
            font.pixelSize: 15
        }

        Text {
            id: element
            x: 5
            y: 10
            height: 20
            color: "#ffffff"
            text: qsTr("当前故障数量：")
            textFormat: Text.AutoText
            font.family: "Arial"
            font.pixelSize: 15
        }
    }

    Rectangle {
        id: rectangle1
        x: 170
        y: 0
        width: 300
        height: 120
        color: "#00000000"

        Text {
            id: element4
            x: 50
            y: 60
            width: 180
            height: 40
            color: "#ffffff"
            text: qsTr("电控系统主界面")
            font.family: "Arial"
            font.pixelSize: 25
        }

        Image {
            id: image
            x: 10
            y: 67
            width: 26
            height: 26
            source: "image/greedCycle.png"
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: element7
            y: 10
            color: "#ffffff"
            text: qsTr("EBZ160E悬臂式掘进机")
            font.family: "Arial"
            font.pixelSize: 26
        }
    }

    Rectangle {
        id: rectangle2
        x: 470
        y: 0
        width: 170
        height: 120
        color: "#00000000"

        Text {
            id: timeText
            x: 0
            y: 10
            width: 170
            height: 20 // 添加 ID 以便更新
            // 显示到秒
            font.pixelSize: 18
            color: "white"
            text: "2024-08-20 14:39:52"
        }

        Text {
            id: element8
            x: -55
            y: 75
            height: 25
            color: "#ffffff"
            text: qsTr("锁车日期：2024年8月27日10时")
            font.pixelSize: 16
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
        x: 0
        y: 0
        width: 640
        height: 480
        z: -1
        source: "image/menuBc.png"
    }

    BorderImage {
        id: borderImage
        x: 0
        y: 120
        width: 640
        height: 30
        source: "image/fault.png"

        Text {
            id: element6
            x: -15
            y: 0
            width: 640
            height: 30
            color: "#ff0000"
            text: qsTr("警告信息")
            renderType: Text.NativeRendering
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 20
        }
    }

    Rectangle {
        id: rectangle3
        x: 0
        y: 150
        width: 640
        height: 70
        color: "#00000000"

        Grid {
            id: grid2
            width: 640
            height: 70
            columns: 8
            rows: 2







            Text {
                id: element40
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("系统电压")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }
            Text {
                id: element42
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("液压油温")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }
            Text {
                id: element43
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("液压油位")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }
            Text {
                id: element44
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("横摆角")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }
            Text {
                id: element45
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("纵摆角")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }
            Text {
                id: element46
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("泵1压力")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }

            Text {
                id: element47
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("泵2压力")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }





            Text {
                id: element48
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("行走压力")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }
            Text {
                id: element49
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("751 V")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }
            Text {
                id: element50
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("39 ℃")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }
            Text {
                id: element51
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("100 %")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }
            Text {
                id: element52
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("0.0 度")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }

            Text {
                id: element53
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("0.0 度")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }

            Text {
                id: element54
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("0.0 MPa")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 16
            }

            Text {
                id: element55
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("0.0 MPa")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }

            Text {
                id: element67
                x: 80
                width: 80
                height: 35
                color: "#ffffff"
                text: qsTr("0.0 MPa")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }
        }


    }

    Rectangle {
        id: rectangle4
        x: 0
        y: 220
        width: 640
        height: 180
        color: "#00000000"
        border.width: 0


        Grid {
            id: grid
            x: 40
            y: 0
            width: 390
            height: 180
            rows: 6
            columns: 5

            Text {
                id: element9
                width: 78
                height: 30
                text: qsTr("电机状态")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element10
                width: 78
                height: 30
                text: qsTr("U相")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element11
                width: 78
                height: 30
                text: qsTr("V相")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element12
                width: 78
                height: 30
                text: qsTr("W相")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element13
                width: 78
                height: 30
                text: qsTr("温度")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            //第二行
            Text {
                id: element14
                width: 78
                height: 30
                text: qsTr("油泵运行")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element15
                width: 78
                height: 30
                text: qsTr("19.1 A")
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element16
                width: 78
                height: 30
                text: qsTr("54.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element17
                width: 78
                height: 30
                text: qsTr("36.1 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element18
                width: 78
                height: 30
                text: qsTr("34 ℃")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            //第三行
            Text {
                id: element19
                width: 78
                height: 30
                text: qsTr("截低停止")
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element20
                width: 78
                height: 30
                text: qsTr("0.0 A")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element21
                width: 78
                height: 30
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element22
                width: 78
                height: 30
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element23
                width: 78
                height: 30
                text: qsTr("34 ℃")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            //第四行
            Text {
                id: element24
                width: 78
                height: 30
                text: qsTr("截高停止")
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element25
                width: 78
                height: 30
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element26
                width: 78
                height: 30
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element27
                width: 78
                height: 30
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element28
                width: 78
                height: 30
                text: qsTr("34 ℃")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            //第五行
            Text {
                id: element29
                width: 78
                height: 30
                text: qsTr("二运停止")
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element30
                width: 78
                height: 30
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element31
                width: 78
                height: 30
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element32
                width: 78
                height: 30
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element33
                width: 78
                height: 30
                text: qsTr("34 ℃")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            //第六行
            Text {
                id: element34
                width: 78
                height: 30
                text: qsTr("风机停止")
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element35
                width: 78
                height: 30
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element36
                width: 78
                height: 30
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element37
                width: 78
                height: 30
                text: qsTr("0.0 A")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }

            Text {
                id: element38
                width: 78
                height: 30
                text: qsTr("34 ℃")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                font.pixelSize: 18
            }
        }

        Grid {
            id: grid3
            x: 436
            y: 0
            width: 184
            height: 60
            rows: 2
            columns: 2

            Text {
                id: element56
                width: 95
                height: 30
                color: "#ffffff"
                text: qsTr("钻锚前进距离")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 18
            }

            Text {
                id: element57
                width: 95
                height: 30
                color: "#ffffff"
                text: qsTr("左/右")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 18
            }

            Text {
                id: element58
                width: 95
                height: 30
                color: "#ffffff"
                text: "0 mm"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 18
            }

            Text {
                id: element59
                x: 95
                width: 95
                height: 30
                color: "#ffffff"
                text: "0 mm"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 18
            }
        }

        Rectangle {
            id: rectangle6
            x: 430
            y: 60
            width: 180
            height: 140
            color: "#00000000"

            Text {
                id: element60
                width: 90
                height: 35
                color: "#ffffff"
                text: qsTr("本地模式")
                font.family: "Tahoma"
                styleColor: "#00000000"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 18
            }

            Text {
                id: element61
                x: 90
                width: 90
                height: 35
                color: "#ffffff"
                text: qsTr("工作模式")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                lineHeight: 1.1
                fontSizeMode: Text.Fit
                renderType: Text.NativeRendering
                font.pixelSize: 18
            }

            Text {
                id: element62
                x: 0
                y: 35
                width: 90
                height: 35
                color: "#ffffff"
                text: qsTr("正在润滑")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 18
            }

            Text {
                id: element63
                x: 90
                y: 35
                width: 90
                height: 35
                color: "#ffffff"
                text: qsTr("掘进模式")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 18
            }

            Text {
                id: element64
                y: 70
                width: 180
                height: 35
                color: "#ffffff"
                text: qsTr("截割手动模式")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 18
            }

            Text {
                id: element65
                y: 105
                width: 180
                height: 35
                color: "#ffffff"
                text: qsTr("照明已开启")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 18
            }
        }


    }

    Rectangle {
        id: rectangle7
        x: 300
        y: 440
        width: 150
        height: 40
        color: "#00000000"

        Text {
            id: element41
            width: 150
            height: 40
            color: "#ffffff"
            text: qsTr("24小时锁车倒计时：970分")
            font.family: "Times New Roman"
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 18
        }
    }

    Rectangle {
        id: rectangle5
        x: 0
        y: 400
        width: 640
        height: 40
        color: "#00000000"

        Grid {
            id: grid1
            x: 40
            y: 0
            width: 390
            height: 40
            rows: 1
            columns: 2

            Text {
                id: element5
                width: 195
                height: 40
                color: "#ffffff"
                text: qsTr("总截割时间：0 时 38分")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 18
            }

            Text {
                id: element39
                width: 195
                height: 40
                color: "#ffffff"
                text: qsTr("总工作时间：1 时 25 分")
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 18
            }
        }
    }

    Rectangle {
        id: rectangle8
        x: 450
        y: 450
        width: 190
        height: 30
        color: "#00000000"

        Text {
            id: element66
            x: 0
            y: 0
            width: 150
            height: 30
            color: "#ffffff"
            text: qsTr("远程心跳")
            font.family: "Courier"
            renderType: Text.NativeRendering
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 18
        }

        Image {
            id: image1
            x: 160
            y: 2
            width: 26
            height: 26
            fillMode: Image.PreserveAspectFit
            source: "image/greedCycle.png"
        }
    }



}

























































/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:20;anchors_height:480;anchors_width:640;anchors_x:0;anchors_y:0}
D{i:22;anchors_height:60;anchors_width:1720;anchors_x:"-15";anchors_y:0}D{i:70;anchors_height:30;anchors_width:80}
D{i:31;anchors_height:200;anchors_width:640;anchors_x:0;anchors_y:210}
}
 ##^##*/
