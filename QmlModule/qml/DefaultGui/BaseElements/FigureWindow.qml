import QtQuick 2.0

Item {
    id: _root
    property int type: 0
//    MouseArea {
//        anchors.fill: parent
//        onClicked: {
//            console.debug(type)
//        }
//    }

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


