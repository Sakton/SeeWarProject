import QtQuick 2.0
import QtQuick.Layouts 1.12
import Settings 1.0
import "../BaseElements"

BasicButtonBlockModes {
    width: 100
    height: 230
    modelTopPodBlock: [
        {idBtn : Setting.MyEnumButton.BUTTON_GAME,
            name : Setting.buttonName_GAME,
            urlImg : Setting.img_PLAY},
        { idBtn : Setting.MyEnumButton.BUTTON_EDITING,
            name : Setting.buttonName_CORRECT,
            urlImg : Setting.img_CORRECT
        }]
    modelBottomPodBlock:[
        {idBtn : Setting.MyEnumButton.BUTTON_DISCHARGE,
            name : Setting.buttonName_CLEAR,
            urlImg : Setting.img_CLEAR},
        {idBtn : Setting.MyEnumButton.BUTTON_AUTOALIGMENT,
            name : Setting.buttonName_AUTOALIGNMENT,
            urlImg : Setting.img_AUTOALIGMENT}]
}

