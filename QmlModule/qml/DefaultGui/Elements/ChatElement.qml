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
            Setting.userObject.onMessageChat(txt)
            _root.textLog = "<b><font color = " + Setting.styleLogYourColor + ">" + Setting.textAppealYou + ": </b>" + txt + "<br>"
        }
    }

    MouseArea {
        id: _mouse
        anchors.fill: parent
        anchors.margins: parent.width / 10
        onDoubleClicked: { _loader.setSource(Setting.window_CHATTEXTAREA,
                                             {"width" : Setting.mainWidth,
                                                 "height":Setting.mainHeight / 3 ,
                                                 "x": -Setting.mainWidth,
                                                 "y" : Setting.mainWidth / 2})
        }
    }
}
