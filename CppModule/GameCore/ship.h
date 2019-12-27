#ifndef SHIP_H
#define SHIP_H
#include "paluba.h"
#include "../Model/config.h"
#include <vector>

class Paluba;

class Ship
{
public:
    explicit Ship(int countPalub, int angle);
    int getCountPalub() const;
    QString getResourceImg() const;
    void setResourceImg(const QString &value);

private:
    int m_countLifePalub;
    QString resourceImg;
    int m_countPalub;
    int m_angle;
    std::vector<Paluba *> m_ship;
    std::vector<int> idexesPalubs;
};

#endif // SHIP_H
