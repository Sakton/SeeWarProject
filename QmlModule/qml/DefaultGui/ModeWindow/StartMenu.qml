import QtQuick 2.0
import QtQuick.Layouts 1.12
import Settings 1.0
import "../BaseElements"

Rectangle {
    id: _root
    width: 230
    height: 460
    color: Setting.styleApplicationColor
    signal buttonMenuClicked(int enumTypeButton)

    Component.onCompleted: console.debug(_root)
    Component.onDestruction: console.debug(_root + " destruction()")


    ColumnLayout {
        anchors.fill: parent
        Layout.margins: 5
        spacing: 40

        Repeater {
            model: [
                     { typeButton : Setting.MyEnumButton.BUTTON_ANDROID, name : "С андроид" },
                     { typeButton : Setting.MyEnumButton.BUTTON_NETWORK, name : "По сети" },
                     { typeButton : Setting.MyEnumButton.BUTTON_CUSTOMIZATION, name : "Настройки" } ]
            delegate: MyButton {
                Layout.fillWidth: true
                Layout.fillHeight: true
                typeButton: modelData.typeButton
                name: modelData.name
                onButtonClicked: {
                    buttonMenuClicked(typeButton)
                }
            }
        }
    }
}



