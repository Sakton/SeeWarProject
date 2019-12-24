#ifndef FIELDELEMENT_H
#define FIELDELEMENT_H
#include "abstractgamefigure.h"
#include <QObject>

class FieldElement : public QObject
{
    Q_OBJECT
public:
    FieldElement(AbstractGameFigure *figure = nullptr, QObject *parent = nullptr);
    int index() const;
    AbstractGameFigure *figure() const;
    void setFigure(AbstractGameFigure *figure);

private:
    AbstractGameFigure *m_figure;
    static int countFieldElements;
    int m_index;
};

#endif // FIELDELEMENT_H
