import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import Settings 1.0
import "../Elements"

Rectangle {
    id: _root
    property string txt: ""
    signal ttttt(string txt)

    width: Setting.mainWidth
    height: Setting.mainHeight
    color: Setting.styleApplicationColor

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
            //завернуто в Итем для правильной
            //установки размеров в Лейауте
            TopElementGameMode {
                id: _topElement
                anchors.fill: parent
            }
        }

        Field {
            id: _f
            Layout.minimumHeight: _root.width
            Layout.fillWidth: true

            delegate: DelegatFieldGameMode {
                width: _f.cellWidth
                index: model.myIndex
                onClicedIndex: {
                    _topElement.clickIndex = model.myIndex
                }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true

            color: Setting.styleApplicationColor
            border.color: Setting.styleTextColor
        }
    }

}
