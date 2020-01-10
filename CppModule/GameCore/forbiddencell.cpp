#include "forbiddencell.h"

ForbiddenCell::ForbiddenCell(Framing *framing, QObject *parent) : AbstractGameFigure(parent),
    m_framing{framing}
{

}

QColor ForbiddenCell::getColor()
{
    return m_color;
}

QString ForbiddenCell::getResourceImg()
{
    return m_img;
}

void ForbiddenCell::setSelfToField(AbstractField *field)
{
    Q_UNUSED(field)
}

void ForbiddenCell::resetSelfToField()
{

}
