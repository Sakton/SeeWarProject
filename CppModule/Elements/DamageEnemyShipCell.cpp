#include "DamageEnemyShipCell.h"
#include "../Model/config.h"

DamageEnemyShipCell::DamageEnemyShipCell(QObject *parent)
    : AbstractGameFigure(parent), testRes{Config::DAMAGE_PALUBA_QURL}
{
}

QColor DamageEnemyShipCell::getColor()
{
    return {};
}

QString DamageEnemyShipCell::getResourceImg()
{
    return testRes;
}

int DamageEnemyShipCell::getRotateAngleFigure()
{
    return 0;
}

void DamageEnemyShipCell::setSelfToField(Field *field)
{
    Q_UNUSED(field)
}

void DamageEnemyShipCell::resetSelfToField()
{

}
