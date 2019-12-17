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
