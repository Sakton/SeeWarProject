#include "paluba.h"

Paluba::Paluba(int, bool)
{}

bool Paluba::getIsDead() const
{
    return isDead;
}

void Paluba::setIsDead(bool value)
{
    if(isDead != value && value)
        isDead = value;
}

int Paluba::getIndex() const
{
    return index;
}

void Paluba::setIndex(int value)
{
    index = value;
}
