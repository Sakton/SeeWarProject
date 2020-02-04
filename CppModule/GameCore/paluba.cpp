#include "paluba.h"
#include <QDebug>

Paluba::Paluba(Ship *ship, int numberPalub, QObject *parent)
    : AbstractGameFigure(parent),
    m_ship{ship},
    m_numberPalub{numberPalub},
    m_color{"#fffc00"},
    m_resourceImg{"qrc:/QmlModule/qml/DefaultGui/img/Palybs/types1/types1_01.png"},
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


