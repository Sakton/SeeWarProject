import QtQuick 2.0
import QtQuick.Controls 2.12
import "../BaseElements"
import Settings 1.0

StackView {
    id: _root

    property real dragSizeX: 0
    property real dragSizeY: 0

    implicitWidth: Setting.mainWidth
    implicitHeight: Setting.mainHeight / 4

    //    Component.onCompleted: create()
    signal selectElementType(int typeElement)

    //********
    property var myModel: null
    //********

    onMyModelChanged: {
        _repeater.model = myModel
    }

    Repeater {
        id: _repeater
        model: Setting.modelFlot
        delegate: FigureWindow {
            id: _delegate
            Component.onCompleted: _root.push(_delegate)
            countPalubs: model.countPalub
            imgSource: model.img
            selfIndex: model.index
            deltaDragMinX: 0
            deltaDragMinY: -dragSizeX
            deltaDragMaxX: dragSizeX
            deltaDragMaxY: 0
        }
    }

    //    function create() {
    //        for(var j = 1; j <= 4; ++j) {
    //            for(var i = j; i <= 4; ++i) {
    //                var component = Qt.createComponent(Setting.urlElementFigureWindow)
    //                if (component.status === Component.Ready) {
    //                    var obj = component.createObject(_root,
    //                                                     {"countPalubs" : j,
    //                                                         "deltaDragMinX" : 0,
    //                                                         "deltaDragMinY" : -dragSizeY,
    //                                                         "deltaDragMaxX" : dragSizeX,
    //                                                         "deltaDragMaxY" : 0
    //                                                     } )
    //                    obj.elementType.connect(selectElementType) //связи сигналов
    //                    _root.push(obj)
    //                }
    //            }
    //        }
    //    }
}
