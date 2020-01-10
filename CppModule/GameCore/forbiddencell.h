#ifndef FORBIDDENCELL_H
#define FORBIDDENCELL_H
#include "../Model/abstractgamefigure.h"
#include "framing.h"
#include "ship.h"

class Framing;

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
    void setSelfToField( AbstractField *field ) override;
    void resetSelfToField() override;

private:
    int selfIndex;
    Framing *m_framing;
    QColor m_color{"gray"};
    QString m_img{""};
};

#endif // FORBIDDENCELL_H
