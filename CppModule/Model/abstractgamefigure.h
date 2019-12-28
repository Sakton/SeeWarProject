#ifndef ABSTRACTGAMEFIGURE_H
#define ABSTRACTGAMEFIGURE_H
#include <QColor>
#include "abstractfield.h"

class AbstractField;

class AbstractGameFigure
{
public:
    virtual ~AbstractGameFigure();
    virtual QColor getColor() = 0;
    virtual QString getResourceImg() = 0;
    virtual void setSelfToField(AbstractField *field) = 0;
//    virtual void printSelfToField(AbstractField *field) = 0;
//    virtual int getCurreneIndex() = 0;
//    virtual AbstractGameFigure *getSelf() = 0;
};

#endif // ABSTRACTGAMEFIGURE_H
