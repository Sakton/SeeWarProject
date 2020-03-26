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
        property string popupText: qsTr("Ход соперника")

        id: _popup
        x: _root.width / 2 - width / 2
        y: _root.height / 2 - height / 2
        width: _root.width * 3 / 4
        height: _root.height / 20
        visible: false
        background: Rectangle {
            anchors.fill: parent
            color: "black"
            radius: _popup.height / 2
        }

        enter: Transition {
            NumberAnimation {
                property: "opacity"
                duration: 2500
                from: 1.0
                to: 0.0

                onStopped: {
                    _popup.destroy()
                }
            }
        }

        Column {
            anchors.centerIn: parent
            Text {
                id: _text
                text: _popup.popupText
                font.bold: true
                styleColor: "#eadb00"
                font.pointSize: _popup.height / 2
                style: Text.Outline
                anchors.centerIn: parent.Center
            }
        }
    }

    Rectangle {
        id: _root
        anchors.fill: parent

        property string txt: ""

        AnimatedImage {
            anchors.fill: parent
            source: Setting.urlBackgroundBlackWater
            cache: false
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
                        colorCell: model.colorElement
                        imageResource: model.imageResourceCell
                        rotateAngle: model.angleRotationFigure
                        onClicedIndex: {

                            //TODO проверка состояния и количетва ходов
                            if (Setting.userObject.countMoves === 0) {
                                _popup.open()
                            } else {
                                _topElement.clickIndex = model.indexElement
                                Setting.userObject.slotFromQml_ClickToCell(
                                            model.indexElement)
                            }
                        }
                    }
                } //Field

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
