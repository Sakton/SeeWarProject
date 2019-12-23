#ifndef ABSTRACTFABRIQUEGAME_H
#define ABSTRACTFABRIQUEGAME_H
#include <QAbstractListModel>
#include "baseflotinterface.h"

//пока отставить
class AbstractFabriqueGame
{
public:
    virtual ~AbstractFabriqueGame();
    virtual BaseFlotInterface *createFlot() = 0;
    virtual QAbstractListModel *createField() = 0;
};

#endif // ABSTRACTFABRIQUEGAME_H
