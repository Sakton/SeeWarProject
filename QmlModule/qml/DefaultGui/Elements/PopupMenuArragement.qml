import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import Settings 1.0

Popup {
    id: _root
    signal buttonOK;
    signal buttonRotate;

    width: 200
    height: 100
    padding: 1

    background: Rectangle {
        anchors.fill: parent
        color: Setting.styleTextColor
        radius: width / Setting.kRadius
    }

//    opacity: 0.8

    RowLayout {
        anchors.fill: parent
        spacing: 0

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: Setting.styleByttonColor
            //border.color: Setting.
            radius: _root.width / Setting.kRadius

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                color: Setting.styleTextColor
                text: qsTr("Rotate")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.debug("Rotate")
                }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: Setting.styleByttonColor
            radius: _root.width / Setting.kRadius

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                color: Setting.styleTextColor
                text: qsTr("OK")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    buttonOK()
                }
            }
        }
    }
}
