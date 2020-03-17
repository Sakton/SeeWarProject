#include "damageshipcell.h"

DamageShipCell::DamageShipCell(int index, QObject *parent)
    : AbstractGameFigure(parent),
    m_color{"red"},
    m_resourceImg{"qrc:/QmlModule/qml/DefaultGui/img/cherep.gif"},
    m_index{index}
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
    return 0;
}

void DamageShipCell::setSelfToField(AbstractField *field)
{
    Q_UNUSED(field)
}

void DamageShipCell::resetSelfToField()
{

}
