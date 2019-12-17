#ifndef PALUBA_H
#define PALUBA_H
#include "fieldelement.h"

class Paluba : public FieldElement
{
    bool isDead;
public:
    Paluba(int ind = 0, bool dd = false);
    bool getIsDead() const;
    void setIsDead(bool value);
};

#endif // PALUBA_H
