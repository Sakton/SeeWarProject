import QtQuick 2.0
import QtQuick.Layouts 1.12
import "../Elements"
import "../BaseElements"
import Settings 1.0

InterfaceWindowSignals {
    id: _root
    width: Setting.mainWidth
    height: Setting.mainHeight

    Rectangle {
        anchors.fill: parent
        color: Setting.styleApplicationColor

        Component.onCompleted: {
            console.debug("Arragement created pointer = " + _root)
            _stopka.dragSizeX = parent.width
            _stopka.dragSizeY = _fld.height
        }

        AnimatedImage {
            anchors.fill: parent
            source: Setting.urlBackgroundBlackWater
            onStatusChanged: {
                playing = AnimatedImage.Ready
            }

            ColumnLayout {
                anchors.fill: parent
                spacing: 0

                Field {
                    id: _fld
                    Layout.fillWidth: true
                    Layout.minimumHeight: _root.width
                    model: Setting.modelField

                    DropArea {
                        id: _da
                        anchors.fill: parent
                        property var currentSourceDropElement: null
                        property int angle: 0
                        property int currentIndex: 0
                        property int countPalubs: 0
                        property var objectFigure: null

                        drag.onPositionChanged: {
                            _da.currentIndex = _fld.indexAt(drag.x, drag.y)
                            _da.currentSourceDropElement = _da.drag.source
                            _da.objectFigure = currentSourceDropElement.parent.parent.parent
                            _da.countPalubs = objectFigure.countPalubs
                        }

                        onCurrentIndexChanged: {
                            if (currentIndex >= 0 && objectFigure !== null) {
                                //отпраить индекс в модель
                                objectFigure.currentIndex = _da.currentIndex
                                if (currentIndex % Setting.countsCells >= 4) {
                                    currentSourceDropElement.parent.zerkalno = true
                                } else {
                                    currentSourceDropElement.parent.zerkalno = false
                                }
                            }
                        }

                        onAngleChanged: {
                            objectFigure.currentAngle = _da.angle
                        }

                        Connections {
                            target: _popup
                            onButtonRotate: {
                                var element = _da.currentSourceDropElement.parent.children[0]
                                if (element.parent.parent.parent.countPalubs > 1) {
                                    element.rotateAngle = (element.rotateAngle === 90) ? 0 : 90
                                    _da.angle = element.rotateAngle
                                }
                            }
                        }

                        onDropped: {
                            _popup.visible = true
                        }
                    } //dropArea
                } //field

                Stopka {
                    id: _stopka
                    Layout.minimumHeight: (_root.height - _fld.height) / 2
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    dragSizeX: parent.width
                    dragSizeY: _fld.height

                    PopupMenuArragement {
                        id: _popup
                        width: parent.width / 2
                        height: parent.height / 2
                        anchors.centerIn: parent
                        visible: false

                        onButtonOK: {
                            _stopka.pop()
                            visible = false
                        }
                    }
                } //stopka

                ButtonBlockArragement {
                    id: _blockButton
                    Layout.minimumHeight: (_root.height - _fld.height) / 2
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    onClickedButtonOnBlock: {
                        buttonMenuClicked(idBtn)
                    }
                }
            } //ColumnLayout
        } //AnimatedImage
    } //rect
} //InterfaceWindowSignals
