import QtQuick 2.0
import QtQuick.Layouts 1.12
import Settings 1.0


Item {
    id: _root
    //интерфейс элемента получается
    //к ним идет обращение в аррагементе
    property int type: 0
    property bool horizontal: false
//    property bool zerkalno: false
    property real deltaDragMinY: 0
    property real deltaDragMinX: 0
    property real deltaDragMaxY: 0
    property real deltaDragMaxX: 0
    property var bindingTarget: null

    signal elementType(var typeElement)
    implicitWidth: 360
    implicitHeight: 650

//    source: "qrc:/QmlModule/qml/DefaultGui/img/storm.gif"



    onHorizontalChanged: {
        if (horizontal)
            _blockCountPalubs.rotation = 0
        else
            _blockCountPalubs.rotation = 90
    }

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

            source: {
                switch(type) {
                case 1:
                    "qrc:/QmlModule/qml/DefaultGui/img/1x.png"
                    break
                case 2:
                    "qrc:/QmlModule/qml/DefaultGui/img/2x.png"
                    break
                case 3:
                    "qrc:/QmlModule/qml/DefaultGui/img/3x.png"
                    break
                case 4:
                    "qrc:/QmlModule/qml/DefaultGui/img/4x.png"
                    break
                default:
                    "qrc:/QmlModule/qml/DefaultGui/img/1x.png"
                }
            }

            Item {
                id: _blockCountPalubs
                width: (parent.width * type / 16)
                height: (parent.height / 8)

                RowLayout {
                    anchors.fill: parent
                    spacing: 2
                    //rotation: 90
                    //                    Rotation {
                    //                        angle: 0
                    //                        origin.x:
                    //                    }

                    Repeater {
                        model: type
                        delegate: Rectangle {
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            color: Setting.styleTextColor
                        }
                    }
                }
            }

            transform: Scale {
                id: _scale
                xScale: 1
            }

            onZerkalnoChanged: {
                _scale.xScale = (zerkalno === false) ? 1 : -1
                if(_scale.xScale === -1) {
//                    _mouseArea.drag.minimumX = parent.width / 2
                    _mouseArea.drag.maximumX = deltaDragMaxX - parent.width / 2
                } else {
                    _mouseArea.drag.maximumX = deltaDragMaxX - parent.width * 1.5
                }
            }

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
                    if(dragActive) {
                        Drag.start()
                        cursorShape = Qt.DragMoveCursor

                    } else {
                        cursorShape = Qt.ArrowCursor
                        Drag.drop()
                        elementType(type)
                    }
                }

                onPositionChanged: {
                    if(dragActive) {
                        Drag.start()
                    }
                }
            } //ma
        } //_img



    }
}


