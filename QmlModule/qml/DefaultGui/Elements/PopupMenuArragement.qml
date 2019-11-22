import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import Settings 1.0

Popup {
    id: _root
    signal buttonOK;
    signal buttonRotate;

    width: 200
    height: 100
    padding: 1
//    modal: true
//    closePolicy: Popup.CloseOnEscape

    background: Rectangle {
        anchors.fill: parent
        color: Setting.styleTextColor
        radius: width / Setting.kRadius
    }

//    opacity: 0.8

    RowLayout {
        anchors.fill: parent
        spacing: 0

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: Setting.styleByttonColor
            //border.color: Setting.
            radius: _root.width / Setting.kRadius

            Image {
                id: _iRot
                width: height
                height: parent.height / 2
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                source: Setting.rotateImg

                transform:  Rotation {
                    id: _rotation
                    origin.x: _iRot.width / 2
                    origin.y: _iRot.height / 2
                    angle: 0

                    SequentialAnimation  on angle {
                        loops:  Animation.Infinite
                        PropertyAnimation {
                            duration: 2500
                            to: 359 }
                    }
                }
            }

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: parent.width / 4
                font.bold: true
                color: Setting.styleTextColor
                text: qsTr("R")
            }

            Text {
                anchors.bottom: parent.bottom
                anchors.bottomMargin: Setting.hintButtonBottomMargins
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Повернуть")
                color: Setting.styleTextColor
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    buttonRotate()
                }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: Setting.styleByttonColor
            radius: _root.width / Setting.kRadius

            Image {
                id: _iOk
                width: height
                height: parent.height / 2
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                source: Setting.okImg

                transform:  Rotation {
                    id: _rotationOk
                    origin.x: _iOk.width / 2
                    origin.y: _iOk.height / 2
                    axis {
                        x: 0
                        y: 1
                        z: 0
                    }
                    angle: 0

                    SequentialAnimation on angle {
                        loops:  Animation.Infinite
                        PropertyAnimation {
                            duration: 1500
                            to: 359 }
                    }
                }
            }

            Text {
                anchors.bottom: parent.bottom
                anchors.bottomMargin: Setting.hintButtonBottomMargins
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Установить")
                color: Setting.styleTextColor
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    buttonOK()
                }
            }
        }
    }
}
