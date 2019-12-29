#include "ship.h"
#include <QDebug>
#include <iostream>

Ship::Ship(int countPalub, int angle, QObject *parent): AbstractGameFigure(parent), m_countLifePalub{countPalub}, m_countPalub{countPalub}, m_angle{angle}
{
    for(int i = 1; i <= countPalub; ++i )
        m_palubs.push_back(new Paluba(this, i, this));
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
    int k = (m_angle == 90) ? Config::NUM_ROW : 1;
    m_idexesPalubs.clear();
    for(int i = firstIndex, j = 0; i < firstIndex + m_countPalub * k, j < m_countPalub; i += k, ++j) {
        m_idexesPalubs.push_back(i);
        m_palubs.at(j)->setCurrentIndexOfModel(i);
    }
    for(auto x : m_idexesPalubs)
        qDebug() << x << " ";
}

int Ship::getAngle() const
{
    return m_angle;
}

void Ship::setAngle(int angle)
{
    m_angle = angle;
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


