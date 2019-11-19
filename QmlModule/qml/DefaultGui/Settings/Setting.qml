pragma Singleton

import QtQuick 2.0
import QtQuick.Window 2.13
import "../ModeWindow"

QtObject {
    //не работает ****
    readonly property real dpi: Screen.pixelDestiny * 25.4
    function dp(x){
        if(dpi < 120) {
            return x; // Для обычного монитора компьютера
        } else {
            return x*(dpi/160);
        }
    }
    //***** Screen.pixelDestiny = undefined ????

    //main window
    readonly property int mainWidth: {
//        console.debug(Screen.width)

        if(Screen.width > 1000)
        return 360
        else
        return Screen.width
    }
    readonly property int mainHeight: {
//        console.debug(Screen.height)
        if(Screen.height > 1000)
        return 687
        else
        return Screen.height
    }
    readonly property string mainTitle: "SeeWarGame"

    //counts
    readonly property int countsCells: 9

    //models
    property var modelField: TestModelGridView {}
    property var modelFlot: TestModelShipView {}

    //colors sheme
    readonly property color styleApplicationColor: "#1c1c1c"//"#0d1e49"//"#0b193c"
    readonly property color styleByttonColor: "#000000"//"#09183e"
    readonly property color styleTextColor: "#fffc00"

    //urls
    readonly property string urlElementFigureWindow: "qrc:/QmlModule/qml/DefaultGui/BaseElements/FigureWindow.qml"
}
