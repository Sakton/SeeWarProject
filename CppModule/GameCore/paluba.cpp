#include "paluba.h"
#include <QDebug>

Paluba::Paluba(Ship *ship, int numberPalub, QObject *parent)
    : AbstractGameFigure(parent),
      m_ship{ship},
      m_numberPalub{numberPalub},
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
    auto elementField = field->getFieldElementCell(getCurrentIndexOfModel());
    elementField->setFigure(this);
}

void Paluba::resetSelfToField()
{
    if(m_field != nullptr) {
        auto elementField = m_field->getFieldElementCell(getCurrentIndexOfModel());
        elementField->resetToBaseState();
    }
}

int Paluba::getCurrentIndexOfModel() const
{
    return m_currentIndexOfModel;
}

void Paluba::setCurrentIndexOfModel(int currentIndexOfModel)
{
    m_currentIndexOfModel = currentIndexOfModel;
}

AbstractField *Paluba::getField() const
{
    return m_field;
}

void Paluba::setField(AbstractField *field)
{
    m_field = field;
}
