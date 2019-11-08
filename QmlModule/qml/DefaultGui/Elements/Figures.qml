import QtQuick 2.0
import Settings 1.0

ListView {
    id: _root
    width: 100
    height: 230

    model: Setting.modelFlot

    delegate: DelegateFigure {
        width: _root.width
        height: _root.height / 10
    }
}
