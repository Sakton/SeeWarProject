#include "ship.h"

Ship::Ship(int countPalub, int angle):m_countLifePalub{countPalub}, m_countPalub{countPalub}, m_angle{angle}
{
    for(int i = 1; i <= countPalub; ++i )
        m_ship.push_back(new Paluba(this, i));
}

int Ship::getCountPalub() const
{
    return m_countPalub;
}

QString Ship::getResourceImg() const
{
    return resourceImg;
}

void Ship::setResourceImg(const QString &value)
{
    resourceImg = value;
}


