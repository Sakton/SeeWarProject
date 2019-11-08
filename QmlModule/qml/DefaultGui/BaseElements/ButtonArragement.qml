import QtQuick 2.0

Rectangle {
    id: _root
    property int idBtn: -1
    property string text: _text.text
    signal clicked(int idBtn)

    width: 100
    height: 50
    color: "gray"

    Text {
        id: _text
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        text: _root.text
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
//            clicked(idBtn)
            console.debug(idBtn)
        }
    }
}
