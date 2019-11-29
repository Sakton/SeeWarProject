import QtQuick 2.0
import QtQuick.Layouts 1.12
import "../Elements"
import Settings 1.0

Rectangle {
    id: _root
    width: Setting.mainWidth
    height: Setting.mainHeight

    color: Setting.styleApplicationColor

    Component.onCompleted: {
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

                DropArea {
                    id: _da
                    anchors.fill: parent
                    property var currentSourceDropElement: null
                    drag.onPositionChanged: {
                        var currentIndex = _fld.indexAt(drag.x, drag.y)
                        console.debug("currentIndex = " + currentIndex)
                        currentSourceDropElement = _da.drag.source
                        if(currentIndex >= 0) {
                            if (currentIndex % Setting.countsCells >= 4) {
                                currentSourceDropElement.parent.zerkalno = true
                            } else {
                                currentSourceDropElement.parent.zerkalno = false
                            }
                        }
                    }

                    Connections {
                        target: _popup
                        onButtonRotate: {
                            var element = _da.currentSourceDropElement.parent.children[0]
                            if(element.parent.parent.parent.countPalubs > 1) {
                                element.rotateAngle = (element.rotateAngle === 90) ? 0 : 90
                            }
                        }
                    }

                    onDropped: {
                        _popup.visible = true
                    }
                }
            }

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
                        _stopka.pop();
                        visible = false
                    }
                }
            }

            ButtonBlockArragement {
                id: _blockButton
                Layout.minimumHeight: (_root.height - _fld.height) / 2
                Layout.fillWidth: true
                Layout.fillHeight: true

                onClickedButtonOnBlock: {
                    loaderWindow(idBtn)
                }
            }
        } //ColumnLayout
    } //AnimatedImage

    Loader {
        id: _loader
        anchors.fill: parent
    }

    function loaderWindow(idBtn) {
        switch(idBtn) {
        case Setting.MyEnumButton.BUTTON_GAME:
            _loader.source = Setting.gameModeWindow
            break;
        case Setting.MyEnumButton.BUTTON_EDITING:
            console.log("Load Editing_Window")
            break;
        case Setting.MyEnumButton.BUTTON_DISCHARGE:
            console.log("Reload Arragement Window")
            break;
        case Setting.MyEnumButton.BUTTON_AUTOALIGMENT:
            console.log("Call AoutoAligment Function")
            break;
        }
    }
}
