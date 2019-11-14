import QtQuick 2.0
import QtGraphicalEffects 1.12
import Settings 1.0

RadialGradient {
    width: 230
    height: 100

    property var centerPoint: Qt.point(0,0)
    property var radius: 100
    property color startColor: "white"
    property color endColor: "black"

    //    property var startPoint: Qt.point(0,0)
    //    property var endPoint: Qt.point(width, height)

    //    start: startPoint
    //    end: endPoint

    gradient: Gradient {
        GradientStop {
            position: 0.2
            color: startColor
        }
        GradientStop {
            position: 1.0
            color: endColor
        }
    }
}
