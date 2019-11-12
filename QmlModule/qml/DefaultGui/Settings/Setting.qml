pragma Singleton

import QtQuick 2.0
import "../ModeWindow"

QtObject {
    //main window
    readonly property int mainWidth: 230
    readonly property int mainHeight: 460
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
