import QtQuick 2.0

Rectangle{
    width: 166
    height:40
    color: "#00000000"
    property int someStatus1: 0
    property int someStatus2: 0

    Image {
        id: some_Status1
        x: 0
        y: 5
        width: 30
        height: 30
        fillMode: Image.PreserveAspectFit
        source:{switch (someStatus1) {
            case 0: return "qrc:/Image/status_red.png"
            case 1: return "qrc:/Image/status_yellow.png";
            case 2: return "qrc:/Image/status_green.png"
            default: return "";
            }
        }
    }

    Text {
        id: some_Text1
        x: 54
        y: 0
        width: 112
        height: 40
        text: switch (status) {
              case 0: return "关闭润滑";
              case 1: return "等待润滑";
              case 2: return "开始润滑";
              default: return "";
          }
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 28
        font.bold: true
        color: "#ECECEC"
    }

    Image {
        id: some_Status2
        x: 0
        y: 69
        width: 30
        height: 30
        fillMode: Image.PreserveAspectFit
        source:{switch (someStatus2) {
            case 0: return "qrc:/Image/status_red.png"
            case 1: return "qrc:/Image/status_yellow.png";
            case 2: return "qrc:/Image/status_green.png"
            default: return "";
            }
        }
    }
    Text {
        id: some_Text2
        x: 54
        y: 64
        width: 112
        height: 40
        text:switch (status) {
             case 0: return "照明已关闭";
             case 1: return "照明已开启";
             case 2: return "信号模式开启";
             default: return "";
         }
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 28
        font.bold: true
        color: "#ECECEC"
    }
}
