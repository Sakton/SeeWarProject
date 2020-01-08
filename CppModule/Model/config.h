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

    static std::vector<QString> imgShips{
        "qrc:/QmlModule/qml/DefaultGui/img/1xb1.png",
        "qrc:/QmlModule/qml/DefaultGui/img/2xb1.png",
        "qrc:/QmlModule/qml/DefaultGui/img/3xb1.png",
        "qrc:/QmlModule/qml/DefaultGui/img/4xb1.png"
    };
}



#endif // CONFIG_H