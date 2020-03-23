#ifndef DAMAGESHIPCELL_H
#define DAMAGESHIPCELL_H
#include "abstractgamefigure.h"
#include "paluba.h"

class DamageShipCell : public Paluba
{
    Q_OBJECT
    Q_INTERFACES(AbstractGameFigure)
public:
    explicit DamageShipCell(Paluba & paluba);
};

#endif // DAMAGESHIPCELL_H
