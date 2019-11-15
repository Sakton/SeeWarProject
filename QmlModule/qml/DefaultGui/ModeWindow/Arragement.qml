import QtQuick 2.0
import QtQuick.Layouts 1.12
import "../Elements"
import Settings 1.0

Rectangle {
    id: _root
    width: 230
    height: 460

    color: Setting.styleApplicationColor

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
                    //                    console.debug("currentIndex = " + currentIndex)
                    console.debug("_da.drag.source = " + _da.drag.source)
                    if(currentIndex % Setting.countsCells > 4) {
                        console.debug("currentIndex = " + currentIndex)
                        currentSource.parent.zerkalno = true
                    } else {
                        currentSource.parent.zerkalno = false
                    }
                }
            }
        }

        Stopka {
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
