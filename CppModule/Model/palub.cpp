#include "palub.h"

Palub::Palub(int indx, QObject *parent) : ElementFieldGame(parent), m_stateLife{true}, m_idx{indx}
{

}

bool Palub::stateLife() const
{
    return m_stateLife;
}

int Palub::idx() const
{
    return m_idx;
}

void Palub::setStateLife()
{
    if (!m_stateLife)
        return;
    m_stateLife = false;
    emit palubIsDead();
}

void Palub::setIdx(int idx)
{
    m_idx = idx;
}

void Palub::getDamage(int index)
{
    if(index == m_idx)
        setStateLife();
}
