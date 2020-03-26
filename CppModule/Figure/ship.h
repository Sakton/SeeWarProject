#ifndef SHIP_H
#define SHIP_H
#include <vector>
#include "../Elements/paluba.h"
#include "../Model/config.h"
#include "framing.h"

class DamageShipCell;
class Paluba;
class Framing;
class Field;

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
    void setSelfToField( Field *field ) override;
    void resetSelfToField() override;
    int getRotateAngleFigure() override;
    Framing *getFraming() const;


    Field *getField() const;
    void setField( Field *field );

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
    int m_countLifePalub; //хранит количество живых палуб
 //   QString resourceImg;
    int m_countPalub; //общее количество палуб
    int m_angle; //угол (горизонталь или вертикаль ???)
    std::vector<Paluba *> m_palubs; //указатели обьекты палуб
    //вспомогатеольная структура, индексы
    std::vector<int> m_indexesPalubs; //индексы палуб
    Field *m_field; //указатель на поле
    int oldIndex; //старый индекс до перестановки, для очищения ???
    int oldAngle; //старый угол до перестановки, для очищения ???
    Framing *m_framing; //указатель на оконтовку (рамку (запрещенные клетки))
    QColor m_color; //цвет для тестов
    QString m_resourceImg; //отображение всего кораблика в стеке расстановки (драгенддроп)
};

#endif // SHIP_H
