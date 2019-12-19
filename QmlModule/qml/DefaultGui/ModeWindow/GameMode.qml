import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import Settings 1.0
import "../Elements"
import "../BaseElements"

InterfaceWindowSignals {
    width: Setting.mainWidth
    height: Setting.mainHeight

    Rectangle {
        id: _root
        anchors.fill: parent

        property string txt: ""

        AnimatedImage {
            anchors.fill: parent
            source: Setting.urlBackgroundBlackWater
            onStatusChanged: {
                playing = AnimatedImage.Ready
            }

            ColumnLayout {
                anchors.fill: parent
                spacing: 0

                Item {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    //завернуто в Итем для правильной
                    //установки размеров в Лейауте
                    TopElementGameMode {
                        id: _topElement
                        anchors.fill: parent
                    }
                }

                Field {
                    id: _f
                    Layout.minimumHeight: _root.width
                    Layout.fillWidth: true
                    model: Setting.modelField

                    delegate: DelegatFieldGameMode {
                        width: _f.cellWidth
                        index: model.IndexElement
                        onClicedIndex: {
                            _topElement.clickIndex = model.myIndex
                        }
                    }
                }

                Item {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    ButtonBlockGameMode{
                        anchors.fill: parent
                        onClickedButtonOnBlock: {
                            buttonMenuClicked(idBtn)
                        }
                    }
                }
            }//ColumnLayout
        }//AnimatedImage
    }
}

