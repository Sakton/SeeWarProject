#include "ship.h"
#include <QDebug>
#include <iostream>
#include "../Elements/emptycell.h"
#include "../Elements/damageshipcell.h"
#include "../Field/fieldelement.h"
#include "../Elements/damageshipcell.h"
#include "../Model/field.h"


Ship::Ship(int countPalub, int angle, QObject *parent)
    : AbstractGameFigure(parent),
    m_countLifePalub{countPalub},
    m_countPalub{countPalub},
    m_angle{angle},
    m_field{nullptr},
    oldIndex{-1},
    oldAngle{-1},
    m_framing{nullptr},
    m_color{"#00000000"}
{
    for(int i = 1, j = 4 - countPalub; i <= countPalub; ++i, ++j ) {
        auto palub = new Paluba(this, j, bool(j - 1), this);
        m_palubs.push_back(palub);
    }
    m_framing = new Framing(this, this);
}

int Ship::getCountPalub() const
{
    return m_countPalub;
}

void Ship::setResourceImg(const QString &value)
{
    resourceImg = value;
}

bool Ship::controlVmestimostiInField(int firstIndex)
{
    int row = firstIndex / Config::NUM_ROW;
    int col = firstIndex % Config::NUM_COL;
    int endRowCell = -1;
    int endColCell = -1;
    if(m_angle == 0) {
        endRowCell = row;
        endColCell = ( col + m_countPalub - 1 );
    } else {
        endRowCell = ( row + m_countPalub - 1 );
        endColCell = col;
    }
    return (endRowCell < Config::NUM_ROW && endColCell < Config::NUM_COL);
}

void Ship::setColor(const QColor &color)
{
    m_color = color;
    for(auto el : m_palubs)
        el->setColor(m_color);
}

void Ship::damage()
{
    //FIXME деЛАть ТуТ
    --m_countPalub;
    emit damageShip();
    if(!m_countPalub)
        emit deadShip();
}

Framing *Ship::getFraming() const
{
    return m_framing;
}

const std::vector<int> Ship::getIndexesPalubs() const
{
    return m_indexesPalubs;
}


bool Ship::isPossiblePutInCell(int firstIndex)
{
    if(firstIndex > Config::COUNT_CELL - m_countPalub) return false;
    int k = (m_angle == 90) ? Config::NUM_COL : 1;
    for(int i = firstIndex, j = 0; j < m_countPalub; i += k, ++j) {
        //фигура на клетке - не пустая клетка
        bool p1 = ( dynamic_cast<EmptyCell*>( m_field->getFieldElementCell(i)->figure() ) == nullptr );
        //родитель установленной фигуры - не своя обводка (обводка другого корабля)
        bool p2 = ( m_field->getFieldElementCell(i)->figure()->parent() != m_framing );
        if( p2 && p1 ) return false;
    }
    return true;
}

bool Ship::fillIndexes( int firstIndex )
{
    bool res = false;
    //Если палубы расставлены, то сбрасываем себя из занятых полей

    if( !m_palubs.empty() ) {
        resetSelfToField();
        m_framing->resetSelfToField();
    }

    //если клетки вмещаются
    if( controlVmestimostiInField( firstIndex ) ) {
        //и место свободно
        if( isPossiblePutInCell( firstIndex ) ) {
            m_indexesPalubs.clear();
            int k = ( m_angle == 90 ) ? Config::NUM_COL : 1;
            for(int i = firstIndex, j = 0; j < m_countPalub; i += k, ++j) {
                m_indexesPalubs.push_back(i);
                m_palubs.at( j )->setCurrentIndexOfModel( i );
            }
            createFraming();
            setSelfToField( m_field );
            res = true;
        }
    }
    return res;
}

int Ship::getAngle() const
{
    return m_angle;
}

void Ship::setAngle(int angle)
{
    m_angle = angle;
    if(!m_indexesPalubs.empty())
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

void Ship::setSelfToField(Field *field)
{
    for(auto palub : m_palubs)
        palub->setSelfToField(field);
}

Field *Ship::getField() const
{
    return m_field;
}

void Ship::setField(Field *field)
{
    m_field = field;
    m_framing->setField(field);
}

void Ship::resetAll()
{
    m_framing->resetAll();
    resetSelfToField();
    m_angle = 0;
}

void Ship::createFraming()
{
    m_framing->createFraming();
}

void Ship::resetSelfToField()
{
    for(auto idx : m_indexesPalubs)
        m_field->getFieldElementCell(idx)->resetToBaseState();
    for(auto palub : m_palubs)
        palub->setCurrentIndexOfModel(-1);
    m_indexesPalubs.clear();
}

int Ship::getRotateAngleFigure()
{
    return getAngle();
}


