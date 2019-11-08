import QtQuick 2.0

ListModel {
    id: _root

    Component.onCompleted: {
        listAdd();
    }

    function listAdd() {
        for(var i = 0; i < 10; ++i){
            _root.append({"indexFigure" : i})
        }
    }
}
