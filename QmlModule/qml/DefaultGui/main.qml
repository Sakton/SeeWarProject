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
            loaderWindow(enumTypeButton)
        }
    }

    Loader {
        id: _pageLoader
        anchors.fill: parent
    }

    function loaderWindow(indexWindow) {
        var fileLoad = null;
        switch(indexWindow) {
        case Setting.MyEnumButton.BUTTON_ANDROID:
            _pageLoader.source = "qrc:/QmlModule/qml/DefaultGui/ModeWindow/Arragement.qml"
            break;
        case Setting.MyEnumButton.BUTTON_NETWORK:
            _pageLoader.source = "qrc:/QmlModule/qml/DefaultGui/ModeWindow/GameMode.qml"
            break;
        case Setting.MyEnumButton.BUTTON_CUSTOMIZATION:
    //        fileLoad = Qt.createComponent("qrc:/QmlModule/qml/DefaultGui/ModeWindow/Arragement.qml")
            break
        }
    }
}
