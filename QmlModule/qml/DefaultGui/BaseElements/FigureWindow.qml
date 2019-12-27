import QtQuick 2.0
import QtQuick.Layouts 1.12
import Settings 1.0

Item {
    id: _root
    //интерфейс элемента получается
    //к ним идет обращение в аррагементе
    property int countPalubs: 0
    //    property bool zerkalno: false
    property real deltaDragMinY: 0
    property real deltaDragMinX: 0
    property real deltaDragMaxY: 0
    property real deltaDragMaxX: 0
    property var bindingTarget: null
    property string imgSource: ""

    signal elementType(var typeElement)
    implicitWidth: 360
    implicitHeight: 650
    opacity: 0.8

    Item {
        id: _dragItem

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        width: parent.width / 2
        height: parent.height / 2

        Image {
            id: _img
            anchors.fill: parent
            property bool zerkalno: false
            source: imgSource

            //            source: {
            //                switch (countPalubs) {
            //                case 1:
            //                    return Setting.ship1
            //                case 2:
            //                    return Setting.ship2
            //                case 3:
            //                    return Setting.ship3
            //                case 4:
            //                    return Setting.ship4
            //                }
            //            }
            transform: Scale {
                id: _scale
                xScale: 1
            }

            onZerkalnoChanged: {
                _scale.xScale = (zerkalno === false) ? 1 : -1
                if (_scale.xScale === -1) {
                    _mouseArea.drag.maximumX = deltaDragMaxX - parent.width / 2
                    _mouseArea.drag.minimumX = parent.width / 3
                } else {
                    _mouseArea.drag.minimumX = deltaDragMinX - parent.width / 2
                    _mouseArea.drag.maximumX = deltaDragMaxX - parent.width * 1.5
                }
            }

            Item {
                id: _blockCountPalubs
                property int rotateAngle: 0
                width: (parent.width * countPalubs / 16)
                height: (parent.height / 8)

                onRotateAngleChanged: {
                    _rotate.angle = rotateAngle
                }

                transform: Rotation {
                    id: _rotate
                    origin.x: _blockCountPalubs.width / (2 * countPalubs)
                    origin.y: _blockCountPalubs.height / 2
                    angle: _blockCountPalubs.rotateAngle
                }

                RowLayout {
                    anchors.fill: parent
                    spacing: 2

                    Repeater {
                        model: countPalubs
                        delegate: Rectangle {
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            color: Setting.styleTextColor
                        }
                    }
                }
            } //blockCountPalubs

            MouseArea {
                id: _mouseArea
                property bool dragActive: _mouseArea.drag.active

                anchors.fill: parent
                drag.target: parent
                Drag.dragType: Drag.Automatic
                Drag.hotSpot.x: 0
                Drag.hotSpot.y: 0
                drag.minimumX: deltaDragMinX - parent.width / 2
                drag.maximumX: deltaDragMaxX - parent.width * 1.5
                drag.minimumY: deltaDragMinY - parent.height / 2
                drag.maximumY: deltaDragMaxY

                onPressed: {
                    parent.anchors.fill = undefined
                }

                onDragActiveChanged: {
                    if (dragActive) {
                        Drag.start()
                        cursorShape = Qt.DragMoveCursor
                    } else {
                        cursorShape = Qt.ArrowCursor
                        Drag.drop()
                        elementType(countPalubs)
                    }
                }

                onPositionChanged: {
                    if (dragActive) {
                        Drag.start()
                    }
                }
            } //MouseArea
        } //Image
    }
}
