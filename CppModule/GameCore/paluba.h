#ifndef PALUBA_H
#define PALUBA_H
#include "../Model/abstractgamefigure.h"
#include "ship.h"

class Ship;

class Paluba : AbstractGameFigure
{
public:
    explicit Paluba(Ship *ship, int numberPalub/*, QString resourceImg*/);
    // AbstractGameFigure interface
    void testFunction() override;
    QColor getColor() override;
    QString getResourceImg() override;

private:
    Ship *m_ship;
    int m_numberPalub;

    QString m_resourceImg;
};

#endif // PALUBA_H
