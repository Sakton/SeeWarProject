import QtQuick 2.0
import QtQuick.Controls 2.12
import "../BaseElements"

StackView  {
    id: _root
    width: 100
    height: 230
    visible: true
    Component.onCompleted: create()

    MouseArea {
        anchors.fill: parent
        onClicked: {
            parent.pop()
        }
    }

//    Connections {
//        target:
//    }


    function create() {
        for(var j = 1; j <= 4; ++j) {
            for(var i = 1; i <= j; ++i) {
                var component = Qt.createComponent("qrc:/QmlModule/qml/DefaultGui/BaseElements/FigureWindow.qml")
                if(component.status === Component.Ready) {
                    console.debug("do" + _root.depth)
                    var obj = component.createObject(null, {"type": i})
                    _root.push(obj)
                    console.debug("posle" + _root.depth)
                }
            }
        }
    }
}
