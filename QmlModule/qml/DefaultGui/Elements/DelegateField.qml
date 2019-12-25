import QtQuick 2.0
import Settings 1.0

Item {
    width: height
    height: 30
    //все роли модели
    property int indexElement: 0
    property color colorCell: "red"
    property var pointerToObjectCell : null


    Image {
        anchors.fill: parent
        source: pointerToObjectCell.img

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            color: pointerToObjectCell.color
            font.pixelSize: parent.width / 3
            text: indexElement
        }
    }//Image
}
