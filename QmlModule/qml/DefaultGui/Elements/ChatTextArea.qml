import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import Settings 1.0

Popup {
    id: _root

    signal textOnChat(string txt)

    width: 200
    height: 100
    modal: true
    opacity: 0.8
    Component.onCompleted: open()
    background: Rectangle {
        anchors.fill: parent
        color: Setting.styleApplicationColor
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 5

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
            TextEdit {
                id: _textToChat
                anchors.fill: parent
                color: Setting.styleTextColor
                text: Setting.defaultTextToTextAreaChat
                focus: false
                wrapMode: TextEdit.Wrap
                font.pixelSize: parent.height / 8
                onFocusChanged: {
                    _textToChat.clear()
                    _ma.enabled = true
                }
            }
        }

        Rectangle {
            id: _textButton
            Layout.fillWidth: true
            Layout.minimumHeight: parent.height / 3
            color: Setting.styleByttonColor
            border.color: Setting.styleTextColor
            clip: true

            Text {
                id: _texts
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: parent.height / 3
                color: Setting.styleTextColor
                text: ""
                Timer {
                    property int i: 0
                    property int lenth: Setting.buttonName_SENDMESAGECHAT.length - 1
                    property int left: 0
                    property int right: 0
                    property string str: Setting.buttonName_SENDMESAGECHAT
                    interval: 150
                    repeat: true
                    running: true
                    onTriggered: {
                        if(left === -lenth || right ===lenth) {
                            left = 0
                            right = 0
                            str = Setting.buttonName_SENDMESAGECHAT
                        }
                        str = Setting.buttonName_LEFTZABOI + str + Setting.buttonName_RIGHTZABOI
                        _texts.text = str
                        --left;
                        ++right;
                    }
                }
            }

            MouseArea {
                id: _ma
                anchors.fill: parent
                enabled: false
                onClicked: {
                    if(_textToChat.text !== "") {
                        textOnChat(_textToChat.text)
                    }
                    _textToChat.clear()
                }
            }
        }
    }
}
