import QtQuick 2.0
import QtQuick.Layouts 1.12
import Settings 1.0


Item {
    id: _root
    property int type: 0
    property bool horizontal: false
    property real deltaDragMinY: 0
    property real deltaDragMinX: 0
    property real deltaDragMaxY: 0
    property real deltaDragMaxX: 0

    signal elementType(var typeElement)

    width: 230
    height: 100

    onHorizontalChanged: {
        if (horizontal)
            _blockCountPalubs.rotation = 0
        else
            _blockCountPalubs.rotation = 90
    }

    Image {
        id: _img
        //fillMode: Image.Stretch
        anchors.fill: parent

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
            width: (_root.width * type / 16)
            height: _root.height / 8

            RowLayout {
                anchors.fill: parent
                spacing: 1
                //rotation: 90
                Repeater {
                    model: type
                    delegate: Rectangle {
                        width: parent.width / type
                        height: parent.height
                        color: Setting.styleTextColor
                    }
                }
            }
        }
    }

    MouseArea {
        id: _mouseArea

        property bool dragActive: _mouseArea.drag.active

        anchors.fill: parent
        drag.target: parent
        Drag.dragType: Drag.Automatic
        Drag.hotSpot.x: 0 //_root.width / 2
        Drag.hotSpot.y: 0 //_root.height / 2
        drag.minimumX: deltaDragMinX
        drag.maximumX: deltaDragMaxX
        drag.minimumY: deltaDragMinY
        drag.maximumY: deltaDragMaxY

        onDragActiveChanged: {
            console.debug("deltaDragMinX" + deltaDragMinX)
            console.debug("deltaDragMinY" + deltaDragMinY)
            console.debug("deltaDragMaxX" + deltaDragMaxX)
            console.debug("deltaDragMaxY" + deltaDragMaxY)

            console.debug("dragActiv" + dragActive)
            if(dragActive) {
                Drag.start()
                //                    drag.target.width *= 0.5
                //                    drag.target.height *= 0.5
                //                    drag.target.opacity = 0.5
                cursorShape = Qt.DragMoveCursor

            } else {
                //                    drag.target.width *= 2
                //                    drag.target.height *= 2
                //                    drag.target.opacity = 1
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
    }
}




//MouseArea {
//    id: _root

//    property int type: 0
//    property bool dragActive: _root.drag.active
//    property bool horizontal: false
//    signal elementType(var typeElement)

//    width: 230
//    height: 100

//    drag.target: _root
//    Drag.dragType: Drag.Automatic
//    Drag.hotSpot.x: 0//_root.width / 2
//    Drag.hotSpot.y: 0//_root.height / 2
//    drag.minimumX: 0
//    drag.maximumX: _root.width //????
//    drag.minimumY: 0
//    drag.maximumY: _root.height * 2

//    onHorizontalChanged: {
//        if(horizontal)
//            _blockCountPalubs.rotation = 0
//        else
//            _blockCountPalubs.rotation = 90
//    }

//    onPositionChanged: {
//        if(dragActive) {
//            Drag.start()
//        }
//    }

//    onDragActiveChanged: {
//        console.debug("dragActiv" + dragActive)
//        if(dragActive) {
//            Drag.start()
//            drag.target.width *= 0.5
//            drag.target.height *= 0.5
//            drag.target.opacity = 0.5
//            cursorShape = Qt.DragMoveCursor

//        } else {
//            drag.target.width *= 2
//            drag.target.height *= 2
//            drag.target.opacity = 1
//            cursorShape = Qt.ArrowCursor
//            Drag.drop()
//            elementType(type)
//        }
//    }

//    Image {
//        id: _img
//        anchors.fill: parent
//        source: {
//            switch(type) {
//            case 1:
//                "qrc:/QmlModule/qml/DefaultGui/img/1x.png"
//                break
//            case 2:
//                "qrc:/QmlModule/qml/DefaultGui/img/2x.png"
//                break
//            case 3:
//                "qrc:/QmlModule/qml/DefaultGui/img/3x.png"
//                break
//            case 4:
//                "qrc:/QmlModule/qml/DefaultGui/img/4x.png"
//                break
//            default:
//                "qrc:/QmlModule/qml/DefaultGui/img/1x.png"
//            }
//        }

//        Item {
//            id: _blockCountPalubs
//            width: (_root.width * type / 16)
//            height: _root.height / 8

//            RowLayout {
//                anchors.fill: parent
//                spacing: 1
//                //rotation: 90
//                Repeater {
//                    model: type
//                    delegate: Rectangle {
//                        width: parent.width / type
//                        height: parent.height
//                        color: Setting.styleTextColor
//                    }
//                }
//            }
//        }
//    }
//}


