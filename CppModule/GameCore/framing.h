#ifndef FRAMING_H
#define FRAMING_H
#include "../Model/abstractgamefigure.h"
#include "forbiddencell.h"

class ForbiddenCell;
class Ship;

class Framing : public AbstractGameFigure
{
    Q_OBJECT
    Q_INTERFACES(AbstractGameFigure)
public:
    Framing( Ship *ship, QObject *parent = nullptr );

    // AbstractGameFigure interface
public:
    QColor getColor() override;
    QString getResourceImg() override;
    void setSelfToField(AbstractField *field) override;
    void resetSelfToField() override;

    AbstractField *getField() const;
    void setField(AbstractField *field);

    private:
    Ship *m_ship;
    std::vector<AbstractGameFigure *> m_forbiddenCell;
    std::vector<int> m_oldForbiddenIndexes;
    AbstractField *m_field;
};

#endif // FRAMING_H
