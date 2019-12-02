import QtQuick 2.0
import Settings 1.0
//Все Главные окна с элементами меню должны наследовать этот класс

Item {
    width: Setting.mainWidth
    height: Setting.mainHeight
    //Сигнал типа окна (типы с ресурсами храним в настройках)
    signal buttonMenuClicked(int enumTypeButton)
}
