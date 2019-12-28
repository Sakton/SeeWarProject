#ifndef FIELDELEMENT_H
#define FIELDELEMENT_H
#include "abstractgamefigure.h"
#include "abstractfieldelement.h"
//*****
#include "../GameCore/emptycell.h"
//*****
#include <QObject>

class FieldElement : public AbstractFieldElement
{
    Q_OBJECT
    Q_PROPERTY(AbstractGameFigure* figure READ figure WRITE setFigure NOTIFY figureChanged)
public:
    //уже наверно не надо
    enum StateCellField{
        EMPTY = 0,
        CLOSE,
        BAN
    };
    Q_ENUM(StateCellField)

    explicit FieldElement(AbstractGameFigure *baseSelfEmptyFigure, QObject *parent = nullptr);
    StateCellField getStateCell() const;
    void setStateCell(const StateCellField &value);

    //AbstractFieldElement interface
    AbstractGameFigure *figure() const override;
    void setFigure(AbstractGameFigure *figure) override;
    int index() const override;
    void resetToBaseState() override;

signals:
    void figureChanged(AbstractGameFigure* figure);

private:
    //Указатель на отображение фигуры
    //2 отображен6ие для того чтобы возвращать указатель на обьект-фигуру
    // или свое отображение
    AbstractGameFigure *m_figure;
    //Свое родное отображение по умолчанию. (Состояние???)
    AbstractGameFigure *m_BaseSelfEmptyFigure;
    static int countFieldElements;
    int m_index;
    StateCellField stateCell;
    QColor m_color;
};

#endif // FIELDELEMENT_H
