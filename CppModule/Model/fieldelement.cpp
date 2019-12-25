#include "fieldelement.h"

int FieldElement::countFieldElements = 0;

FieldElement::FieldElement(AbstractGameFigure *figure, QObject *parent) : QObject(parent), m_figure{figure}, m_index{ countFieldElements++ }
{
    m_figure = new EmptyCell(this);
}

int FieldElement::index() const
{
    return m_index;
}

AbstractGameFigure *FieldElement::figure() const
{
    return m_figure;
}

void FieldElement::setFigure(AbstractGameFigure *figure)
{
    m_figure = figure;
}
