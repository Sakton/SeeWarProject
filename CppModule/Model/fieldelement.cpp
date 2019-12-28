#include "fieldelement.h"

int FieldElement::countFieldElements = 0;

FieldElement::FieldElement(AbstractGameFigure *baseSelfEmptyFigure, QObject *parent) : AbstractFieldElement(parent), m_figure{baseSelfEmptyFigure}, m_BaseSelfEmptyFigure{new EmptyCell(this)}, m_index{ countFieldElements++ }, stateCell{StateCellField::EMPTY}
{

}

int FieldElement::index() const
{
    return m_index;
}

void FieldElement::resetToBaseState()
{
    m_figure = nullptr;
}

AbstractGameFigure *FieldElement::figure() const
{
    if(!m_figure)
        return m_figure;
    return m_BaseSelfEmptyFigure;
}

void FieldElement::setFigure(AbstractGameFigure *figure)
{
    m_figure = figure;
}

FieldElement::StateCellField FieldElement::getStateCell() const
{
    return stateCell;
}

void FieldElement::setStateCell(const StateCellField &value)
{
    stateCell = value;
}
