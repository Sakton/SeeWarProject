import QtQuick 2.0
import Settings 1.0

Item {
    width: height
    height: 30
    //color: Setting.styleTextColor
//    color: Setting.styleApplicationColor

//    border.color: "red"
//    border.width: 1

    //тут должны быть пропертиес для подключения извне
//    Rectangle {
//        width: parent.width - 1
//        height: width
//        anchors.centerIn: parent.Center

//        color: Setting.styleByttonColor

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            color: "red"
            font.pixelSize: parent.width / 3

            text: model.muIndex //TODO убрать зависимость
        }
//    }
}
