#include "damageemptycell.h"

DamageEmptyCell::DamageEmptyCell(int index, QObject *parent)
    : AbstractGameFigure(parent),
    m_color{QColor("red")},
    m_resourceImg{"qrc:/QmlModule/qml/DefaultGui/img/krest.gif"},
    m_index{index}
{
}

QColor DamageEmptyCell::getColor()
{
    return m_color;
}

QString DamageEmptyCell::getResourceImg()
{
    return m_resourceImg;
}

int DamageEmptyCell::getRotateAngleFigure()
{
    return 0;
}

void DamageEmptyCell::setSelfToField(AbstractField *field)
{
    //field->getFieldElementCell(m_index);
    Q_UNUSED(field)
}

void DamageEmptyCell::resetSelfToField()
{

}
