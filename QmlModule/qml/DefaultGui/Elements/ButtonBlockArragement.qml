import QtQuick 2.0
import QtQuick.Layouts 1.12
import Settings 1.0
import "../BaseElements"

Rectangle {
    width: 100
    height: 230
    color: Setting.styleTextColor
    signal clickedButtonOnBlock(int idBtn)

    //TODO тут плохо много онкликедов
    //и вообще повторов

    ColumnLayout {
        id: _container
        anchors.fill: parent
        spacing: 1

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 1

            Repeater {
                model: [
                    {idBtn : Setting.MyEnumButton.BUTTON_GAME,
                     name : Setting.buttonName_GAME,
                     urlImg : Setting.img_PLAY},
                    { idBtn : Setting.MyEnumButton.BUTTON_EDITING,
                      name : Setting.buttonName_CORRECT,
                      urlImg : Setting.img_CORRECT
                    }]
                delegate: ButtonArragement {
                    idBtn: modelData.idBtn
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    urlImg: modelData.urlImg
                    text: modelData.name
                    onIdButtonClicked: {
                        clickedButtonOnBlock(idBtn)
                    }
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 1

            Repeater {
                model: [
                    {idBtn : Setting.MyEnumButton.BUTTON_DISCHARGE,
                     name : Setting.buttonName_CLEAR,
                     urlImg : Setting.img_CLEAR},
                    {idBtn : Setting.MyEnumButton.BUTTON_AUTOALIGMENT,
                     name : Setting.buttonName_AUTOALIGNMENT,
                     urlImg : Setting.img_AUTOALIGMENT}]
                delegate: ButtonArragement {
                    idBtn: modelData.idBtn
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    urlImg: modelData.urlImg
                    text: modelData.name
                    onIdButtonClicked: {
                        clickedButtonOnBlock(idBtn)
                    }
                }
            }
        }
    }
}
