#include "paluba.h"
#include <QDebug>

Paluba::Paluba(Ship *ship, int numberPalub, QObject *parent)
    : AbstractGameFigure(parent),
    m_ship{ship},
    m_numberPalub{numberPalub},
    m_color{"#fffc00"},
    m_resourceImg{},
    m_currentIndexOfModel{-1}
{

}

QColor Paluba::getColor()
{
    return m_color;
}

QString Paluba::getResourceImg()
{
    return m_resourceImg;
}

void Paluba::setSelfToField(AbstractField *field)
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
}

int Paluba::getNumberPalub() const
{
    return m_numberPalub;
}


