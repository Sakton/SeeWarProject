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
    void setSelfToField ( AbstractField *field ) override;
    void resetSelfToField() override;

    AbstractField *getField() const;
    void setField(AbstractField *field);
    void createFraming();

    //возврат к первоначальному состоянию
    void resetAll();

private:
    //можно ли поставить в клетку при условиях для установки
    bool emptyCellField (int index);
    void appointIndexesToForbiddenCell();
    void createForbiddemCellElements(int countpalubs);
    void searchIndexesToSetFromField();
    int row(int index); //индекс-строка
    int col(int index); //индекс-клонка
    int indexFromRowCol(int i_row, int i_col); //пересчет обратно
    void setIndexesHorisontally(int index, int len); //установить себя на поле горизонталь
    void setIndexesVertically(int index, int len); //установить себя на поле вертикаль

private:
    Ship *m_ship;
    std::vector<ForbiddenCell *> m_forbiddenCell;
    std::vector<int> m_forbiddenIndexes;
    AbstractField *m_field;
};

#endif // FRAMING_H
