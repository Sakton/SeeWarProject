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
    Q_INTERFACES(AbstractFieldElement)
    Q_PROPERTY(AbstractGameFigure* figure READ figure WRITE setFigure NOTIFY figureChanged)

public:
    explicit FieldElement(AbstractGameFigure *baseSelfEmptyFigure, QObject *parent = nullptr);

    //AbstractFieldElement interface
    AbstractGameFigure *figure() const override;
    void setFigure(AbstractGameFigure *figure) override;
    int index() const override;
    void resetToBaseState() override;
    int getRow() override;
    int getCol() override;
    void sendSignalToChange(int index);

signals:
    void figureChanged(int index);

private:
    // Указатель на отображение фигуры
    // 2 отображен6ие для того чтобы возвращать указатель на обьект-фигуру
    // или свое отображение
    AbstractGameFigure *m_figure;
    //Свое родное отображение по умолчанию. (Состояние???)
    AbstractGameFigure *m_BaseSelfEmptyFigure;
    static int countFieldElements;
    int m_index;
    QColor m_color;
};

#endif // FIELDELEMENT_H
