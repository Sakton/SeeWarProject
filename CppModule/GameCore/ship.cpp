#include "ship.h"
#include <QDebug>
#include <iostream>

Ship::Ship(int countPalub, int angle, QObject *parent)
    : AbstractGameFigure(parent),
      m_countLifePalub{countPalub},
      m_countPalub{countPalub},
      m_angle{angle},
      oldIndex{-1},
      oldAngle{-1}
{
    for(int i = 1; i <= countPalub; ++i ) {
        auto el = new Paluba(this, i, this);
        el->setField(m_field);
        m_palubs.push_back(el);
    }
}

int Ship::getCountPalub() const
{
    return m_countPalub;
}

void Ship::setResourceImg(const QString &value)
{
    resourceImg = value;
}

void Ship::fillIndexes(int firstIndex)
{
    if(!m_palubs.empty()) {
        qDebug() << "!m_palubs.empty()";
        resetSelfToField();
    }
    int k = (m_angle == 90) ? Config::NUM_COL : 1;
    m_indexesPalubs.clear();
    for(int i = firstIndex, j = 0; (firstIndex + (m_countPalub - 1) * k < Config::COUNT_CELL) && (i <= firstIndex + (m_countPalub - 1) * k) && j < m_countPalub; i += k, ++j) {
        m_indexesPalubs.push_back(i);
        m_palubs.at(j)->setCurrentIndexOfModel(i);
    }
    setSelfToField(m_field);
}

int Ship::getAngle() const
{
    return m_angle;
}

void Ship::setAngle(int angle)
{
    m_angle = angle;
    fillIndexes(m_indexesPalubs.at(0));
}

QColor Ship::getColor()
{
    return {};
}

QString Ship::getResourceImg()
{
    return resourceImg;
}

void Ship::setSelfToField(AbstractField *field)
{
    for(auto palub : m_palubs)
        palub->setSelfToField(field);
}

AbstractField *Ship::getField() const
{
    return m_field;
}

void Ship::setField(AbstractField *field)
{
    m_field = field;
}

void Ship::resetSelfToField()
{
    for(auto idx : m_indexesPalubs) {
        auto elementField = m_field->getFieldElementCell(idx);
        elementField->resetToBaseState();
    }
}


