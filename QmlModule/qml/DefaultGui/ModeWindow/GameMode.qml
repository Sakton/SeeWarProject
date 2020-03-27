import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import Settings 1.0
import "../Elements"
import "../BaseElements"

InterfaceWindowSignals {
    id: _root
    width: Setting.mainWidth
    height: Setting.mainHeight

    //TODO выводить попапы при смерти корабля и проигрыше выигрыше

    Popup {
        id: _popup
        x: _root.width / 2 - width / 2
        y: _root.height / 2 - height / 2
        implicitWidth: _text.width
        implicitHeight: _root.height / 20
        visible: false

        background: Rectangle {
            anchors.fill: parent
            color: "black"
            radius: _popup.height / 2
            opacity: 0
        }
        property string popupText: qsTr("Ход соперника")

        onOpened: {
            _popup.close()
        }

        enter: Transition {
            NumberAnimation {
                loops: 1
                property: "opacity"
                duration: 2000
                from: 1.0
                to: 0.0
            }
        }

        ColumnLayout  {
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
    } //Popup

    Rectangle {
        id: _rect
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
                    id: _btnBlock
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
