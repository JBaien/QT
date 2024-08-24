import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import Qt.labs.calendar 1.0

ApplicationWindow {
    id:root
    width: 1200
    height: 1920
    visible:true
    title: "HDZK ControlPanel"

    //页面显示
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
                height: 150
                color: "#00000000"

                Text {
                    id: element
                    color: "#ffffff"
                    text: qsTr("常规控制设置")
                    font.bold: true
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.fill: parent
                    font.pixelSize: 70
                }
            }

            Rectangle {
                id: rectangle1
                x: 500
                y: 170
                width: 1000
                height: 1000
                color: "#00000000"

                Grid {
                    id: grid
                    y: 0
                    width: 1920
                    height: 1000
                    rows: 10
                    columns: 2
                    anchors.fill: parent

                    //工作/调试模式
                    Label {
                        id: modelabel
                        x: 0
                        width: 600
                        height: 100
                        color: "#ffffff"
                        text: qsTr("工作/调试模式：")
                        font.pointSize: 35
                        verticalAlignment: Text.AlignVCenter
                    }

                    Button {
                        id: modeButton
                        y: 0
                        width: 250
                        height: 90
                        text: qsTr("工作")
                        spacing: 5
                        font.bold: true
                        font.family: "Arial"
                        Layout.fillWidth: true
                        font.pixelSize: 35
                        implicitWidth: 100
                        background: Rectangle {
                            color: "#7CFC00" // Bright green
                            border.color: "black" // Add border color
                            border.width: 2 // Set border width
                            radius: 10 // Rounded corners
                        }
                        onClicked: {
                            modeButton.text = modeButton.text === "工作" ? "调试" : "工作";
                        }
                    }

                    //照明系统
                    Label {
                        id: lightinglabel
                        width: 600
                        height: 100
                        color: "#ffffff"
                        text: qsTr("照明系统：")
                        font.pointSize: 35
                        verticalAlignment: Text.AlignVCenter
                    }

                    Button {
                        id: lightingButton
                        width: 250
                        height: 90
                        text: qsTr("关闭")
                        spacing: 5
                        font.bold: true
                        font.family: "Arial"
                        Layout.fillWidth: true
                        font.pixelSize: 35
                        implicitWidth: 100
                        background: Rectangle {
                            color: "#7CFC00" // Bright green
                            border.color: "black" // Add border color
                            border.width: 2 // Set border width
                            radius: 10 // Rounded corners
                        }
                        onClicked: {
                            lightingButton.text = lightingButton.text === "关闭" ? "开启" : "关闭";
                        }
                    }

                    //自动截割使能
                    Label {
                        id: autocutlabel
                        width: 600
                        height: 100
                        color: "#ffffff"
                        text: qsTr("自动截割使能：")
                        font.pointSize: 35
                        verticalAlignment: Text.AlignVCenter
                    }

                    Button {
                        id: autocutButton
                        width: 250
                        height: 90
                        text: qsTr("关闭")
                        spacing: 5
                        font.bold: true
                        font.family: "Arial"
                        Layout.fillWidth: true
                        font.pixelSize: 35
                        implicitWidth: 100
                        background: Rectangle {
                            color: "#7CFC00" // Bright green
                            border.color: "black" // Add border color
                            border.width: 2 // Set border width
                            radius: 10 // Rounded corners
                        }
                        onClicked: {
                            autocutButton.text = autocutButton.text === "关闭" ? "开启" : "关闭";
                        }
                    }

                    // 供电系统选择
                    Label {
                        id: powerlabel
                        width: 600
                        height: 100
                        color: "#ffffff"
                        text: qsTr("供电系统选择:")
                        font.pointSize: 35
                        verticalAlignment: Text.AlignVCenter
                    }

                    Button {
                        id: powerButton
                        width: 250
                        height: 90
                        text: qsTr("AC1140V")
                        spacing: 5
                        font.bold: true
                        font.family: "Times New Roman"
                        Layout.fillWidth: true
                        font.pixelSize: 35
                        implicitWidth: 100
                        background: Rectangle {
                            color: "#7CFC00" // Bright green
                            border.color: "black" // Add border color
                            border.width: 2 // Set border width
                            radius: 10 // Rounded corners
                        }
                        onClicked: {
                            powerButton.text = powerButton.text === "AC1140V" ? "AC660V" : "AC1140V";
                        }
                    }

                    // 一运正转
                    Label {
                        id: operationlabel
                        width: 600
                        height: 100
                        color: "#ffffff"
                        text: qsTr("一运正转:")
                        font.pointSize: 35
                        verticalAlignment: Text.AlignVCenter
                    }

                    Button {
                        id: operationButton1
                        width: 250
                        height: 90
                        text: qsTr("关闭")
                        spacing: 5
                        font.bold: true
                        font.family: "Arial"
                        Layout.fillWidth: true
                        font.pixelSize: 35
                        implicitWidth: 100
                        background: Rectangle {
                            color: "#7CFC00" // Bright green
                            border.color: "black" // Add border color
                            border.width: 2 // Set border width
                            radius: 10 // Rounded corners
                        }
                        onClicked: {
                            operationButton1.text = operationButton1.text === "关闭" ? "开启" : "关闭";
                        }
                    }

                    // 一运反转
                    Label {
                        id: operationlabel2
                        width: 600
                        height: 100
                        color: "#ffffff"
                        text: qsTr("一运反转:")
                        font.pointSize: 35
                        verticalAlignment: Text.AlignVCenter
                    }

                    Button {
                        id: operationButton2
                        width: 250
                        height: 90
                        text: qsTr("关闭")
                        spacing: 5
                        font.bold: true
                        font.family: "Arial"
                        Layout.fillWidth: true
                        font.pixelSize: 35
                        implicitWidth: 100
                        background: Rectangle {
                            color: "#7CFC00" // Bright green
                            border.color: "black" // Add border color
                            border.width: 2 // Set border width
                            radius: 10 // Rounded corners
                        }
                        onClicked: {operationButton2.text = operationButton2.text === "关闭" ? "开启" : "关闭";
                        }
                    }

                    // 星轮正转
                    Label {
                        id: operationlabe3
                        width: 600
                        height: 100
                        color: "#ffffff"
                        text: qsTr("星轮正转:")
                        font.pointSize: 35
                        verticalAlignment: Text.AlignVCenter
                    }

                    Button {
                        id: operationButton3
                        width: 250
                        height: 90
                        text: qsTr("关闭")
                        spacing: 5
                        font.bold: true
                        font.family: "Arial"
                        Layout.fillWidth: true
                        font.pixelSize: 35
                        implicitWidth: 100
                        background: Rectangle {
                            color: "#7CFC00" // Bright green
                            border.color: "black" // Add border color
                            border.width: 2 // Set border width
                            radius: 10 // Rounded corners
                        }
                        onClicked: {operationButton3.text = operationButton3.text === "关闭" ? "开启" : "关闭";
                        }
                    }

                // 星轮反转
                    Label {
                        id: operationlabe4
                        width: 600
                        height: 100
                        color: "#ffffff"
                        text: qsTr("星轮反转:")
                        font.pointSize: 35
                        verticalAlignment: Text.AlignVCenter
                    }

                    Button {
                        id: operationButton4
                        width: 250
                        height: 90
                        text: qsTr("关闭")
                        spacing: 5
                        font.bold: true
                        font.family: "Arial"
                        Layout.fillWidth: true
                        font.pixelSize: 35
                        implicitWidth: 100
                        background: Rectangle {
                            color: "#7CFC00" // Bright green
                            border.color: "black" // Add border color
                            border.width: 2 // Set border width
                            radius: 10 // Rounded corners
                        }
                        onClicked: {operationButton4.text = operationButton4.text === "关闭" ? "开启" : "关闭";
                        }
                    }

                // 扫描仪使能
                    Label {
                        id: scanlabel
                        width: 600
                        height: 100
                        color: "#ffffff"
                        text: qsTr("扫描仪使能:")
                        font.pointSize: 35
                        verticalAlignment: Text.AlignVCenter
                    }

                    Button {
                        id: scanButton
                        width: 250
                        height: 90
                        text: qsTr("关闭")
                        spacing: 5
                        font.bold: true
                        font.family: "Arial"
                        Layout.fillWidth: true
                        font.pixelSize: 35
                        implicitWidth: 100
                        background: Rectangle {
                            color: "#7CFC00" // Bright green
                            border.color: "black" // Add border color
                            border.width: 2 // Set border width
                            radius: 10 // Rounded corners
                        }
                        onClicked: {scanButton.text = scanButton.text === "关闭" ? "开启" : "关闭";
                        }
                    }

                //后灯状态
                    Label {
                        id: rearLightlabel
                        width: 600
                        height: 100
                        color: "#ffffff"
                        text: qsTr("后灯状态:")
                        font.pointSize: 35
                        verticalAlignment: Text.AlignVCenter
                    }

                    Button {
                        id: rearLightButton
                        width: 250
                        height: 90
                        text: qsTr("信号")
                        spacing: 5
                        font.bold: true
                        font.family: "Arial"
                        Layout.fillWidth: true
                        font.pixelSize: 35
                        implicitWidth: 100
                        background: Rectangle {
                            color: "#7CFC00" // Bright green
                            border.color: "black" // Add border color
                            border.width: 2 // Set border width
                            radius: 10 // Rounded corners
                        }
                        onClicked: {rearLightButton.text = rearLightButton.text === "信号" ? "照明" : "信号";
                        }
                    }
                }
            }

        }

    }
}

