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
        if(Screen.width > 1000)
        return 230
        else
        return Screen.width
    }
    readonly property int mainHeight: {
        if(Screen.height > 1000)
        return 460
        else
        return Screen.height
    }

    readonly property string mainTitle: "SeeWarGame"

    //models
    property var modelField: TestModelGridView {}
    property var modelFlot: TestModelShipView {}

    //colors sheme
    readonly property color styleApplicationColor: "#0d1e49"//"#0b193c"
    readonly property color styleByttonColor: "#09183e"
    readonly property color styleTextColor: "#fffc00"

    //urls
    readonly property string urlElementFigureWindow: "qrc:/QmlModule/qml/DefaultGui/BaseElements/FigureWindow.qml"
}
