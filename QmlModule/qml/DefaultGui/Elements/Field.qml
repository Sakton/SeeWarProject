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
        id: _d
        indexElement: {
            //промежуточная переменная для предотвращения частых вызовов модели
            var indexObject = model.indexElement
            return (indexObject === undefined) ? -1 : indexObject
        }
        //        pointerToObjectCell: {
        //            var element = model.pointerObjectCell.figure
        //            console.debug("model.pointerObjectCell = " + element)
        //            element
        //        }
        colorCell: model.colorElement
        imageResource: model.imageResourceCell
        height: _grid.cellHeight
    }
}
