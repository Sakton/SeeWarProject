import QtQuick 2.0

ListModel {
    id: root
    Component.onCompleted: {
        appnd()
    }

    function appnd() {
        for (var i = 0; i < 81; ++i) {
            root.append({
//                            "myIndex": i
                            "IndexView" : i
                        })
        }
    }
}
