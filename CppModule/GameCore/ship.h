#ifndef SHIP_H
#define SHIP_H
#include "paluba.h"
#include "../Model/config.h"
#include <vector>
#include "../Model/abstractfield.h"

class Paluba;

class Ship :/*public QObject, */public AbstractGameFigure
{
    Q_OBJECT
    Q_INTERFACES(AbstractGameFigure)
public:
    explicit Ship(int countPalub, int angle, QObject *parent = nullptr);
    int getCountPalub() const;
    void setResourceImg(const QString &value);
    //***???
    void fillIndexes(int firstIndex/*, int angleRotate*/);
    int getAngle() const;
    void setAngle(int angle);

    // AbstractGameFigure interface
public:
    QColor getColor() override;
    QString getResourceImg() override;
    void setSelfToField(AbstractField *field) override;

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
    std::vector<int> m_idexesPalubs;

};

#endif // SHIP_H
