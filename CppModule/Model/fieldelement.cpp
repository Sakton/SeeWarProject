#include "fieldelement.h"
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
    qDebug() << "reset FieldElement Index" << m_index;
    emit figureChanged(m_index);
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
