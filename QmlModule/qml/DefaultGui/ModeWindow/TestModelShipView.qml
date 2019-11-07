import QtQuick 2.0

ListModel {
    Repeater {
        model: 10
        ListElement {
            shipIndex: index
        }
    }
}
