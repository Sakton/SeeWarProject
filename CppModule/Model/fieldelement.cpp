#include "fieldelement.h"
#include "config.h"
#include <QDebug>

int FieldElement::countFieldElements = 0;

FieldElement::FieldElement(AbstractGameFigure *baseSelfEmptyFigure, QObject *parent)
    : AbstractFieldElement(parent),
      m_figure{baseSelfEmptyFigure},
      m_BaseSelfEmptyFigure{new EmptyCell(this)},
      m_index{ countFieldElements++ }
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

AbstractGameFigure *FieldElement::figure() const
{
    if(m_figure != nullptr)
        return m_figure;
    return m_BaseSelfEmptyFigure;
}

void FieldElement::setFigure(AbstractGameFigure *figure)
{
    m_figure = figure;
    emit figureChanged(m_index);
}
