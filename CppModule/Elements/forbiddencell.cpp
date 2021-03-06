#include "forbiddencell.h"
#include <QDebug>
#include "../Model/field.h"

ForbiddenCell::ForbiddenCell(Framing *framing, QObject *parent) : AbstractGameFigure(parent),
    m_selfIndex{-1},
    m_framing{framing},
    m_color{"gray"},
    m_img{""}
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

void ForbiddenCell::setSelfToField(Field *field)
{
    if( m_selfIndex >= 0 )
        field->getFieldElementCell(m_selfIndex)->setFigure(this);
}

void ForbiddenCell::resetSelfToField()
{
}

int ForbiddenCell::getRotateAngleFigure()
{
    return m_framing->getRotateAngleFigure();
}

void ForbiddenCell::clear()
{
    m_selfIndex = -1;
}

int ForbiddenCell::getSelfIndex() const
{
    return m_selfIndex;
}

void ForbiddenCell::setSelfIndex(int value)
{
    m_selfIndex = value;
}
