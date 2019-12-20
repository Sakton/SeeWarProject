import QtQuick 2.0
import QtQuick.Controls 2.12
import "../ModeWindow"
import "../Settings"
import Settings 1.0


GridView {
    id: _grid
    width: 230
    height: width
    cellWidth: cellHeight
    cellHeight: width / Setting.countsCells

    boundsBehavior: Flickable.StopAtBounds

    delegate: DelegateField {
        indexElement: model.IndexElement


        height: _grid.cellHeight
    }
}
