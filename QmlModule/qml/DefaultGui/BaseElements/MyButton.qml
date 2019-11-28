import QtQuick 2.0
import Settings 1.0

Rectangle {
    width: 40
    height: 20
    property string name: ""
    property int typeButton: 0
    signal buttonClicked(int typeButton)

    border.width: 1
    border.color: Setting.styleTextColor

    color: Setting.styleByttonColor
    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        color: Setting.styleTextColor
        font.pointSize: 14
        text: qsTr(name)
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            buttonClicked(typeButton)
        }
    }
}
