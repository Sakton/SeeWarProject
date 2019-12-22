#include "palub.h"

Palub::Palub(int indx, QObject *parent) : ElementFieldGame(parent), m_stateLife{true}, m_idx{indx}
{

}

int Palub::idx() const
{
    return m_idx;
}

void Palub::setIdx(int idx)
{
    m_idx = idx;
}

void Palub::getDamage(int index)
{
    //if(index == m_idx)

}
