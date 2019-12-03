import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Popup {
    id: _root

    signal textOnChat(string txt)

    width: 200
    height: 100
    modal: true
    opacity: 0.7
    Component.onCompleted: open()

    ColumnLayout {
        anchors.fill: parent
        spacing: 5

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
            TextEdit {
                id: _textToChat
                anchors.fill: parent
                text: qsTr("Сообщение")
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "blue"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    textOnChat(_textToChat.text)
                }
            }
        }
    }
}
