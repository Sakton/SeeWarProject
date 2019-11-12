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
    cellHeight: width / 9

    boundsBehavior: Flickable.StopAtBounds

    model: Setting.modelField

    delegate: DelegateField {
        height: _grid.cellHeight
    }
}
