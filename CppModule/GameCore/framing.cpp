#include "framing.h"

Framing::Framing(Ship *ship, QObject *parent) : AbstractGameFigure(parent), m_ship{ship}, m_field{nullptr}
{

}

QColor Framing::getColor()
{
    return {};
}

QString Framing::getResourceImg()
{
    return {};
}

void Framing::setSelfToField(AbstractField *field)
{
    m_field = field;
    for(auto el : m_forbiddenCell)
        el->setSelfToField(field);
}

void Framing::resetSelfToField()
{
    for(int idx : m_oldForbiddenIndexes)
        m_field->getFieldElementCell(idx)->resetToBaseState();

}

AbstractField *Framing::getField() const
{
    return m_field;
}

void Framing::setField(AbstractField *field)
{
    m_field = field;
}
