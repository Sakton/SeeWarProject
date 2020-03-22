#ifndef DAMAGESHIPCELL_H
#define DAMAGESHIPCELL_H
#include "abstractgamefigure.h"
#include "paluba.h"

class DamageShipCell : public Paluba
{
    Q_OBJECT
    Q_INTERFACES(AbstractGameFigure)
public:
    explicit DamageShipCell(Ship *ship, int numberPalub, QObject *parent = nullptr);

    // AbstractGameFigure interface
    public:
    QColor getColor() override;
    QString getResourceImg() override;
    int getRotateAngleFigure() override;
    void setSelfToField(AbstractField *field) override;
    void resetSelfToField() override;

private:
    QColor m_color;
    QString m_resourceImg;
    int m_index;
};

#endif // DAMAGESHIPCELL_H
