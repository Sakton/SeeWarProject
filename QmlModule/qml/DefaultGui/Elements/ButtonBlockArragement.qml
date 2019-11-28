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
//                idBtn: Setting.MyEnumButton.BUTTON_GAME
                Layout.fillWidth: true
                Layout.fillHeight: true
                urlImg: Setting.playImg
                text: "Играть"
                onClickedBtn: {
                    console.debug(idBtn)
                    clickedButtonOnBlock(idBtn)
                }
            }

            ButtonArragement {
                id: _b1
//                idBtn: 1
                Layout.fillWidth: true
                Layout.fillHeight: true
                urlImg: Setting.editImg
                text: "Править"
//                onClicked: {
//                    clickedButtonOnBlock(_b1.idBtn)
//                }
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 1

            ButtonArragement {
                id: _b2
//                idBtn: 2
                Layout.fillWidth: true
                Layout.fillHeight: true
                urlImg: Setting.refreshImg
                text: "Сброс"
//                onClicked: {
//                    clickedButtonOnBlock(_b2.idBtn)
//                }
            }

            ButtonArragement {
                id: _b3
//                idBtn: 3
                Layout.fillWidth: true
                Layout.fillHeight: true
                urlImg: Setting.robotImg
                text: "Авторасстановка"
//                onClicked: {
//                    clickedButtonOnBlock(_b3.idBtn)
//                }
            }
        }
    }
}
