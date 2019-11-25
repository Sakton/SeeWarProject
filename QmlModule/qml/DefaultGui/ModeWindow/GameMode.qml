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
                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: Setting.styleApplicationColor
                    border.color: Setting.styleTextColor

                    ColumnLayout {
                        anchors.fill: parent

                        Text {
                            id: _textLogIgry
                            horizontalAlignment: Text.Center
                            Layout.fillWidth: true
                            Layout.minimumHeight: height
                            color: Setting.styleTextColor
                            textFormat: Text.RichText
                            text: qsTr("<h3><b><i>Лог игры</i></b></h3>")
                        }

                        ScrollView {
                            id: _scrollLog
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            ScrollBar.vertical.interactive: false
                            //clip: true
                            TextArea {
                                id: _textLog
                                anchors.fill: parent
                                //                                                            Layout.fillWidth: true
                                //                                                            Layout.fillHeight: true
                                color: Setting.styleTextColor
                                textFormat: Text.RichText
                                clip: true
                                text: {
                                    "<b><font color = " + Setting.styleLogYourColor + ">Ты: </b>" +
                                            "<br>" +
                                            "<b><font color = " + Setting.styleLogHiColor + ">Он: </br>"
                                }
                            } //TextArea
                        }//ScrollView
                    }
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

            delegate: Rectangle {
                width: _f.cellWidth
                height: _f.cellHeight
                color: Setting.styleApplicationColor
                border.color: Setting.styleTextColor

                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter

                    text: model.myIndex
                    color: Setting.styleTextColor
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        _textLog.insert(0, "<b><font color = " + Setting.styleLogYourColor + ">Ты: " + model.myIndex + " </b><br>")

                    }
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
