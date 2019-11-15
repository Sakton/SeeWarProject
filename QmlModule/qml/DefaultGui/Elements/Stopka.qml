import QtQuick 2.0
import QtQuick.Controls 2.12
import "../BaseElements"
import Settings 1.0


StackView  {
    id: _root

    property real dragSizeX: 0
    property real dragSizeY: 0

    width: 230
    height: 100

    Component.onCompleted: create()

    signal selectElementType(int typeElement)

    onSelectElementType: {
        console.debug("onSelectElementType = " + typeElement)
        _root.pop()
    }

    function create() {
        for(var j = 1; j <= 4; ++j) {
            for(var i = j; i <= 4; ++i) {
                var component = Qt.createComponent(Setting.urlElementFigureWindow)
                if(component.status === Component.Ready) {
                    var obj = component.createObject(_root,
                                                     {"type" : j,
                                                      "deltaDragMinX" : 0,
                                                      "deltaDragMinY" : -dragSizeY,
                                                      "deltaDragMaxX" : dragSizeX,
                                                      "deltaDragMaxY" : 0} )
                    obj.elementType.connect(selectElementType) //связи сигналов
                    _root.push(obj)
                }
            }
        }
    }
}
