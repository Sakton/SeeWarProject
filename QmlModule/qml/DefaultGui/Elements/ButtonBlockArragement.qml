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

            ButtonArragement {
                id: _b0
                idBtn: Setting.MyEnumButton.BUTTON_GAME
                Layout.fillWidth: true
                Layout.fillHeight: true
                urlImg: Setting.playImg
                text: "Играть"
                onClickedBtn: {
                    clickedButtonOnBlock(idBtn)
                }
            }

            ButtonArragement {
                id: _b1
                idBtn: Setting.MyEnumButton.BUTTON_EDITING
                Layout.fillWidth: true
                Layout.fillHeight: true
                urlImg: Setting.editImg
                text: "Править"
                onClickedBtn: {
                    clickedButtonOnBlock(_b1.idBtn)
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 1

            ButtonArragement {
                id: _b2
                idBtn: Setting.MyEnumButton.BUTTON_DISCHARGE
                Layout.fillWidth: true
                Layout.fillHeight: true
                urlImg: Setting.refreshImg
                text: "Сброс"
                onClickedBtn: {
                    clickedButtonOnBlock(_b2.idBtn)
                }
            }

            ButtonArragement {
                id: _b3
                idBtn: Setting.MyEnumButton.BUTTON_AUTOALIGMENT
                Layout.fillWidth: true
                Layout.fillHeight: true
                urlImg: Setting.robotImg
                text: "Авторасстановка"
                onClickedBtn: {
                    clickedButtonOnBlock(_b3.idBtn)
                }
            }
        }
    }
}
