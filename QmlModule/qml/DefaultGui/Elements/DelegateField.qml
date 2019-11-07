import QtQuick 2.0

Rectangle {
    width: height
    height: 30
    color: "magenta"

    //тут должны быть пропертиес для подключения извне
    Rectangle {
        width: parent.width - 1
        height: width
        anchors.centerIn: parent.Center

        color: "green"

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            font.pixelSize: parent.width / 3

            text: model.muIndex //TODO убрать зависимость
        }
    }
}
