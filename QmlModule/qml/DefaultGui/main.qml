import QtQuick 2.12
import QtQuick.Window 2.12
import Settings 1.0
import "ModeWindow"

Window {
    id: _root
    width: Setting.mainWidth //1200 / 2.6
    height: Setting.mainHeight //600 / 2.6
    title: Setting.mainTitle
    color: Setting.styleApplicationColor
    visible: true

    StartMenu {
        id: _startMenu
        width: parent.width / 2
        height: parent.height / 2
        x: parent.width / 4
        y: parent.height / 4

        onButtonMenuClicked: {
            console.debug("Screen.width = " + Screen.width)
            console.debug("Screen.height = " + Screen.height)
            console.debug("Screen.pixelDestiny = " + Screen.pixelDestiny)
            console.debug("Screen.serialNumber = " + Screen.serialNumber)
            console.debug("Screen.devicePixelRatio = " + Screen.devicePixelRatio)
            loaderWindow(indexButton)
        }
    }

    Loader {
        id: _pageLoader
        anchors.fill: parent
    }

//    function loaderWindow(indexWindow) {
//        var fileLoad = null;
//        switch(indexWindow) {
//        case 0:
//            fileLoad = Qt.createComponent("qrc:/QmlModule/qml/DefaultGui/ModeWindow/Arragement.qml")
//            break;
//        case 1:
//            fileLoad = Qt.createComponent("qrc:/QmlModule/qml/DefaultGui/ModeWindow/Arragement.qml")
//            break;
//        case 2:
//            fileLoad = Qt.createComponent("qrc:/QmlModule/qml/DefaultGui/ModeWindow/Arragement.qml")
//            break
//        }
//        var objWindow = fileLoad.createObject(_root);
//        _startMenu.visible = false
//        objWindow.visible = true
//    }

    function loaderWindow(indexWindow) {
        var fileLoad = null;
        switch(indexWindow) {
        case 0:
            //fileLoad = Qt.createComponent("qrc:/QmlModule/qml/DefaultGui/ModeWindow/Arragement.qml")
            _pageLoader.source = "qrc:/QmlModule/qml/DefaultGui/ModeWindow/Arragement.qml"
            break;
        case 1:
    //        fileLoad = Qt.createComponent("qrc:/QmlModule/qml/DefaultGui/ModeWindow/Arragement.qml")
            break;
        case 2:
    //        fileLoad = Qt.createComponent("qrc:/QmlModule/qml/DefaultGui/ModeWindow/Arragement.qml")
            break
        }
    }
}
