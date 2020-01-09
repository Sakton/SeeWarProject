import QtQuick 2.0
import Settings 1.0

Item {
    width: height
    height: 30
    //все роли модели
    property int indexElement: 0
    property color colorCell: "red"
    property int stateCell: 0
    property var pointerToObjectCell: null
    property string imageResource: ""

    Canvas {
        id: mycanvas
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d")
            ctx.strokeStyle = colorCell
            ctx.strokeRect(0, 0, width, height)
        }

        Image {
            //anchors.fill: parent
            width: parent.width - parent.width / 10
            height: parent.height - parent.height / 10
            source: imageResource

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                color: colorCell
                font.pixelSize: parent.width / 3
                text: indexElement
            }
        } //Image

//        Text {
//            anchors.horizontalCenter: parent.horizontalCenter
//            anchors.verticalCenter: parent.verticalCenter
//            color: "red"
//            font.pixelSize: parent.width / 3
//            text: indexElement
//        }
    }

    //    Rectangle {
    //        anchors.fill: parent
    ////        source: pointerToObjectCell.img
    //        color: {
    //            console.debug("color = ") + model.color
    //            switch(model.color) {
    //            case 0: return "black"
    //            case 1: return "blue"
    //            case 2: return "gray"
    //            }
    //        }

    //        Text {
    //            anchors.horizontalCenter: parent.horizontalCenter
    //            anchors.verticalCenter: parent.verticalCenter
    //            //color: pointerToObjectCell.color
    //            color: "red"
    //            font.pixelSize: parent.width / 3
    //            text: indexElement
    //        }
    //    }//Rectangle


}
