import QtQuick 2.0
import Settings 1.0

LogElement {
    id: _root
    width: 100
    height: 200

    Loader {
        id: _loader
        anchors.fill: parent
    }

    Connections {
        target: _loader.item
        onTextOnChat : { //от попап окна ввода текста
             _root.textLog = txt + "<br>"
        }
    }

    MouseArea {
        anchors.fill: parent

        //TODO что с прокруткой!!! Поправить
//        onClicked: {
//            console.debug("onClicked")
//            _root.focus = true
//        }

        onDoubleClicked: {_loader.setSource(Setting.window_CHATTEXTAREA,
                                      {"width" : Setting.mainWidth,
                                          "height":Setting.mainHeight / 3 ,
                                          "x": -Setting.mainWidth,
                                          "y" : Setting.mainWidth / 2})
        }
    }
}
