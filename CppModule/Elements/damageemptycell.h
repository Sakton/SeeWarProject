#ifndef DAMAGEEMPTYCELL_H
#define DAMAGEEMPTYCELL_H
#include "abstractgamefigure.h"

class DamageEmptyCell : public AbstractGameFigure
{
    Q_OBJECT
    Q_INTERFACES(AbstractGameFigure)
public:
    explicit DamageEmptyCell(int index, QObject *parent = nullptr);

    // AbstractGameFigure interface
    public:
    QColor getColor() override;
    QString getResourceImg() override;
    int getRotateAngleFigure() override;
    void setSelfToField( Field *field ) override;
    void resetSelfToField() override;

private:
    QColor m_color;
    QString m_resourceImg;
    int m_index;
};

#endif // DAMAGEEMPTYCELL_H
