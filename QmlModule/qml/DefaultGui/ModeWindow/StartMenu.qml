import QtQuick 2.0
import QtQuick.Layouts 1.12
import Settings 1.0
import "../BaseElements"

InterfaceWindowSignals {
    width: Setting.mainWidth
    height: Setting.mainHeight

    Rectangle {
        id: _root
        anchors.fill: parent
        color: Setting.styleApplicationColor

        InterfaceWindowSignals {
            id: _signalInterface
        }

        Component.onCompleted: console.debug(_root)
        Component.onDestruction: console.debug(_root + " destruction()")

        ColumnLayout {
            width: parent.width / 2
            height: parent.height / 2
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
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

}




