#include "paluba.h"
#include <QDebug>
#include "../Model/field.h"

const char* images[]{
    "qrc:/QmlModule/qml/DefaultGui/img/Palybs/types1/types1_01.png",
    "qrc:/QmlModule/qml/DefaultGui/img/Palybs/types1/types1_02.png",
    "qrc:/QmlModule/qml/DefaultGui/img/Palybs/types1/types1_03.png",
    "qrc:/QmlModule/qml/DefaultGui/img/Palybs/types1/types1_04.png"
};

Paluba::Paluba(Ship *ship, int numberPalub, bool onePalub, QObject *parent)
    : AbstractGameFigure(parent),
    m_ship{ship},
    m_numberPalub{numberPalub},
    m_color{"#fffc00"},
    m_resourceImg{},
    m_currentIndexOfModel{-1},
    m_stateDamage{StatePalubs::NO_DAMAG}
{
    if(onePalub)
        m_resourceImg = images[3];
    qDebug() << numberPalub;
    m_resourceImg = images[numberPalub];
}

Paluba::Paluba(const Paluba &pl)
{
    m_ship = pl.m_ship;
    m_numberPalub = pl.m_numberPalub;
    m_color = pl.m_color;
    m_resourceImg = pl.m_resourceImg;
    m_currentIndexOfModel = pl.m_currentIndexOfModel;
    m_stateDamage = pl.m_stateDamage;
}


QColor Paluba::getColor()
{
    return m_color;
}

QString Paluba::getResourceImg()
{
    return m_resourceImg;
}

void Paluba::setSelfToField(Field *field)
{
    field->getFieldElementCell(getCurrentIndexOfModel())->setFigure(this);
}

void Paluba::resetSelfToField()
{

}

int Paluba::getRotateAngleFigure()
{
    return m_ship->getRotateAngleFigure();
}

int Paluba::getCurrentIndexOfModel() const
{
    return m_currentIndexOfModel;
}

void Paluba::setCurrentIndexOfModel(int currentIndexOfModel)
{
    m_currentIndexOfModel = currentIndexOfModel;
}

void Paluba::setResourceImg(const QString &image)
{
    m_resourceImg = image;
    emit imgChanged(m_resourceImg);
}

int Paluba::getNumberPalub() const
{
    return m_numberPalub;
}

void Paluba::setColor(const QColor &color)
{
    m_color = color;
}

Ship *Paluba::getShip() const
{
    return m_ship;
}


