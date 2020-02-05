#ifndef PALUBA_H
#define PALUBA_H
#include "../Model/abstractgamefigure.h"
#include "ship.h"
#include <QImage>

class Ship;

class Paluba : public AbstractGameFigure
{
    Q_OBJECT
    Q_INTERFACES(AbstractGameFigure)
public:
    explicit Paluba(Ship *ship, int numberPalub, QObject *parent = nullptr);
    // AbstractGameFigure interface
    QColor getColor() override;
    QString getResourceImg() override;
    void setSelfToField(AbstractField *field) override;
    void resetSelfToField() override;
    int getRotateAngleFigure() override;


    int getCurrentIndexOfModel() const;
    void setCurrentIndexOfModel(int currentIndexOfModel);
    void setResourceImg(const QString &image);


private:
    Ship *m_ship;
    int m_numberPalub;
    QColor m_color;
    QString m_resourceImg;
    int m_currentIndexOfModel;

};

#endif // PALUBA_H
