#include "fieldelement.h"
#include <QDebug>
#include "../Model/config.h"

int FieldElement::countFieldElements = 0;

FieldElement::FieldElement(AbstractGameFigure *baseSelfEmptyFigure, QObject *parent)
    : AbstractFieldElement(parent),
    m_figure{baseSelfEmptyFigure},
    m_BaseSelfEmptyFigure{new EmptyCell(this)},
    m_index{ (countFieldElements++) % 81 },
    m_color{}
{

}

int FieldElement::index() const
{
    return m_index;
}

void FieldElement::resetToBaseState()
{
    m_figure = nullptr;
    emit figureChanged(m_index);
}

int FieldElement::getRow()
{
    return m_index / Config::NUM_ROW;
}

int FieldElement::getCol()
{
    return m_index % Config::NUM_COL;
}

void FieldElement::sendSignalToChange(int index)
{
    emit figureChanged(index);
}


AbstractGameFigure *FieldElement::figure() const
{
    if(m_figure != nullptr)
        return m_figure;
    return m_BaseSelfEmptyFigure;
}

void FieldElement::setFigure(AbstractGameFigure *figure)
{
    if(m_figure) delete m_figure;
    m_figure = figure;
    emit figureChanged(m_index);
}
