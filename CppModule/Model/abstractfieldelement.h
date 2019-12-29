#ifndef ABSTRACTFIELDELEMENT_H
#define ABSTRACTFIELDELEMENT_H

#include <QObject>
#include "abstractgamefigure.h"

class AbstractGameFigure;

class AbstractFieldElement : public QObject
{
    Q_OBJECT
//    Q_PROPERTY(AbstractGameFigure* figure READ figure WRITE setFigure NOTIFY figureChanged)
public:
    explicit AbstractFieldElement(QObject *parent = nullptr);
    virtual int index() const = 0;
    virtual void setFigure(AbstractGameFigure *figure) = 0;
    virtual AbstractGameFigure *figure() const = 0;
    virtual void resetToBaseState() = 0;
signals:
    void figureChanged(AbstractGameFigure* figure);

private:
    //AbstractGameFigure* m_figure;
};

Q_DECLARE_INTERFACE(AbstractFieldElement, "CppInterface_AbstractFieldElement")
//Q_DECLARE_OPAQUE_POINTER(AbstractFieldElement)

#endif // ABSTRACTFIELDELEMENT_H
