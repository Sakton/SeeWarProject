#ifndef SHIP_H
#define SHIP_H
#include "paluba.h"
#include "../Model/config.h"
#include <vector>

class Paluba;

class Ship
{
public:
    explicit Ship(int countPalubs, int angle);

private:
    int m_countLifePalub;
    int m_angle;
    std::vector<Paluba *> m_ship;
};

#endif // SHIP_H
