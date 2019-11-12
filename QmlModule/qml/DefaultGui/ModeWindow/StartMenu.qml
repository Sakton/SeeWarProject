import QtQuick 2.0
import QtQuick.Layouts 1.12
import Settings 1.0
import "../BaseElements"

Rectangle {
    id: root
    width: 230
    height: 460
    color: Setting.styleApplicationColor
    signal buttonClicked(int indexButton)

    ColumnLayout {
        anchors.fill: parent
        Layout.margins: 5
        spacing: 40

        MyButton {
            Layout.fillWidth: true
            Layout.fillHeight: true
            name: "С андроид"
            indexButton: 0
            onButtonClicked: {
                buttonClicked(indexButton)
            }
        }

        MyButton {
            Layout.fillWidth: true
            Layout.fillHeight: true
            name: "По сети"
            indexButton: 1
            onButtonClicked: {
                buttonClicked(indexButton)
            }
        }

        MyButton {
            Layout.fillWidth: true
            Layout.fillHeight: true
            name: "Настройки"
            indexButton: 2
            onButtonClicked: {
                buttonClicked(indexButton)
            }
        }
    }
}



