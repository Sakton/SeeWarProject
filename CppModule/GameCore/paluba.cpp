#include "paluba.h"

Paluba::Paluba(Ship *ship, int numberPalub/*, QString resourceImg*/):m_ship{ship}, m_numberPalub{numberPalub}/*, m_resourceImg{resourceImg}*/
{

}

void Paluba::testFunction()
{

}

QColor Paluba::getColor()
{
    return QColor();
}

QString Paluba::getResourceImg()
{
    return m_resourceImg;
}
