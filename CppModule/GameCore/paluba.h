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


    int getCurrentIndexOfModel() const;
    void setCurrentIndexOfModel(int currentIndexOfModel);
    void setImage(const QImage &image);

    AbstractField *getField() const;
    void setField(AbstractField *field);

private:
    Ship *m_ship;
    int m_numberPalub;
    QColor m_color{"yellow"};
    QString m_resourceImg{"qrc:/QmlModule/qml/DefaultGui/img/Palybs/types1/types1_01.png"};
    int m_currentIndexOfModel;
    AbstractField *m_field;
};

#endif // PALUBA_H
