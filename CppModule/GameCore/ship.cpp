#include "ship.h"
#include <QDebug>
#include <iostream>
#include "emptycell.h"

const char* Ship::images[]{
    "qrc:/QmlModule/qml/DefaultGui/img/Palybs/types1/types1_01.png",
    "qrc:/QmlModule/qml/DefaultGui/img/Palybs/types1/types1_02.png",
    "qrc:/QmlModule/qml/DefaultGui/img/Palybs/types1/types1_03.png",
    "qrc:/QmlModule/qml/DefaultGui/img/Palybs/types1/types1_04.png"
};

Ship::Ship(int countPalub, int angle, QObject *parent)
    : AbstractGameFigure(parent),
    m_countLifePalub{countPalub},
    m_countPalub{countPalub},
    m_angle{angle},
    m_field{nullptr},
    oldIndex{-1},
    oldAngle{-1},
    m_framing{nullptr}
{
    for(int i = 1, j = 4 - countPalub; i <= countPalub; ++i, ++j ) {
        auto palub = new Paluba(this, i, this);
        if(countPalub != 1)
            palub->setResourceImg(QString(images[j]));
        else
            palub->setResourceImg(QString(images[0]));
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

const std::vector<int> Ship::getIndexesPalubs() const
{
    return m_indexesPalubs;
}

bool Ship::isPossiblePutInCell(int firstIndex)
{
    if(firstIndex > Config::COUNT_CELL - m_countPalub) {
        return false;
    }
    int k = (m_angle == 90) ? Config::NUM_COL : 1;
    bool res = true;
    for(int i = firstIndex, j = 0; j < m_countPalub; i += k, ++j) {
        //фигура на клетке - не пустая клетка
        bool p1 = ( dynamic_cast<EmptyCell*>( m_field->getFieldElementCell(i)->figure() ) == nullptr );
        //родитель установленной фигуры - не своя обводка (обводка другого корабля)
        bool p2 = ( m_field->getFieldElementCell(i)->figure()->parent() != m_framing );
        if( p2 && p1 ) {
            res = false;
            break;
        }
    }
    return res;
}

bool Ship::fillIndexes( int firstIndex )
{
    bool res = false;
    //Если палубы расставлены, то сбрасываем себя из занятых полей

    if( !m_palubs.empty() ) {
        resetSelfToField();
        m_framing->resetSelfToField();
    }

    qDebug() << "//***********";
    qDebug() << "firstIndex = " << firstIndex;
    for( auto m : m_palubs )
        qDebug() << m->getCurrentIndexOfModel();
    qDebug() << "//***********";


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
    } else {
        //сброс обрамления
        m_framing->resetSelfToField();
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
    m_framing->setField(field);
}

void Ship::resetAll()
{
    m_framing->resetAll();
    resetSelfToField();
    //???????
//    for(auto palub : m_palubs)
//        palub->setCurrentIndexOfModel(-1);
}

void Ship::createFraming()
{
    m_framing->createFraming();
}

void Ship::resetSelfToField()
{
    for(auto idx : m_indexesPalubs)
        m_field->getFieldElementCell(idx)->resetToBaseState();
    //???????
//    for(auto palub : m_palubs)
//        palub->setCurrentIndexOfModel(-1);
}

int Ship::getRotateAngleFigure()
{
    return getAngle();
}


