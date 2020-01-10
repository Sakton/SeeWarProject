import QtQuick 2.0
import Settings 1.0


QtObject {

    property var currentObject: null

    function createObject(resourceObject) {
        var component = Qt.createComponent(resourceObject);
        if(component.status === Component.Ready){
            if(currentObject !== null)
                currentObject.destroy()
            currentObject = component.createObject(_root, {"width":_root.width, "height":_root.height})
            currentObject.buttonMenuClicked.connect(loaderWindow)
        }
        return currentObject
    }

    function loaderWindow(indexWindow) {
        var fileLoad = null;
        switch(indexWindow) {
        case Setting.MyEnumButton.BUTTON_ANDROID:
            createObject(Setting.window_ARRAGEMENT)
            break;
        case Setting.MyEnumButton.BUTTON_NETWORK:
            createObject(Setting.window_GAME)
            break;
        case Setting.MyEnumButton.BUTTON_CUSTOMIZATION:
            break;
        case Setting.MyEnumButton.BUTTON_GAME:
            createObject(Setting.window_GAME)
            break;
        case Setting.MyEnumButton.BUTTON_EDITING:
            console.log("Load Editing_Window")
            break;
        case Setting.MyEnumButton.BUTTON_DISCHARGE:
            console.log("Reload Arragement Window")
            break;
        case Setting.MyEnumButton.BUTTON_AUTOALIGMENT:
            console.log("Call AoutoAligment Function")
            break;
        case Setting.MyEnumButton.BUTTON_REPEAT:
            console.log("Press Button Repeat")
            break;
        case Setting.MyEnumButton.BUTTON_BACK:
            createObject(Setting.window_STARTMENU)
            break;
        }
    }
}
