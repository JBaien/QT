import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property int time:0
    Timer
    {
        id:timer
        running:true
        interval:20000
        repeat:true
        onTriggered:
            time += 1

    }
    Text
    {
        id:txt
        text:time
        font.pixelSize: 68
    }
}





/*
import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1
//import uiModel 1.0

Window
{
    id:root
    visible:true
    width:Screen.desktopAvailableWidth
    height:Screen.desktopAvailableHeight
    onWidthChanged:console.log("width_root:",root.width)
    onHeightChanged:console.log("height_root:",root.height)
    title: "HDZK ControlPanel"
    property int time:0

    Timer
    {
        id:timer
        running:true
        interval:20000
        repeat:true
        onTriggered:
            time += 1

    }
    Text
    {
        id:txt
        text:time
        font.pixelSize: 68
    }

//    UiPlugin
//    {
//        id:uiModel
//        onCommValueChanged:console.log("for test",uiModel.commValue)
//    }
//    Rectangle
//    {
//        width: 500
//        height: 500
//        Text
//        {
//            text:uiModel.commValue
//            height:200
//            font.pixelSize : height / 2
//            color:"red"
//        }
//    }


    Item
    {
        id:rootItem
        anchors.fill: parent
//        rotation:270
        property int a;
        Column
        {
            //第一栏
                Rectangle
                {
                    id:rectangle0
                    width: rootItem.width
                    height: (rootItem.height / 8)
                    border.color: "blue"

                    //logo图标
                    Image
                    {
                        id:logo
                        anchors.leftMargin: 5
                        width:logo.height
                        height:rectangle0.height
                        source:"Image/hdzk2.png"
                        fillMode: Image.PreserveAspectCrop
                    }
                    //通信状态
                    property int myComm:0
                    focus:myComm? true :false
                    property string myCommStr: focus ? "正常": "未连接"
                    property alias myCommStatus:rectangle0.myComm
                    Text
                    {
                        id:commText
                        height:rectangle0.height
                        anchors.right:rectangle0.right
                        font.pixelSize : height / 2
                        color:rectangle0.focus ? "green": "red"
                        text: "通讯：" + rectangle0.myCommStr
                        verticalAlignment: Text.AlignVCenter
                        onTextChanged:function(text) //文本改变时打印
                        {
                            console.log("a:",rootItem.a)
                        }
                    }
                }
            //第二栏
                Rectangle
                {
                    id:rectangle1
                    width: rootItem.width
                    height: (rootItem.height / 8 * 6 )
                    border.color:"green"

                    //显示指令
                    property int cmd:0
                    property string myCmd:"指令信息"
                    Text
                    {
                        anchors.centerIn: parent
                        font.pixelSize : parent.height / 10
                        text:rectangle1.cmd + "：" + rectangle1.myCmd
                        onTextChanged:function(text)
                        {
                            console.log("cmd text changed to:",text)
                        }
                    }
                    //显示动态图
                }
            //第三栏
                Rectangle
                {
                    id:rectangle2
                    width: rootItem.width
                    height: (rootItem.height / 8)
                    border.color:"red"
                    Text
                    {
                        text:"for test2"
                        onTextChanged:
                        {
                            console.log("new text",text)
                        }
                    }
                }
        }
    }

}
*/
