#ifndef SHIP_H
#define SHIP_H
#include "paluba.h"
#include "../Model/config.h"
#include <vector>
#include "../Model/abstractfield.h"

class Paluba;

class Ship : public AbstractGameFigure
{
    Q_OBJECT
    Q_INTERFACES(AbstractGameFigure)
public:
    explicit Ship(int countPalub, int angle, QObject *parent = nullptr);
    int getCountPalub() const;
    void setResourceImg(const QString &value);
    int getAngle() const;
    void setAngle(int angle);
    //главный метод размещения
    void fillIndexes(int firstIndex);

    // AbstractGameFigure interface
public:
    QColor getColor() override;
    QString getResourceImg() override;
    void setSelfToField(AbstractField *field) override;
    void resetSelfToField() override;

    AbstractField *getField() const;
    void setField(AbstractField *field);

private:
    //кораблик интересуется у поля можно ли ему занять эти клетки
    bool isPossiblePutInCell(int firstIndex);
    //кораблик сам проверяет себя влезет ли он в размещение по указанному первому индексу
    bool controlVmestimostiInField(int firstIndex);

signals:
    void angleChanged();
    void indexesPalubsChanged();

private:
    int m_countLifePalub;
    QString resourceImg;
    int m_countPalub;
    int m_angle;
    std::vector<Paluba *> m_palubs;
    //вспомогатеольная структура, индексы
    std::vector<int> m_indexesPalubs;
    AbstractField *m_field;
    int oldIndex;
    int oldAngle;
};

#endif // SHIP_H
