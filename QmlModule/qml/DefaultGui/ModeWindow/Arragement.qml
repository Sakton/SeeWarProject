import QtQuick 2.0
import QtQuick.Layouts 1.12
import "../Elements"
import Settings 1.0

Rectangle {
    id: _root
    width: 460
    height: 230
    //    anchors.margins: 2

    color: Setting.styleApplicationColor

    //    RowLayout {
    //        anchors.fill: parent
    //        spacing: 1

    //        ButtonBlockArragement {
    //            Layout.minimumWidth: parent.width / 4
    //            Layout.fillWidth: true
    //            Layout.fillHeight: true
    //        }

    //        Figures {
    //            Layout.minimumWidth: parent.width / 4
    //            Layout.fillWidth: true
    //            Layout.fillHeight: true
    //        }

    //        Field {
    //            Layout.minimumWidth: parent.width / 2
    //            Layout.fillWidth: true
    //            Layout.fillHeight: true
    //        }
    //    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 1

        Field {
            Layout.minimumHeight: parent.width / 2
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        //        Figures {
        //            Layout.minimumHeight: parent.width / 4
        //            Layout.fillWidth: true
        //            Layout.fillHeight: true
        //        }

        Stopka {
            Layout.minimumHeight: parent.width / 4
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        ButtonBlockArragement {
            Layout.minimumHeight: parent.width / 4
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

    }
}
