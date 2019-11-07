import QtQuick 2.0
import QtQuick.Layouts 1.12

Rectangle {
    id: root
    width: 460
    height: 230
    color: "yellow"

    RowLayout {
        anchors.fill: parent

        Rectangle {
            Layout.minimumWidth: parent.width / 4
            Layout.fillHeight: parent

            color: "red"
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                font.pointSize: 14

                text: qsTr("Настройки")
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.debug("Настройки")
                }
            }
        }

        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true

                color: "blue"
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter

                    font.pointSize: 14

                    text: qsTr("По сети")
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        console.debug("По сети")
                    }
                }
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true

                color: "green"
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter

                    font.pointSize: 14

                    text: qsTr("С кмп")
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        console.debug("С кмп")
                    }
                }
            }
        }
    }
}
