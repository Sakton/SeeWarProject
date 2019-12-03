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
        onTextOnChat : {
             _root.textLog = txt + "<br>"
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {_loader.setSource(Setting.window_CHATTEXTAREA,
                                      {"width" : Setting.mainWidth,//_root.width * 3,
                                          "height":Setting.mainHeight / 3 ,
                                          "x": -_root.width * 3,
                                          "y" : _root.height * 2})
        }
    }
}
