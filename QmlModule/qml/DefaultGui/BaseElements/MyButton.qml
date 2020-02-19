import QtQuick 2.0
import "../Settings"
//import Settings 1.0

BasicButtonClass {
    border.width: 1
    border.color: Setting.styleTextColor

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: Setting.styleTextColor
        font.pointSize: 14
        text: qsTr(name)
    }
}


