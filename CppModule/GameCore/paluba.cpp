#include "paluba.h"

Paluba::Paluba(Ship *ship, int numberPalub, QObject *parent): QObject(parent), m_ship{ship}, m_numberPalub{numberPalub}, m_currentIndexOfModel{-1}
{

}

QColor Paluba::getColor()
{
    return m_color;
}

QString Paluba::getResourceImg()
{
    return m_resourceImg;
}

void Paluba::setSelfToField(AbstractField *field)
{
    //TODO ТУТ
}
