import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import Settings 1.0
import "../Elements"
import "../BaseElements"

InterfaceWindowSignals {
    width: Setting.mainWidth
    height: Setting.mainHeight

    Popup {
        id: _popup
        x: _root.width / 2 - width / 2
        y: _root.height / 2 - height / 2
        width: _root.width * 3 / 4
        height: _root.height / 10
        visible: true


        PropertyAnimation {
            duration: 2000
            property: "opacity"
            to: 0
        }

        Text {
            id: name
            text: qsTr("Ход соперника")
        }
    }

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
                    model: Setting.enemyModelField
                    delegate: DelegatFieldGameMode {
                        id: _delegate
                        width: _f.cellWidth
                        index: model.indexElement
                        onClicedIndex: {
                            //TODO проверка состояния и количетва ходов
                            if(Setting.userObject.countMoves === 0) {
                                _popup.open()
                            } else {
                                _topElement.clickIndex = model.indexElement
                                Setting.userObject.onClickToCell(model.indexElement)
                                --Setting.userObject.countMoves
                            }
                        }
                    }
                }



                Item {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    ButtonBlockGameMode {
                        anchors.fill: parent
                        onClickedButtonOnBlock: {
                            buttonMenuClicked(idBtn)
                        }
                    }
                }
            } //ColumnLayout
        } //AnimatedImage
    }
}
