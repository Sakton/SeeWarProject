#ifndef PALUBA_H
#define PALUBA_H
#include <QImage>
#include "abstractgamefigure.h"
#include "../Figure/ship.h"

class Ship;
class Field;



class Paluba : public AbstractGameFigure
{
    Q_OBJECT
    Q_INTERFACES(AbstractGameFigure)
    enum StatePalubs {
        DAMAG = 0, NO_DAMAG
    };
//    Q_PROPERTY(QColor color READ getColor NOTIFY getColorChanged)
    Q_PROPERTY(QString img READ getResourceImg WRITE setResourceImg NOTIFY imgChanged)

public:
    explicit Paluba(Ship *ship, int numberPalub, bool onePalub, QObject *parent = nullptr);
    // AbstractGameFigure interface
    QColor getColor() override;
    QString getResourceImg() override;
    void setSelfToField(Field *field) override;
    void resetSelfToField() override;
    int getRotateAngleFigure() override;


    int getCurrentIndexOfModel() const;
    void setCurrentIndexOfModel(int currentIndexOfModel);
    void setResourceImg(const QString &image);
    int getNumberPalub() const;
    void setColor(const QColor &color);
    void setStateDamage();

    Ship *getShip() const;

signals:
    void imgChanged(QString img);

    private:
    Ship *m_ship;
    int m_numberPalub;
    QColor m_color;
    QString m_resourceImg;
    int m_currentIndexOfModel;
    StatePalubs m_stateDamage;
};

#endif // PALUBA_H
