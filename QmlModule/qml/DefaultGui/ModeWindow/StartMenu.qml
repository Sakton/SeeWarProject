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
                         { idButton : Setting.MyEnumButton.BUTTON_ANDROID, name : Setting.buttonName_ANDROID },
                         { idButton : Setting.MyEnumButton.BUTTON_NETWORK, name : Setting.buttonName_NETWORK },
                         { idButton : Setting.MyEnumButton.BUTTON_CUSTOMIZATION, name : Setting.buttonName_SETTINGS } ]
                delegate: MyButton {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    idBtn: modelData.idButton
                    name: modelData.name
                    onIdButtonClicked: {
                        buttonMenuClicked(idBtn)
                    }
                }
            }
        }
    }
}




