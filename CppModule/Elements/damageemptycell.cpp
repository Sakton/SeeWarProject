#include "damageemptycell.h"
#include "../Model/config.h"

DamageEmptyCell::DamageEmptyCell(QObject *parent)
    : EmptyCell(parent)
{
    setImg(Config::MISS_QURL);
}
