import QtQuick 2.0
import QtQuick.Controls 2.12
import "../BaseElements"
import Settings 1.0


StackView  {
    id: _root
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
                                                     {"type": j})

                    obj.elementType.connect(selectElementType) //связи сигналов
                    _root.push(obj)
                }
            }
        }
    }
}
