import QtQuick 2.0

import QtQuick 2.0
import QtQuick.Layouts 1.12
import Settings 1.0
import "../BaseElements"

Rectangle {
    width: 100
    height: 230
    color: Setting.styleTextColor
    property var modelTopPodBlock: null
    property var modelBottomPodBlock: null
    signal clickedButtonOnBlock(int idBtn)



    ColumnLayout {
        id: _container
        anchors.fill: parent
        spacing: 1

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 1

            Repeater {
                model: modelTopPodBlock
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
                model: modelBottomPodBlock
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

