#ifndef SHIP_H
#define SHIP_H
#include <vector>
#include "../Elements/paluba.h"
#include "../Model/config.h"
#include "../Field/abstractfield.h"
#include "framing.h"

class DamageShipCell;
class Paluba;
class Framing;

class Ship : public AbstractGameFigure
{
    Q_OBJECT
    Q_INTERFACES(AbstractGameFigure)
public:
    explicit Ship( int countPalub, int angle, QObject *parent = nullptr );
    int getCountPalub() const;
    void setResourceImg( const QString &value );
    int getAngle() const;
    void setAngle( int angle );
    const std::vector<int> getIndexesPalubs() const;
    //главный метод размещения
    bool fillIndexes(int firstIndex);
    void setColor(const QColor &color);
    //дамаг
    void damage();


    // AbstractGameFigure interface
public:
    QColor getColor() override;
    QString getResourceImg() override;
    void setSelfToField( AbstractField *field ) override;
    void resetSelfToField() override;
    int getRotateAngleFigure() override;
    Framing *getFraming() const;


    AbstractField *getField() const;
    void setField( AbstractField *field );

    //возврат к первоначальному состоянию
    void resetAll();

    //создает объект обрамления запрещенными клетками для запрета расположения других кораблей вплотную
    void createFraming();

    private:
    //кораблик интересуется у поля можно ли ему занять эти клетки
    bool isPossiblePutInCell(int firstIndex);
    //кораблик сам проверяет себя влезет ли он в размещение по указанному первому индексу
    bool controlVmestimostiInField(int firstIndex);

signals:
    void deadShip();
    void damageShip();

private:
    static const char* images[];
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
    Framing *m_framing;
    QColor m_color;
};

#endif // SHIP_H
