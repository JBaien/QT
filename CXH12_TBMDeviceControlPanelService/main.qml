import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
//对于浮点数，显示小数点后2位
Window
{
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
                    //掘进机型号
                    Text
                    {
                        id:devType
                        height:rectangle0.height
                        anchors.centerIn: rectangle0
                        font.pixelSize : height / 2
                        verticalAlignment: Text.AlignVCenter
                        text:Ui.uiData_system_car_type + "掘进机:" + Ui.uiData_system_car_number + " "
                    }

                    //通信状态
                    property string myCommStr: Ui.commStatus ? "正常": "未连接"
                    Text
                    {
                        id:commText
                        height:rectangle0.height
                        anchors.right:rectangle0.right
                        font.pixelSize : height / 2
                        color:Ui.commStatus ? "green": "red"
                        text: "通讯：" + rectangle0.myCommStr
                        verticalAlignment: Text.AlignVCenter
                        onTextChanged:function(text) //文本改变时打印
                        {
                            console.log("通讯状态：",Ui.commStatus)
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
                    //显示掘进机信息
                    //第一列
                    Column
                    {

                        Rectangle
                        {
                            id:rectangle1_rectangle0_0
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:0
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"油泵工作状态：" + Ui.uiData_pumpOilMotor_work_status
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle0_1
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:0
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"油泵A相电流：" + (Ui.uiData_pumpOilMotor_current_A).toLocaleString() + " A"
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle0_2
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:0
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"油泵B相电流：" + (Ui.uiData_pumpOilMotor_current_B).toLocaleString() + " A"
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle0_3
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:0
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"油泵C相电流：" + (Ui.uiData_pumpOilMotor_current_C).toLocaleString() + " A"
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle0_4
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:0
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"油泵绕组温度：" + (Ui.uiData_pumpOilMotor_wind_temp).toLocaleString() + " °C"
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle0_5
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:0
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"冷却水压力：" + (Ui.uiData_system_cool_water_pressure).toLocaleString()
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle0_6
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:0
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"冷却水流量：" + (Ui.uiData_system_cool_water_flow_calculate).toLocaleString()
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle0_7
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:0
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"油箱温度：" + (Ui.uiData_system_fuel_tank_temp).toLocaleString() + " °C"
                            }
                        }
                    }

                    //第二列
                    Column
                    {
                        Rectangle
                        {
                            id:rectangle1_rectangle1_0
                            width:rectangle1.width / 4 * 2
                            height:rectangle1.height / 8
                            x:rectangle1.width / 4
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"截割模式" + Ui.uiData_system_auto_manual_cut_status
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle1_1
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:rectangle1.width / 4
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"系统电压：" + (Ui.uiData_system_system_voltage).toLocaleString() + "V"
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle1_2
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:rectangle1.width / 4
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"瓦斯浓度：" + (Ui.uiData_system_gas_density).toLocaleString() + "%"
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle1_3
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:rectangle1.width / 4
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"粉尘浓度:" + (Ui.uiData_system_dust_density).toLocaleString() + "%"
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle1_4
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:rectangle1.width / 4
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"左前激光距离:" + Ui.uiData_system_left_forward_laser_distance
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle1_5
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:rectangle1.width / 4
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"左后激光距离:" + Ui.uiData_system_left_backward_laser_distance
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle1_6
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:rectangle1.width / 4
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"右前激光距离:" + Ui.uiData_system_right_forward_laser_distance
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle1_7
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:rectangle1.width / 4
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"右后激光距离:" + Ui.uiData_system_right_backward_laser_distance
                            }
                        }
                    }
                    //第三列
                    Column
                    {
                        Rectangle
                        {
                            id:rectangle1_rectangle2_0
                            width:rectangle1.width / 4 * 2
                            height:rectangle1.height / 8
                            x:rectangle1.width / 2
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"水泵状态：" + Ui.uiData_system_waterPump_work_status
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle2_1
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:rectangle1.width / 2
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"铲板状态：" + Ui.uiData_system_shoveBlade_work_status
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle2_2
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:rectangle1.width / 2
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"后支撑状态：" + Ui.uiData_system_rearSupport_work_status
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle2_3
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:rectangle1.width / 2
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"一运状态:" + Ui.uiData_system_transport_1_motor_work_status
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle2_4
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:rectangle1.width / 2
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"二运状态:" + Ui.uiData_system_transport_2_motor_work_status
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle2_5
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:rectangle1.width / 2
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"截割状态:" + Ui.uiData_system_cut_motor_work_status
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle2_6
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:rectangle1.width / 2
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"截高状态:" + Ui.uiData_highCutMotor_work_status
                            }
                        }
                        Rectangle
                        {
                            id:rectangle1_rectangle2_7
                            width:rectangle1.width / 4
                            height:rectangle1.height / 8
                            x:rectangle1.width / 2
                            Text
                            {
                                font.pixelSize : parent.height / 3
                                text:"截低状态:" + Ui.uiData_lowCutMotor_work_status
                            }
                        }
                    }
                    //按键警告
                    property string myDataValidFlag:Ui.dataValidFlag ? "": "警告：请复位按键！"
                    Text
                    {
                        id:keyWarning
                        height:rectangle0.height
                        x:rectangle1.width /4 * 3
                        y:rectangle1.height / 2 - 200
                        font.pixelSize : height / 3
                        verticalAlignment: Text.AlignVCenter
                        text:rectangle1.myDataValidFlag
                        color:rectangle1.myDataValidFlag ? "red": "green"
                    }
                    //显示操作台指令
                    Text
                    {
                        id:rectangle1_keyText
                        width:rectangle1.width / 4
                        height:rectangle1.height
                        x:rectangle1.width /4 * 3
                        y:(rectangle1.height - rectangle0.height) / 2
//                        anchors.centerIn: parent
                        font.pixelSize : parent.height / 8
//                        text:Ui.springBackCmd + "：" + Ui.cmdText
                        color:rectangle1.myDataValidFlag ? "red": "green"
                        text: Ui.cmdText
                        onTextChanged:function(text)
                        {
                            console.log("指令值:",Ui.springBackCmd)
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
                    //显示时间信息
                    Timer
                    {
                        id:timeTimer
                        interval:1000
                        running:true
                        repeat:true
                        onTriggered:currentTime.text = new Date().toLocaleString(Qt.LocalDate)
                    }
                    Text
                    {
                        id:currentTime
                        anchors.centerIn: rectangle2.Center
                        font.pixelSize: rectangle2.height / 4
                        text:new Date().toLocaleDateString(Qt.LocalDate) //中文时间
                    }

                    //显示报警信息
                    //显示版本
                    Text
                    {
                        font.pixelSize : rectangle2.height / 4
                        anchors.right:rectangle2.right
                        text:Ui.version

                    }
                }
        }
    }

}
