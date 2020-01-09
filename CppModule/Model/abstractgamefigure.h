#ifndef ABSTRACTGAMEFIGURE_H
#define ABSTRACTGAMEFIGURE_H
#include <QColor>
#include "abstractfield.h"

class AbstractField;

class AbstractGameFigure : public QObject
{
public:
    AbstractGameFigure(QObject *parent = nullptr);
    virtual ~AbstractGameFigure();
    virtual QColor getColor() = 0;
    virtual QString getResourceImg() = 0;
    virtual void setSelfToField(AbstractField *field) = 0;
    virtual void resetSelfToField() = 0;
};

Q_DECLARE_OPAQUE_POINTER(AbstractGameFigure)
Q_DECLARE_INTERFACE(AbstractGameFigure, "CppInterface_AbstractGameFigure")

#endif // ABSTRACTGAMEFIGURE_H
