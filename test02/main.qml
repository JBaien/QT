import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 1280
    height: 800
    title: "EBZ280E Coal Mining Machine Control Panel"

    Rectangle {
        width: parent.width
        height: parent.height
        color: "#002D6C" // 深蓝色背景

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20
            spacing: 10

            // 标题和时间行
            RowLayout {
                spacing: 10
                width: parent.width

                Text {
                    text: "EBZ280E悬臂式掘进机"
                    font.pixelSize: 32
                    color: "white"
                    Layout.fillWidth: true
                    Layout.alignment: Text.AlignHCenter
                }

                Item {
                    width: 500 // 间隔 100pt
                }

                Text {
                    id: timeText // 添加 ID 以便更新
                    text: Qt.formatDateTime(new Date(), "yyyy-MM-dd hh:mm:ss") // 显示到秒
                    font.pixelSize: 24
                    color: "white"
                    Layout.fillWidth: true
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

            // 警告区域
            Rectangle {
                width: parent.width
                height: 60
                border.width: 2
                radius: 5
                color: "transparent"
                Layout.alignment: Qt.AlignHCenter
//                Layout.topMargin: 65 // 向下移动 65pt

                Text {
                    text: "液压油位低报警"
                    font.pixelSize: 28
                    color: "red"
                    anchors.centerIn: parent
                }
            }

            // 数据网格区域（系统电压、液压油温等）
            GridLayout {
                columns: 6
                rowSpacing: 10
                columnSpacing: 20
                Layout.fillWidth: true
                Layout.fillHeight: true

                // 第一行（标题）
                Text { text: "系统电压"; color: "white"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "液压油温"; color: "white"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "液压油位"; color: "white"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "掘锚角"; color: "white"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "锲板倾角X/Y"; color: "white"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "粉尘浓度"; color: "white"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }

                // 第二行（数值）
                Text { text: "1189V"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "42℃"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "45%"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "0.0"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "58.3/58.2"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "0 mg/m³"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
            }

            // 电机状态区域（包括详细电机数据）
            GridLayout {
                columns: 5
                rowSpacing: 10
                columnSpacing: 20
                Layout.fillWidth: true
                Layout.topMargin: 20

                // 标题行
                Text { text: "电机状态"; color: "white"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "U相"; color: "white"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "V相"; color: "white"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "W相"; color: "white"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "温度"; color: "white"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }

                // 数据行（电机状态和对应的电流/温度）
                Text { text: "油泵运行"; color: "red"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "39.1 A"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "41.3 A"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "41.4 A"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "31℃"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }

                Text { text: "截低停止"; color: "yellow"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "57.1 A"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "56.7 A"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "41.0 A"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "32℃"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }

                Text { text: "截高运行"; color: "green"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "60.2 A"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "59.8 A"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "58.7 A"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "35℃"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }

                Text { text: "二运停止"; color: "yellow"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "45.0 A"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "44.8 A"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "44.7 A"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "33℃"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }

                Text { text: "风机停止"; color: "yellow"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "50.1 A"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "50.0 A"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "49.8 A"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
                Text { text: "34℃"; color: "#00FFFF"; font.pixelSize: 24; Layout.alignment: Qt.AlignHCenter }
            }

            // 模式和报警区域
            RowLayout {
                width: parent.width
                spacing: 10
                anchors.topMargin: 20

                Rectangle {
                    width: 150
                    height: 80
                    color: "#00B050" // 绿色背景
                    border.color: "white"
                    border.width: 2
                    radius: 5

                    Text {
                        anchors.centerIn: parent
                        text: "本地模式"
                        font.pixelSize: 24
                        color: "white"
                    }
                }

                Rectangle {
                    width: 150
                    height: 80
                    color: "#FF0000" // 红色背景
                    border.color: "white"
                    border.width: 2
                    radius: 5

                    Text {
                        anchors.centerIn: parent
                        text: "正锚清理"
                        font.pixelSize: 24
                        color: "white"
                    }
                }

                Rectangle {
                    width: 150
                    height: 80
                    color: "#FFFF00" // 黄色背景
                    border.color: "white"
                    border.width: 2
                    radius: 5
                    Layout.alignment: Qt.AlignHCenter

                    Text {
                        anchors.centerIn: parent
                        text: "备用模式"
                        font.pixelSize: 24
                        color: "black"
                    }
                }

                // 根据需要添加更多状态框
            }
        }
    }
}
