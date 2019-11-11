import QtQuick 2.0
import QtQuick.Controls 2.12
import "../ModeWindow"
import "../Settings"
import Settings 1.0

//GridView {
//    id: _grid
//    width: height
//    height: 230

//    cellWidth: height / 9
//    cellHeight: cellWidth

//    model: Setting.modelField

//    delegate: DelegateField {
//        height: _grid.cellHeight
//    }
//}

GridView {
    id: _grid
    width: 230
    height: width

//    cellWidth: height / 9
//    cellHeight: cellWidth

    cellWidth: cellHeight
    cellHeight: width / 9

    model: Setting.modelField

    delegate: DelegateField {
        height: _grid.cellHeight
    }
}
