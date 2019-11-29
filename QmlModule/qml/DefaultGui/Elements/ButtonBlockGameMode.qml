import QtQuick 2.0
import QtQuick.Layouts 1.12
import Settings 1.0

Item {
    width: 200
    height: 100
    signal buttonId(int idBtn)

    RowLayout {
        anchors.fill: parent

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true

            color: "red"

            Text {
                text: qsTr("В начало")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    buttonId(Setting.MyEnumButton.BUTTON_BACK)
                }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true

            color: "blue"

            Text {
                text: qsTr("Еще раз")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    buttonId(Setting.MyEnumButton.BUTTON_REPEAT)
                }
            }
        }
    }
}
