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
        source: "qrc:/QmlModule/qml/DefaultGui/img/blackWater1.gif"
        onStatusChanged: {
            playing = AnimatedImage.Ready
        }
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        Field {
            id: _fld
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumHeight: _root.width

            DropArea {
                id: _da
                anchors.fill: parent
                drag.onPositionChanged: {
                    var currentIndex = _fld.indexAt(drag.x, drag.y)
                    console.debug("currentIndex = " + currentIndex)
                    var currentSource = _da.drag.source
//                    console.debug("currentSource = " + currentSource)
                    if(currentIndex > -1) {
                        if (currentIndex % Setting.countsCells >= 4) {
                            console.debug(currentSource.parent.zerkalno)
                            currentSource.parent.zerkalno = true
                        } else {
                            console.debug(currentSource.parent.zerkalno)
                            currentSource.parent.zerkalno = false
                        }
                    }/* else {
                        currentSource.parent.zerkalno = false
                    }*/


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
        }

        ButtonBlockArragement {
            id: _blockButton
            Layout.minimumHeight: (_root.height - _fld.height) / 2
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
