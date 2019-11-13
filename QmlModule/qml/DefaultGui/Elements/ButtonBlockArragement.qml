import QtQuick 2.0
import QtQuick.Layouts 1.12
import Settings 1.0
import "../BaseElements"

//Rectangle {
//    width: 100
//    height: 230

//    color: "white"

//    ColumnLayout {
//        id: _container
//        anchors.fill: parent
//        spacing: 1
////        Component.onCompleted: addBtn(_container, 4)
////        onHeightChanged: correctHeight(_container, 4)

//        ButtonArragement {
//            idBtn: 0
//            Layout.fillWidth: true
//            Layout.fillHeight: true

//            text: "Играть"
//        }
//        ButtonArragement {
//            idBtn: 1
//            Layout.fillWidth: true
//            Layout.fillHeight: true

//            text: "Править"
//        }
//        ButtonArragement {
//            idBtn: 2
//            Layout.fillWidth: true
//            Layout.fillHeight: true

//            text: "Сброс"
//        }
//        ButtonArragement {
//            idBtn: 3
//            Layout.fillWidth: true
//            Layout.fillHeight: true

//            text: "Авто"
//        }
//    }

////    //TODO сжимает последний элемент почему-то
////    function addBtn(parentElement, countElement) {
////        for(var i = 0; i < countElement; ++i) {
////            var component = Qt.createComponent("../BaseElements/ButtonArragement.qml");
////            if ( component.status === Component.Ready ) {
////                var btn = component.createObject( parentElement )
////                btn.Layout.fillWidth = true
////                btn.Layout.preferredHeight = parentElement.height / countElement
////                btn.idBtn = i
////                btn.text = "Button_" + i
////            }
////        }
////    }

////    //костыль для обновления высоты (почемуто не работает последняя кнопка)
////    function correctHeight(parent, count) {
////        for(var i = 0; i < count; ++i) {
////            var btn = parent.children[i];
////            btn.Layout.fillHeight = true
////        }
////    }
//}

Rectangle {
    width: 100
    height: 230
    color: Setting.styleTextColor

//Grid !???
    ColumnLayout {
        id: _container
        anchors.fill: parent

//        width: 100
//        height: 230
        spacing: 1
        //        Component.onCompleted: addBtn(_container, 4)
        //        onHeightChanged: correctHeight(_container, 4)

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 1

            ButtonArragement {
                idBtn: 0
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "Играть"
            }

            ButtonArragement {
                idBtn: 1
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "Править"
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 1

            ButtonArragement {
                idBtn: 2
                Layout.fillWidth: true
                Layout.fillHeight: true

                text: "Сброс"
            }

            ButtonArragement {
                idBtn: 3
                Layout.fillWidth: true
                Layout.fillHeight: true

                text: "Авто"
            }
        }
    }

    //    //TODO сжимает последний элемент почему-то
    //    function addBtn(parentElement, countElement) {
    //        for(var i = 0; i < countElement; ++i) {
    //            var component = Qt.createComponent("../BaseElements/ButtonArragement.qml");
    //            if ( component.status === Component.Ready ) {
    //                var btn = component.createObject( parentElement )
    //                btn.Layout.fillWidth = true
    //                btn.Layout.preferredHeight = parentElement.height / countElement
    //                btn.idBtn = i
    //                btn.text = "Button_" + i
    //            }
    //        }
    //    }

    //    //костыль для обновления высоты (почемуто не работает последняя кнопка)
    //    function correctHeight(parent, count) {
    //        for(var i = 0; i < count; ++i) {
    //            var btn = parent.children[i];
    //            btn.Layout.fillHeight = true
    //        }
    //    }
}
