#ifndef DAMAGEEMPTYCELL_H
#define DAMAGEEMPTYCELL_H
#include "emptycell.h"

class DamageEmptyCell : public EmptyCell
{
    Q_OBJECT
    Q_INTERFACES(AbstractGameFigure)
public:
    explicit DamageEmptyCell(QObject *parent = nullptr);
};

#endif // DAMAGEEMPTYCELL_H
