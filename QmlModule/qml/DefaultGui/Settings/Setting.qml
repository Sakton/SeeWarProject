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
    //перечисление
    enum MyEnumButton {
        //Стартовое меню
        BUTTON_ANDROID = 0,
        BUTTON_NETWORK,
        BUTTON_CUSTOMIZATION,
        //Расстановка
        BUTTON_GAME = 10,
        BUTTON_EDITING,
        BUTTON_DISCHARGE,
        BUTTON_AUTOALIGMENT,
        BUTTON_REPEAT,
        //общая
        BUTTON_BACK
    }

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
    readonly property real hintButtonBottomMargins: 3

    //models
    property var modelField: TestModelGridView {}
    property var modelFlot: TestModelShipView {}

    //colors sheme
    readonly property color styleApplicationColor: "#1c1c1c"//"#0d1e49"//"#0b193c"
    readonly property color styleByttonColor: "#000000"//"#09183e"
    readonly property color styleTextColor: "#fffc00"
    readonly property color styleLogYourColor: "#03ff5c"
    readonly property color styleLogHiColor: "#0086f8"

    //urls Window
    readonly property string startMenuWindow: "qrc:/QmlModule/qml/DefaultGui/ModeWindow/StartMenu.qml"
    readonly property string arragementWindow: "qrc:/QmlModule/qml/DefaultGui/ModeWindow/Arragement.qml"
    readonly property string gameModeWindow: "qrc:/QmlModule/qml/DefaultGui/ModeWindow/GameMode.qml"

    //urls
    readonly property string urlElementFigureWindow: "qrc:/QmlModule/qml/DefaultGui/BaseElements/FigureWindow.qml"
    readonly property string urlBackgroundBlackWater: "qrc:/QmlModule/qml/DefaultGui/img/blackWater1.gif"
    readonly property string rotateImg: "qrc:/QmlModule/qml/DefaultGui/img/rtt1.png"
    readonly property string okImg: "qrc:/QmlModule/qml/DefaultGui/img/ok.png"
    readonly property string refreshImg: "qrc:/QmlModule/qml/DefaultGui/img/Symbols-Delete-icon.png"
    readonly property string playImg: "qrc:/QmlModule/qml/DefaultGui/img/play2.png"
    readonly property string editImg: "qrc:/QmlModule/qml/DefaultGui/img/Edit1.png"
    readonly property string robotImg: "qrc:/QmlModule/qml/DefaultGui/img/robot.png"

    //ship urls
    readonly property string p1: "qrc:/QmlModule/qml/DefaultGui/img/Palybs/types1/types1_01.png"
    readonly property string p2: "qrc:/QmlModule/qml/DefaultGui/img/Palybs/types1/types1_02.gif"
    readonly property string p3: "qrc:/QmlModule/qml/DefaultGui/img/Palybs/types1/types1_03.gif"
    readonly property string p4: "qrc:/QmlModule/qml/DefaultGui/img/Palybs/types1/types1_04.png"


    //sprites
    readonly property string ship1: "qrc:/QmlModule/qml/DefaultGui/img/1xb1.png"
    readonly property string ship2: "qrc:/QmlModule/qml/DefaultGui/img/2xb1.png"
    readonly property string ship3: "qrc:/QmlModule/qml/DefaultGui/img/3xb1.png"
    readonly property string ship4: "qrc:/QmlModule/qml/DefaultGui/img/4xb1.png"
    //
    readonly property int kRadius: 20
}
