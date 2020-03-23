#include "damageshipcell.h"
#include "../Model/field.h"

DamageShipCell::DamageShipCell(Paluba &paluba)
: Paluba(paluba)
{
    setResourceImg("qrc:/QmlModule/qml/DefaultGui/img/cherep-v-krasnom-svete.gif");
}
