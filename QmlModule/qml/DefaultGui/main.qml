import QtQuick 2.12
import QtQuick.Window 2.12
import Settings 1.0
import "ModeWindow"

//Window {
//    visible: true
//    width: 460 //1200 / 2.6
//    height: 230 //600 / 2.6
//    title: ("mobWindow DefaultGui")
//    color: Setting.styleApplicationColor

////    StartMenu {
////        anchors.fill: parent
////    }

//    Arragement {
//        anchors.fill: parent
//    }
//}


Window {
    visible: true
    width: 230 //1200 / 2.6
    height: 460 //600 / 2.6
    title: ("mobWindow DefaultGui")
    color: Setting.styleApplicationColor

//    StartMenu {
//        anchors.fill: parent
//    }

    Arragement {
        anchors.fill: parent
    }
}
