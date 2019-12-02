import QtQuick 2.12
import QtQuick.Window 2.12
import Settings 1.0
import "ModeWindow"
import "BaseElements"

Window {
    id: _root
    width: Setting.mainWidth //1200 / 2.6
    height: Setting.mainHeight //600 / 2.6
    title: Setting.mainTitle
    color: Setting.styleApplicationColor
    visible: true

    MainLoaderObject {
        id: _mainLoader
        Component.onCompleted: {
            createObject(Setting.startMenuWindow).buttonMenuClicked.connect(loaderWindow)
        }
    }
}
