import QtQuick 2.0
import Settings 1.0
import QtGraphicalEffects 1.12

BasicButtonClass {
    id: _root
    property string text: _text.text
    property string urlImg: ""

    radius: width / Setting.kRadius

    Image {
        width: height
        height: parent.height / 2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: urlImg
    }

    Text {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: Setting.hintButtonBottomMargins
        anchors.horizontalCenter: parent.horizontalCenter
        text: _root.text
        color: Setting.styleTextColor
    }

    Rectangle {
        id: _zakraska
        x: pointZakraska().x
        y: pointZakraska().y
        width: parent.width / 10
        height: parent.height / 5
        color: parent.color
    }

    function pointZakraska(){
        console.debug(idBtn)
        switch( idBtn ) {
        case Setting.MyEnumButton.BUTTON_GAME:
            return Qt.point(0,0)
        case Setting.MyEnumButton.BUTTON_EDITING:
            return Qt.point(_root.width - _zakraska.width, 0)
        case Setting.MyEnumButton.BUTTON_DISCHARGE:
        case Setting.MyEnumButton.BUTTON_AGAIN:
            return Qt.point(0, _root.height - _zakraska.height)
        case Setting.MyEnumButton.BUTTON_AUTOALIGMENT:
        case Setting.MyEnumButton.BUTTON_BACK:
            return Qt.point(_root.width - _zakraska.width, _root.height - _zakraska.height);
        case Setting.MyEnumButton.BUTTON_RESERVE:
            return Qt.point(_root.width/2, _root.height/2)
        }
    }
}
