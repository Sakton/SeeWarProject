import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import Settings 1.0

Item {
    id: _root
    property int clickIndex: 0
    property string chatEnemyUser: ""
    width: 300
    height: 100

    onClickIndexChanged: {
        _logElement.textLog = "<b><font color = " + Setting.styleLogYourColor + ">" + Setting.textAppealYou + ": </b>" + clickIndex + "<br>"
    }

    Connections {
        target: Setting.userObject
        onAnswerFireToCell: {
            _logElement.textLog = "<b><font color = " + Setting.styleLogHiColor + ">" + Setting.textAppealHi + ": </b>" + index + "<br>"
        }
    }

    RowLayout {
        anchors.fill: parent
        spacing: 0

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
            LogElement {
                id: _logElement
                anchors.fill: parent
                nameLog: "Лог игры"
            }
        }

        Item {
            Layout.minimumWidth: parent.height
            Layout.fillHeight: true
            Field {
                //завернуто в Item не случайно
                anchors.fill: parent
                model: Setting.modelField
            }
        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
            ChatElement {
                id: _chatElement
                anchors.fill: parent
                nameLog: "Чатик"
            }
        }
    }
}
