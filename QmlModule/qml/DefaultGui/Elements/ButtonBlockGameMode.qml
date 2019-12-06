import QtQuick 2.0
import QtQuick.Layouts 1.12
import Settings 1.0
import "../BaseElements"

BasicButtonBlockModes {
    width: 100
    height: 230
    modelTopPodBlock: [
        {idBtn : Setting.MyEnumButton.BUTTON_RESERVE,
            name : ""/*Setting.buttonName_GAME*/,
            urlImg : "" /*Setting.img_PLAY*/},
        { idBtn : Setting.MyEnumButton.BUTTON_RESERVE,
            name : ""/*Setting.buttonName_CORRECT*/,
            urlImg : ""/*Setting.img_CORRECT*/
        }]

    modelBottomPodBlock:[
        {idBtn : Setting.MyEnumButton.BUTTON_AGAIN,
            name : Setting.buttonName_AGAIN,
            urlImg : Setting.img_POVTOR},
        {idBtn : Setting.MyEnumButton.BUTTON_BACK,
            name : Setting.buttonName_MENU,
            urlImg : Setting.img_MENU
        }]
}
