import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import Settings 1.0
import "../Elements"

Rectangle {
    id: _root
    width: Setting.mainWidth
    height: Setting.mainHeight
    color: Setting.styleApplicationColor

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true

            RowLayout {
                anchors.fill: parent
                spacing: 0

                LogElement {
                    id: _logElement
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }

                Item {
                    Layout.minimumWidth: parent.height
                    Layout.fillHeight: true
                    Field {
                        //завернуто в Item не случайно
                        anchors.fill: parent
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    color: Setting.styleApplicationColor
                    border.color: Setting.styleTextColor

                    TextArea {
                        id: _textChat
                        anchors.fill: parent
                        color: Setting.styleTextColor
                        text: "Чат"
                    }
                }
            }
        }

        Field {
            id: _f
            Layout.minimumHeight: _root.width
            Layout.fillWidth: true

            delegate: DelegatFieldGameMode {
                width: _f.cellWidth
                index: model.myIndex
                onClicedIndex: {
                    _logElement.textLog = "<b><font color = " + Setting.styleLogYourColor + ">Ты: " + model.myIndex + " </b><br>"
                }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true

            color: Setting.styleApplicationColor
            border.color: Setting.styleTextColor
        }
    }

}
