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
        spacing: 1

        Field {
            id: _fld
            Layout.minimumHeight: parent.height / 2
            Layout.fillWidth: true
            Layout.fillHeight: true

            DropArea {
                id: _da
                anchors.fill: parent
                drag.onPositionChanged: {
                    console.debug(_fld.indexAt(drag.x, drag.y))
                }
            }
        }

        Stopka {
            Layout.minimumHeight: parent.height / 4
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        ButtonBlockArragement {
            Layout.minimumHeight: parent.height / 4
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
