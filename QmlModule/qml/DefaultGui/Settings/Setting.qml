pragma Singleton

import QtQuick 2.0
import "../ModeWindow"

QtObject {
    //models
    property var modelField: TestModelGridView {}
    property var modelFlot: TestModelShipView {}
    //colors
    readonly property color styleApplicationColor: "blue"
}
