import QtQuick 2.0
import Settings 1.0
import QtQuick.Controls 2.12

Item {
    id: _root
    signal clicedIndex(int indexClick)
    property int index: 0
    property string imageResource: ""
    property int rotateAngle: 0
    property color colorCell: "black"

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
        id: _mouseArea
        anchors.fill: parent
        onClicked: {
            clicedIndex(index)
        }
    }

    AnimatedImage {
        onStatusChanged: playing = (status == AnimatedImage.Ready)
        cache: true
        width: parent.width - parent.width / 10
        height: parent.height - parent.height / 10
        source: imageResource
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        rotation: rotateAngle
    }

}
