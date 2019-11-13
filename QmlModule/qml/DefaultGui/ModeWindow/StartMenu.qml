import QtQuick 2.0
import QtQuick.Layouts 1.12
import Settings 1.0
import "../BaseElements"

Rectangle {
    id: root
    width: 230
    height: 460
    color: Setting.styleApplicationColor
    signal buttonMenuClicked(int indexButton)

    ColumnLayout {
        anchors.fill: parent
        Layout.margins: 5
        spacing: 40

        Repeater {
            model: [ { name : "С андроид" },
                     { name : "По сети" },
                     { name : "Настройки" } ]
            delegate: MyButton {
                Layout.fillWidth: true
                Layout.fillHeight: true
                indexButton: index
                name: modelData.name
                onButtonClicked: buttonMenuClicked(indexButton)
            }
        }
    }
}



