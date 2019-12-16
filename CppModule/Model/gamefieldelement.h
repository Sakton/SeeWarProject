#ifndef GAMEFIELDELEMENT_H
#define GAMEFIELDELEMENT_H
#include "interfacefieldmodel.h"

class GameFieldElement
{
public:
    virtual ~GameFieldElement();
    virtual void setSelfInToModel(InterfaceFieldModel *model) = 0;
};

#endif // GAMEFIELDELEMENT_H
