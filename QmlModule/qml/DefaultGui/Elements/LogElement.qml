import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import Settings 1.0
import "../Elements"

Item {
    id: _root
    property string textLog:"<b><font color = " + Setting.styleLogYourColor + ">Ты: </b>" +
                         "<br>" +
                         "<b><font color = " + Setting.styleLogHiColor + ">Он: </br>"
    property string nameLog: ""
    width: 100
    height: 200

    onTextLogChanged: _textAreaLog.insert(0, textLog)

    ColumnLayout {
        anchors.fill: parent

        Text {
            horizontalAlignment: Text.Center
            Layout.fillWidth: true
            Layout.minimumHeight: height
            color: Setting.styleTextColor
            textFormat: Text.RichText
            text: qsTr("<h3><b><i>" + nameLog + "</i></b></h3>")
        }

        ScrollView  {
            id: _scrollLog
            Layout.fillWidth: true
            Layout.fillHeight: true

            ScrollBar.horizontal: ScrollBar {
                active: false
            }

            ScrollBar.vertical: ScrollBar {
                parent: _scrollLog
                x: 0
                width: _scrollLog.width / 15
                active: true
                height: _scrollLog.height
                contentItem: Rectangle {
                    color: Setting.styleTextColor
                }
            }

            TextArea {
                id: _textAreaLog
                anchors.fill: parent
                color: Setting.styleTextColor
                textFormat: Text.RichText
                clip: true
                text: text
                onTextChanged: {
                    //FIXME
                    //Это влияет на поведение скроллбара скроллвиева, чтоб курсор оставался в 0, тогда
                    //полоса прокрутки стоит на месте
                    cursorPosition = 0
                }
            } //TextArea
        } //ScrollView
    }
}
