import QtQuick 2.0
import "../Settings/"
//import Settings 1.0

Rectangle {
    width: 100
    height: 50
    property int idBtn: -1
    property string name: ""
    signal idButtonClicked(int idBtn)
    color: Setting.styleApplicationColor

    MouseArea {
        anchors.fill: parent
        onClicked: {
            idButtonClicked(idBtn)
        }
    }
}
