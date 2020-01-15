#include "framing.h"
#include <QDebug>
#include "../Model/config.h"
#include "emptycell.h"

Framing::Framing(Ship *ship, QObject *parent) : AbstractGameFigure(parent), m_ship{ship}, m_field{nullptr}
{
    createForbiddemCellElements(ship->getCountPalub());
}

QColor Framing::getColor()
{
    return {};
}

QString Framing::getResourceImg()
{
    return {};
}

void Framing::setSelfToField(AbstractField *field)
{
    for(auto el : m_forbiddenCell)
        el->setSelfToField (field);
}

void Framing::resetSelfToField()
{
    for( auto obj : m_forbiddenCell )
        obj->clear();
    for( int idx : m_forbiddenIndexes )
        if(idx >= 0) // !!!!!!!!!!!!!!!!!
            m_field->getFieldElementCell( idx )->resetToBaseState();
    m_forbiddenIndexes.clear();
}

AbstractField *Framing::getField() const
{
    return m_field;
}

void Framing::setField(AbstractField *field)
{
    m_field = field;
}

int Framing::row(int index)
{
    return (index / Config::NUM_ROW);
}

int Framing::col(int index)
{
    return (index % Config::NUM_COL);
}

int Framing::indexFromRowCol(int i_row, int i_col) {
    return (i_row * Config::NUM_ROW + i_col);
}

void Framing::setIndexesHorisontally(int index, int len)
{
    for (int i = index; i < index + len; ++i)
        m_forbiddenIndexes.push_back(i);
}

void Framing::setIndexesVertically(int index, int len)
{
    for (int i = index; i < index + len * Config::NUM_COL; i += Config::NUM_COL)
        m_forbiddenIndexes.push_back(i);
}

void Framing::createFraming()
{
    //если рамка была сброс
    if(!m_forbiddenIndexes.empty())
        resetSelfToField();
    //ищем новые индексы
    searchIndexesToSetFromField();
    //назначить индексы нужным клеткам
    appointIndexesToForbiddenCell();
    this->setSelfToField( m_field );
}

void Framing::resetAll()
{
    resetSelfToField();
    for(auto el : m_forbiddenIndexes)
        el = -1;
}

//можно ли поставить в клетку при условиях для установки
bool Framing::emptyCellField(int index)
{
    //TODO изменения тут
    if( index < 0 ) return false;
    auto t = m_field->getFieldElementCell( index )->figure();
    //Если фигура на клетке пустая клетка
    bool p1 = dynamic_cast<EmptyCell *>( t ) != nullptr;
    //Если родитель старой запрещенной клетки тот же
    bool p2 = (t->parent() == this);
    return ( p1 || p2 );
}

void Framing::appointIndexesToForbiddenCell()
{
    for( int i = 0; i < m_forbiddenIndexes.size(); ++i ) {
        if( emptyCellField( m_forbiddenIndexes.at( i ) ) )
            m_forbiddenCell.at( i )->setSelfIndex( m_forbiddenIndexes.at( i ) );
        else
            m_forbiddenIndexes.at( i ) = -1;
    }

//    QString s;
//    for(auto el : m_forbiddenIndexes) {
//        s.push_back(QString::number(el));
//        s.push_back(" ");
//    }
//    qDebug() << "end string = " << s;
}

void Framing::createForbiddemCellElements( int countpalubs )
{
    //Формирую всю обводку
    for( int i = 0; i < ( countpalubs * 2 + 6 ); ++i ) {
        m_forbiddenCell.push_back( new ForbiddenCell( this, this ) );
    }
}

void Framing::searchIndexesToSetFromField() {
    int row_line_start = row(m_ship->getIndexesPalubs().at(0));
    int col_line_start = col(m_ship->getIndexesPalubs().at(0));
    int row_line_end = -1;
    int col_line_end = -1;

    int top = -1;
    int bottom = -1;
    int left = -1;
    int right = -1;

    int i_topLeft = -1;
    int i_topRight = -1;
    int i_bottomLeft = -1;
    int i_bottomRight = -1;

    if (m_ship->getAngle() == 0) {
        row_line_end = row_line_start;
        col_line_end = col_line_start + m_ship->getCountPalub() - 1;
    } else {
        row_line_end = row_line_start + m_ship->getCountPalub() - 1;
        col_line_end = col_line_start;
    }

    top = (row_line_start - 1 >= 0) ? row_line_start - 1 : row_line_start;
    left = (col_line_start - 1 >= 0) ? col_line_start - 1 : col_line_start;
    right = (col_line_end + 1 < Config::NUM_COL) ? col_line_end + 1 : col_line_end;
    bottom =
        (row_line_end + 1 < Config::NUM_ROW) ? row_line_end + 1 : row_line_end;

    i_topLeft = indexFromRowCol(top, left);
    i_topRight = indexFromRowCol(top, right);
    i_bottomLeft = indexFromRowCol(bottom, left);
    i_bottomRight = indexFromRowCol(bottom, right);

    if( row_line_start > 0 )
        setIndexesHorisontally(i_topLeft, (i_topRight - i_topLeft + 1));
    if( row_line_end < Config::NUM_ROW - 1 )
        setIndexesHorisontally(i_bottomLeft, (i_topRight - i_topLeft + 1));
    if( col_line_start > 0 )
        setIndexesVertically(i_topLeft,
            (((i_bottomLeft - i_topLeft) / Config::NUM_COL) + 1));
    if( col_line_end < Config::NUM_COL - 1 )
        setIndexesVertically(i_topRight,
            (((i_bottomRight - i_topRight) / Config::NUM_COL) + 1));

    //удаление дубликатов индексов
    //не менять алгоритм установки setIndexesHorisontally и setIndexesVertically
    std::sort(m_forbiddenIndexes.begin(), m_forbiddenIndexes.end());
    auto pos = std::unique(m_forbiddenIndexes.begin(), m_forbiddenIndexes.end());
    m_forbiddenIndexes.erase(pos, m_forbiddenIndexes.end());

//    QString s;
//    for(auto el : m_forbiddenIndexes) {
//        s.push_back(QString::number(el));
//        s.push_back(" ");
//    }
//    qDebug() << s;
}
