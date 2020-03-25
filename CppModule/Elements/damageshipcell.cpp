#include "damageshipcell.h"
#include "../Model/config.h"


DamageShipCell::DamageShipCell(Paluba &paluba)
: Paluba(paluba)
{
    setResourceImg(Config::DAMAGE_PALUBA_QURL);
}

int DamageShipCell::getRotateAngleFigure()
{
    return 0;
}
