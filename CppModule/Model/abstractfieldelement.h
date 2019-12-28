#ifndef ABSTRACTFIELDELEMENT_H
#define ABSTRACTFIELDELEMENT_H

#include <QObject>
#include "abstractgamefigure.h"

class AbstractGameFigure;

class AbstractFieldElement : public QObject
{
    Q_OBJECT
public:
    explicit AbstractFieldElement(QObject *parent = nullptr);
    virtual int index() const = 0;
    virtual void setFigure(AbstractGameFigure *figure) = 0;
    virtual AbstractGameFigure *figure() const = 0;
    virtual void resetToBaseState() = 0;
};

#endif // ABSTRACTFIELDELEMENT_H
