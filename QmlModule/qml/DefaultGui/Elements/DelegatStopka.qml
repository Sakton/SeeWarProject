import QtQuick 2.0

Rectangle {
    width: 100
    height: 230

    color: "blue"

    Rectangle {
        width: parent.width
        height: parent.height - 1

        color: "yellow"

        Text {
 //           text: model.indexFigure
        }
    }
}
