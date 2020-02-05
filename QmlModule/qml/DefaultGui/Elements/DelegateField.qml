import QtQuick 2.0
import Settings 1.0

Item {
    id: _root
    width: height
    height: 30
    //все роли модели
    property int indexElement: 0
    property color colorCell: "black"
    property int stateCell: 0
    property var pointerToObjectCell: null
    property string imageResource: ""
    property int rotateAngle: 0

    onColorCellChanged: {
        //TODO баловство, но может потом
        _mycanvas.requestPaint()
    }

    Canvas {
        id: _mycanvas
        anchors.fill: parent
        renderStrategy: Canvas.Threaded

        onPaint: {
            var ctx = getContext("2d")
            ctx.setLineDash([1, 3]); //установка линии из точек
            ctx.strokeStyle = colorCell
            ctx.strokeRect( 0, 0, _root.width + 1, _root.height + 1)
        }
    }

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: Setting.styleTextColor
        font.pixelSize: parent.width / 3
        text: indexElement
    }

    Image {
        //anchors.fill: parent
        width: parent.width - parent.width / 10
        height: parent.height - parent.height / 10
        source: imageResource
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        rotation: rotateAngle
    }
}
