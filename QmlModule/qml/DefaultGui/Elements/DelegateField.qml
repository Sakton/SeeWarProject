import QtQuick 2.0
import Settings 1.0

Item {
    width: height
    height: 30
    //все роли модели
    property int indexElement: 0


    Image {
        anchors.fill: parent
//        source: {
//            console.debug(model.Paluba)
//            switch(model.Paluba) {
//            case 0: return Setting.p1
//            case 1: return Setting.p2
//            case 2: return Setting.p3
//            case 3: return Setting.p4
//            default: return ""
//            }
//        }

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            color: "red"
            font.pixelSize: parent.width / 3
            text: indexElement
        }
    }//Image
}
