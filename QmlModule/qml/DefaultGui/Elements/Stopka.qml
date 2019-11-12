import QtQuick 2.0
import QtQuick.Controls 2.12
import "../BaseElements"
import Settings 1.0

StackView  {
    id: _root
    width: 100
    height: 230
    visible: true
    Component.onCompleted: create()

    signal selectElementType(int typeElement)

    onSelectElementType: {
        console.debug("onSelectElementType = " + typeElement)
        _root.x = 0
        _root.y = 2 * height
        _root.pop()
    }

    function create() {
        for(var j = 1; j <= 4; ++j) {
            for(var i = 1; i <= j; ++i) {
                var component = Qt.createComponent(Setting.urlElementFigureWindow)
                if(component.status === Component.Ready) {
                    var obj = component.createObject(null, {"type": i})
                    obj.elementType.connect(selectElementType) //связи сигналов
                    _root.push(obj)
                }
            }
        }
    }
}
