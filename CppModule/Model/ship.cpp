#include "ship.h"

Ship::Ship(int countPalubs, int startIndex, Location location, QObject *parent) : ElementFieldGame(parent), m_stateLife{true}, m_countLifePalub{countPalubs}
{
    for(int i = 0; i < countPalubs; ++i) {
        Palub *palub = new Palub(0, this);
        palubs.push_back(palub);
        connect(palub, static_cast<void(Palub::*)()>(&Palub::palubIsDead),
                this, [&](){ palubDamaged(); });
//        connect(palub, static_cast<void(Palub::*)()>(&Palub::palubIsDead),
//                this, static_cast<void(Ship::*)()>(&Ship::palubDamaged));
    }
}

void Ship::getDamage(int index)
{
    for(auto el : palubs)
        el->getDamage(index);
}

bool Ship::stateLife() const
{
    return m_stateLife;
}

int Ship::countLifePalub() const
{
    return m_countLifePalub;
}

void Ship::setCountLifePalub(int countLifePalub)
{
    if (m_countLifePalub == countLifePalub)
        return;
    m_countLifePalub = countLifePalub;
    emit countLifePalubChanged(m_countLifePalub);
}

void Ship::palubDamaged()
{

}
