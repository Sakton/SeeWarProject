import QtQuick 2.0
import Settings 1.0
import QtGraphicalEffects 1.12

Rectangle {
    id: _root
    property int idBtn: -1
    property string text: _text.text
    signal clicked(int idBtn)
    radius: width / 20

    width: 100
    height: 50
    color: Setting.styleByttonColor



    Text {
        id: _text
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: Setting.styleTextColor
        text: _root.text
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
//            clicked(idBtn)
            console.debug(idBtn)
        }
    }

    Rectangle {
        id: _zakraska
        x: pointZakraska().x
        y: pointZakraska().y
        width: parent.width / 20
        height: parent.height / 10
        color: parent.color
    }

    function pointZakraska(){
        switch( idBtn ) {
        case 0:
            return Qt.point(0,0)
        case 1:
            return Qt.point(_root.width - _zakraska.width, 0)
        case 2:
            return Qt.point(0, _root.height - _zakraska.height)
        case 3:
            return Qt.point(_root.width - _zakraska.width, _root.height - _zakraska.height);
        }
    }

}
