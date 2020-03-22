#include "damageshipcell.h"
#include "../Model/field.h"

DamageShipCell::DamageShipCell(Ship *ship, int numberPalub, QObject *parent)
    : Paluba(ship, numberPalub, parent),
    m_color{"red"},
    m_resourceImg{"qrc:/QmlModule/qml/DefaultGui/img/cherep-v-krasnom-svete.gif"},
    m_index{numberPalub}
{
}

QColor DamageShipCell::getColor()
{
    return m_resourceImg;
}

QString DamageShipCell::getResourceImg()
{
    return m_resourceImg;
}

int DamageShipCell::getRotateAngleFigure()
{
    return 90;
}

void DamageShipCell::setSelfToField(Field *field)
{
    field->getFieldElementCell(getCurrentIndexOfModel())->setFigure(this);
}

void DamageShipCell::resetSelfToField()
{

}
