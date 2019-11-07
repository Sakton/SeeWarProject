import QtQuick 2.0
import QtQuick.Controls 2.12
import "../ModeWindow"
import "../Settings"
import Settings 1.0

GridView {
    id: _grid
    width: height
    height: 230

    cellWidth: height / 9
    cellHeight: cellWidth

    model: Setting.modelField

    delegate: DelegateField {
        height: _grid.cellHeight
    }
}
