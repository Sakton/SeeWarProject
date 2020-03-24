#include "DamageEnemyShipCell.h"

DamageEnemyShipCell::DamageEnemyShipCell(QObject *parent)
    : AbstractGameFigure(parent), testRes{"qrc:/QmlModule/qml/DefaultGui/img/cherep.gif"}
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
