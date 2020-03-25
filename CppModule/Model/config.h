#ifndef CONFIG_H
#define CONFIG_H
#include <vector>
#include <QString>

namespace Config {
    constexpr int NUM_ROW = 9;
    constexpr int NUM_COL = 9;
    constexpr int COUNT_CELL = NUM_ROW * NUM_COL;

    constexpr int MAX_COUNT_PALUBS = 4;
    constexpr int COUNT_SHIPS = 10;

    const QString PATH_OF_GUI_QML{QStringLiteral("qrc:/QmlModule/qml/DefaultGui/main.qml")};

    static std::vector<QString> imgShips{
        "qrc:/QmlModule/qml/DefaultGui/img/1xb1.png",
        "qrc:/QmlModule/qml/DefaultGui/img/2xb1.png",
        "qrc:/QmlModule/qml/DefaultGui/img/3xb1.png",
        "qrc:/QmlModule/qml/DefaultGui/img/4xb1.png"
    };

    static std::vector<std::pair<QString, QString>> imgShip_Normal_Damage{
        {"qrc:/QmlModule/qml/DefaultGui/img/1xb1.png",""},
        {"qrc:/QmlModule/qml/DefaultGui/img/2xb1.png",""},
        {"qrc:/QmlModule/qml/DefaultGui/img/3xb1.png",""},
        {"qrc:/QmlModule/qml/DefaultGui/img/4xb1.png",""}
    };

    //const QString DAMAGE_PALUBA_QURL = "qrc:/QmlModule/qml/DefaultGui/img/pirat1.png";
    const QString DAMAGE_PALUBA_QURL = "qrc:/QmlModule/qml/DefaultGui/img/galka.png";
    const QString MISS_QURL = "qrc:/QmlModule/qml/DefaultGui/img/redKrest.png";

    const QString GAME_SERVER_HOST{"127.0.0.1"};
    constexpr quint16 GAME_SERVER_PORT{50080};

    //имена полей для JSON
    const QString Name_User = "nameUser";
    const QString Id_Game = "idGame";
    const QString Fire_To_Cell = "fireCell";
    const QString Message = "message";
    const QString State_Game = "stateGame";
    const QString Hod = "hod";

}



#endif // CONFIG_H
