import QtQuick 2.0
import Settings 1.0

Item {
    signal clicedIndex(int indexClick)
    property int index: 0

    //***
    width: 30
    height: width
//    color: Setting.styleApplicationColor
//    border.color: Setting.styleTextColor

    Text {
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        text: index
        color: Setting.styleTextColor
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            clicedIndex(index)
        }
    }

}
