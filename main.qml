import QtQuick 2.12
import QtQuick.Window 2.12
import "qml/ModeWindow"

Window {
	visible: true
	width: 460 //1200 / 2.6
	height: 230 //600 / 2.6
	title: ("mobWindow")

	//	PlacementMode {
	//		anchors.fill: parent
	//	}
	SelectionMenuMode {
		anchors.fill: parent
	}
}
