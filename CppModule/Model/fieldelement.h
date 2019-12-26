#ifndef FIELDELEMENT_H
#define FIELDELEMENT_H
#include "abstractgamefigure.h"
//*****
#include "../GameCore/emptycell.h"
//*****
#include <QObject>

class FieldElement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(AbstractGameFigure* figure READ figure WRITE setFigure NOTIFY figureChanged)
public:
    enum StateCellField{
        EMPTY = 0,
        CLOSE,
        BAN
    };
    Q_ENUM(StateCellField)

    FieldElement(AbstractGameFigure *figure = nullptr, QObject *parent = nullptr);
    int index() const;
    AbstractGameFigure *figure() const;
    void setFigure(AbstractGameFigure *figure);
    StateCellField getStateCell() const;
    void setStateCell(const StateCellField &value);

signals:
    void figureChanged(AbstractGameFigure* figure);

private:
    AbstractGameFigure *m_figure;
    static int countFieldElements;
    int m_index;
    StateCellField stateCell;
    QColor m_color;
};

#endif // FIELDELEMENT_H
