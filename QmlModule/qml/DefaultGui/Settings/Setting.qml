pragma Singleton

import QtQuick 2.0
import QtQuick.Window 2.13
import "../ModeWindow"

//import CppClassesToQmlModules 1.0
QtObject {
    //не работает ****
    readonly property real dpi: Screen.pixelDestiny * 25.4
    function dp(x) {
        if (dpi < 120) {
            return x // Для обычного монитора компьютера
        } else {
            return x * (dpi / 160)
        }
    }
    //***** Screen.pixelDestiny = undefined ????

    //перечисление
    enum MyEnumButton {
        //никакая кнопка
        BUTTON_RESERVE = 0,
        //Стартовое меню
        BUTTON_ANDROID = 1,
        BUTTON_NETWORK,
        BUTTON_CUSTOMIZATION,
        //Расстановка
        BUTTON_GAME = 10,
        BUTTON_EDITING,
        BUTTON_DISCHARGE,
        BUTTON_AUTOALIGMENT,
        BUTTON_REPEAT,
        //общая
        BUTTON_BACK = 20,
        BUTTON_AGAIN
    }

    //main window
    readonly property int mainWidth: {
        if (Screen.width > 1000) {
            return 360
        }
        return Screen.width
    }
    readonly property int mainHeight: {
        if (Screen.height > 1000) {
            return 687
        }
        return Screen.height
    }
    readonly property string mainTitle: "SeeWarGame"

    //counts
    readonly property int countsCells: 9
    readonly property real hintButtonBottomMargins: 3

    //GamePersona
    //тот для кого вообще все это сделано - пользователь
    //обьект имитирующий пользователя
    //содержит все нужные модели
    property var userObject: ObjectUser

    //models
    property var modelField: OwnField //1
    property var enemyModelField: EnemyField //2
    property var modelFlot: Flot //1

    //    property var modelField: OwnField //1
    //    property var enemyModelField: EnemyField //2
    //    property var modelFlot: Flot // 1
    //************************************************************
    //    property var modelField: OwnField
    //    property var enemyModelField: EnemyField

    //colors sheme
    readonly property color styleApplicationColor: "#1c1c1c" //"#0d1e49"//"#0b193c"
    readonly property color styleByttonColor: "#000000" //"#09183e"
    readonly property color styleTextColor: "#fffc00"
    readonly property color styleLogYourColor: "#03ff5c"
    readonly property color styleLogHiColor: "#0086f8"

    //urls Loaded Application Window
    readonly property string window_STARTMENU: "qrc:/QmlModule/qml/DefaultGui/ModeWindow/StartMenu.qml"
    readonly property string window_ARRAGEMENT: "qrc:/QmlModule/qml/DefaultGui/ModeWindow/Arragement.qml"
    readonly property string window_GAME: "qrc:/QmlModule/qml/DefaultGui/ModeWindow/GameMode.qml"
    readonly property string window_CHATTEXTAREA: "qrc:/QmlModule/qml/DefaultGui/Elements/ChatTextArea.qml"
    readonly property string window_POPUPMENUARRAGEMENT: "qrc:/QmlModule/qml/DefaultGui/Elements/PopupMenuArragement.qml"

    //urls
    readonly property string urlElementFigureWindow: "qrc:/QmlModule/qml/DefaultGui/BaseElements/FigureWindow.qml"
    readonly property string urlBackgroundBlackWater: "qrc:/QmlModule/qml/DefaultGui/img/blackWater1.gif"
    readonly property string rotateImg: "qrc:/QmlModule/qml/DefaultGui/img/rtt1.png"
    readonly property string okImg: "qrc:/QmlModule/qml/DefaultGui/img/ok.png"
    readonly property string img_CLEAR: "qrc:/QmlModule/qml/DefaultGui/img/Symbols-Delete-icon.png"
    readonly property string img_PLAY: "qrc:/QmlModule/qml/DefaultGui/img/play2.png"
    readonly property string img_CORRECT: "qrc:/QmlModule/qml/DefaultGui/img/Edit1.png"
    readonly property string img_AUTOALIGMENT: "qrc:/QmlModule/qml/DefaultGui/img/robot.png"
    readonly property string img_MENU: "qrc:/QmlModule/qml/DefaultGui/img/menu.png"
    readonly property string img_POVTOR: "qrc:/QmlModule/qml/DefaultGui/img/Povtor.png"

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
    //some constants
    readonly property int kRadius: 20

    //names Buttons
    readonly property string buttonName_ANDROID: qsTr("ИГРАТЬ")
    readonly property string buttonName_NETWORK: qsTr("По Сети")
    readonly property string buttonName_SETTINGS: qsTr("Настройки")
    readonly property string buttonName_GAME: qsTr("Играть")
    readonly property string buttonName_CORRECT: qsTr("Править")
    readonly property string buttonName_CLEAR: qsTr("Сброс")
    readonly property string buttonName_AUTOALIGNMENT: qsTr("Авторасстановка")
    readonly property string buttonName_ROTATE: qsTr("Повернуть")
    readonly property string buttonName_PLACING: qsTr("Установить")

    readonly property string buttonName_MENU: qsTr("В Меню")
    readonly property string buttonName_AGAIN: qsTr("Еще партейку?")

    readonly property string buttonName_SENDMESAGECHAT: qsTr("отправить")
    readonly property string buttonName_LEFTZABOI: qsTr("<")
    readonly property string buttonName_RIGHTZABOI: qsTr(">")

    readonly property string defaultTextToTextAreaChat: qsTr("Писать тут")

    readonly property string textAppealYou: qsTr("Ты")

    readonly property string textAppealHi: qsTr("Он")
}
