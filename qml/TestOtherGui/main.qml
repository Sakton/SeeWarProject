import QtQuick 2.12
import QtQuick.Window 2.12

//import seewar 1.0

//import "qml/ModeWindow"
Window {
	visible: true
	width: 460 //1200 / 2.6
	height: 230 //600 / 2.6
	title: ("TestOtherGuiNoQRC")
	Rectangle {
		anchors.fill: parent
		color: "red"
		Text {
			anchors.horizontalCenter: parent.horizontalCenter
			anchors.verticalCenter: parent.verticalCenter
			font.bold: true
			text: qsTr("TestOtherGui_NoQRC_in_Progect")
		}
	}
	MouseArea {
		anchors.fill: parent
		onClicked: {
			GuiLoader.setUrl("qrc:/qml/DefaultGui/main.qml")
		}
	}
}
