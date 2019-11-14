import QtQuick 2.0
import QtQuick.Layouts 1.12
import "../Elements"
import Settings 1.0

Rectangle {
    id: _root
    width: 460
    height: 230

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
                    console.debug(_fld.indexAt(drag.x, drag.y))
                }
            }
        }

        Stopka {
            Layout.minimumHeight: (_root.height - _fld.height) / 2
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        ButtonBlockArragement {
            Layout.minimumHeight: (_root.height - _fld.height) / 2
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
