import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
// Rectangle{
//     width: 1200
//     height: 1920
//     visible: true
ApplicationWindow {
    id: window
    visible: true
    width: 1200
    height: 1920
    title: qsTr("main.qml")
    property int currentSelectedIndex: 0
    Item
    {
        id:item_win
        width: window.height
        height: window.width
        anchors.centerIn: parent
        visible: true
        rotation: 270
        // header: ToolBar
        ToolBar
        {
            contentHeight: item.implicitHeight
            Item
            {
                id: item
                width: 40
                height: 40
                Text
                {
                    anchors.centerIn: parent
                    text: stackView.depth > 1 ? "\u25C0" : "\u2630"
                    font.pixelSize: Qt.application.font.pixelSize * 1.6
                }
                //处理信号
                Connections
                {
                    target:Ui
                    //返回按键
                    function onGoBackPressed()
                    {
                        drawer.visible ? drawer.close() : drawer.open()
                    }
                    //向上按键
                    function onDirectionUpPressed()
                    {
                        moveSelection(-1)
                    }
                    //向下按键
                    function onDirectionDownPressed()
                    {
                        moveSelection(1)
                    }
                    //确认按键
                    function onConfirmPressed()
                    {
                        if (drawer.visible)
                        {
                            openSelectedPage()
                        }
                    }
                }
            }
            Label
            {
                text: stackView.currentItem.title
                anchors.centerIn: parent
            }
        }

        Drawer
        {
            id: drawer
            edge: Qt.TopEdge
            width: window.width
            height: window.height*0.2
            property int currentIndex: 0
            onClosed:
            {
                currentIndex = 0
            }
            Item
            {
                id:item_drawer
                width:parent.height
                height: parent.width
                rotation: 270
                anchors.centerIn: parent
                Column
                {
                    id: drawerColumn
                    anchors.fill: parent

                    Repeater
                    {
                        model: ListModel
                        {
                            ListElement { name: "cutSet"; title: "截割设置页面" }
                            ListElement { name: "normalCtrl"; title: "正常控制页面" }
                            ListElement { name: "parameterSet"; title: "参数设置页面" }
                            ListElement { name: "timeDecode"; title: "时间解码页面" }
                            ListElement { name: "carNumSet"; title: "车号设置页面" }
                            ListElement { name: "alarmEnquiries"; title: "报警查询页面" }
                            ListElement { name: "faultMask"; title: "故障屏蔽页面" }
                            ListElement { name: "maskRecord"; title: "屏蔽记录页面" }
                            ListElement { name: "IOMonitor"; title: "IO监控页面" }
                        }

                        delegate: ItemDelegate
                        {
                            id: menuItem
                            property string source: model.name + ".qml"
                            text: qsTr(model.title)
                            width: parent.width
                            highlighted: ListView.isCurrentItem
                            // onClicked: openPage(source)

                            background: Rectangle
                            {
                                color: menuItem.highlighted ? "#e0e0e0" : "transparent"
                            }

                            contentItem: Text {
                                text: menuItem.text
                                color: menuItem.highlighted ? "#000000" : "#666666"
                                font.bold: menuItem.highlighted
                                verticalAlignment: Text.AlignVCenter
                                leftPadding: 10
                            }
                        }
                    }
                }
            }
        }
        StackView {
            id: stackView
            initialItem: "homePage.qml"
            anchors.fill: parent
        }

        function moveSelection(direction)
        {
            if (drawer.visible)
            {
                var newIndex = currentSelectedIndex + direction
                if (newIndex >= 0 && newIndex < drawerColumn.children.length) {
                    currentSelectedIndex = newIndex
                    drawerColumn.children[currentSelectedIndex].forceActiveFocus()
                    drawerColumn.children[currentSelectedIndex].highlighted = true
                    // 取消其他项目的高亮
                    for (var i = 0; i < drawerColumn.children.length; i++) {
                        if (i !== currentSelectedIndex) {
                            drawerColumn.children[i].highlighted = false
                        }
                    }
                }
            }
        }

        function openSelectedPage()
        {
            var selectedItem = drawerColumn.children[currentSelectedIndex]
            if (selectedItem && selectedItem.source)
            {
                openPage(selectedItem.source)
            }
        }

        function openPage(source)
        {
            stackView.push(source)
            drawer.close()
        }
    }
}
// }
