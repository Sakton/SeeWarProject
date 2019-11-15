import QtQuick 2.0
import QtQuick.Layouts 1.12
import "../Elements"
import Settings 1.0

Rectangle {
    id: _root
    width: 230
    height: 460

    color: Setting.styleApplicationColor

    Component.onCompleted: {
        console.debug("Что в стопку parent.width = " + parent.width)
        console.debug("Что в стопку _fld.height = " + _fld.height)

        _stopka.dragSizeX = parent.width
        _stopka.dragSizeY = _fld.height
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
                    var currentSource = _da.drag.source
                    console.debug("Arragement.width" + _root.width)
                    console.debug("currentSource.width" + currentSource.width)

//                    console.debug("currentIndex = " + currentIndex)
//                    console.debug("_da.drag.source = " + _da.drag.source)
                    if (currentIndex % Setting.countsCells > 4) {
//                        console.debug("currentIndex = " + currentIndex)
                        currentSource.parent.zerkalno = true
//                        currentSource.parent.deltaDragMinX = parent.width
//                        currentSource.parent.deltaDragMaxX = 0
//                        currentSource.parent.deltaDragMinY =
                    } else {
                        currentSource.parent.zerkalno = false
//                        currentSource.parent.deltaDragMinX = 0
//                        currentSource.parent.deltaDragMaxX = parent.width
                    }
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
            Layout.minimumHeight: (_root.height - _fld.height) / 2
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
