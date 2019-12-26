#include "ship.h"

Ship::Ship(int countPalubs, int angle):m_countLifePalub{countPalubs}, m_angle{angle}
{
    for(int i = 1; i <= countPalubs; ++i )
        m_ship.push_back(new Paluba(this, i));
}

