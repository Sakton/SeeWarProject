import QtQuick 2.0

MouseArea {
    id: _root
    width: 230
    height: 100
//    anchors.fill: parent
    property int type: 0
    property bool dragActive: _root.drag.active
    signal elementType(var typeElement)

    drag.target: parent
    Drag.dragType: Drag.Automatic
    Drag.hotSpot.x: _root.width / 2
    Drag.hotSpot.y: _root.height / 2

    onPositionChanged: {
        if(dragActive)
            Drag.start()
    }

    onDragActiveChanged: {
        console.debug(dragActive)
        if(dragActive) {
            Drag.start()
            drag.target.width *= 0.5
            drag.target.height *= 0.5
            drag.target.opacity = 0.5
            cursorShape = Qt.DragMoveCursor

        } else {
            drag.target.width *= 2
            drag.target.height *= 2
            drag.target.opacity = 1
            cursorShape = Qt.ArrowCursor
            Drag.drop()
            elementType(type)
        }
    }

    Image {
        id: _img
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

        Text {
            id: _text
            font.pixelSize: _root.width / 4
            color: "yellow"
            text: type
        }
    }
}


