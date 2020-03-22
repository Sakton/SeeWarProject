#ifndef FORBIDDENCELL_H
#define FORBIDDENCELL_H
#include "abstractgamefigure.h"
#include "../Figure/framing.h"
#include "../Figure/ship.h"

class Framing;
class Field;

class ForbiddenCell : public AbstractGameFigure
{
    Q_OBJECT
    Q_INTERFACES(AbstractGameFigure)
public:
    explicit ForbiddenCell( Framing *framing, QObject *parent = nullptr );

    // AbstractGameFigure interface
public:
    QColor getColor() override;
    QString getResourceImg() override;
    void setSelfToField( Field *field ) override;
    void resetSelfToField() override;
    int getRotateAngleFigure() override;

    void clear();
    int getSelfIndex() const;
    void setSelfIndex(int value);

private:
    int m_selfIndex;
    Framing *m_framing;
    QColor m_color;
    QString m_img;
};

#endif // FORBIDDENCELL_H
