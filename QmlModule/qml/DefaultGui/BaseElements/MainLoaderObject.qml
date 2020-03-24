import QtQuick 2.0
import "../Settings/"

QtObject {

    property var currentObject: null

    function createObject(resourceObject) {
        var component = Qt.createComponent(resourceObject);
        console.log("component = " + component)
        if(component.status === Component.Ready) {
            if(currentObject !== null)
                currentObject.destroy()
            currentObject = component.createObject(_root, {"width":_root.width, "height":_root.height})
            //сединение сигнала buttonMenuClicked кнопок с слотом loaderWindow
            currentObject.buttonMenuClicked.connect(loaderWindow)
        }
        if(component.status === Component.Error)
            //Ошибки создания компонентов
            console.debug("component.errorString = " + component.errorString())
        return currentObject
    }

    function loaderWindow(indexWindow) {
        switch(indexWindow) {
        case Setting.MyEnumButton.BUTTON_ANDROID:
            createObject(Setting.window_ARRAGEMENT)
            break;
        case Setting.MyEnumButton.BUTTON_NETWORK:
            createObject(Setting.window_GAME)
            break;
        case Setting.MyEnumButton.BUTTON_CUSTOMIZATION:
            console.log("BUTTON_CUSTOMIZATION")
            break;
        case Setting.MyEnumButton.BUTTON_GAME:
            createObject(Setting.window_GAME)
            break;
        case Setting.MyEnumButton.BUTTON_EDITING:
            console.log("Load Editing_Window")
            break;
        case Setting.MyEnumButton.BUTTON_DISCHARGE:
            //WARNING ПЛОХО ТУТ СИДИТ СИГНАЛ (МЕТОД)
            Setting.modelFlot.resetAll();
            createObject(Setting.window_ARRAGEMENT)
            break;
        case Setting.MyEnumButton.BUTTON_AUTOALIGMENT:
            createObject(Setting.window_ARRAGEMENT)
            //WARNING ПЛОХО ТУТ СИДИТ СИГНАЛ (МЕТОД)
            Setting.modelFlot.autoArragement();
            break;
        case Setting.MyEnumButton.BUTTON_REPEAT:
            console.log("Press Button Repeat")
            break;
        case Setting.MyEnumButton.BUTTON_BACK:
            createObject(Setting.window_STARTMENU)
            break;
        case Setting.MyEnumButton.BUTTON_AGAIN:
            console.log("BUTTON_AGAIN")
            //TODO для теста
            //Setting.userObject.damag = (Setting.userObject.damag === 0) ? 1 : 0;
            break;
        }
    }
}
