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
//        _root.x = 0
//        _root.y = 2 * height
        _root.pop()
    }

    Loader {
        id: _loader
        anchors.fill: parent

    }

    function create() {
        for(var j = 1; j <= 4; ++j) {
            for(var i = j; i <= 4; ++i) {
                var component = Qt.createComponent(Setting.urlElementFigureWindow)
                if(component.status === Component.Ready) {
                    var obj = component.createObject(null, {"type": j})
                    obj.elementType.connect(selectElementType) //связи сигналов
                    _root.push(obj)
                }
            }
        }
    }

//        function create() {
//            for(var j = 1; j <= 4; ++j) {
//                for(var i = j; i <= 4; ++i) {
//                    _loader.source = Setting.urlElementFigureWindow
//                    _loader.item.type = j
//                    _loader.item.elementType.connect(selectElementType)
//                    _root.push(_loader.item)

//                }
//            }
//        }
}
