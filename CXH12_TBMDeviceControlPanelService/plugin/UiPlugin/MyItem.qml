import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1

Item
{
    function readValues(anArray,anObject)
    {
        for(var i = 0; i < anArray.length;i++)
        {
            console.log("Array item:",anArray[i]);
        }
        for(var prop in anObject)
        {
            console.log("Object item:",prop,"=",anObject[prop])
        }
    }
}
