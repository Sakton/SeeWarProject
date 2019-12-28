#include "field.h"
#include "config.h"
#include <QDebug>


Field::Field(QObject *parent):AbstractField(parent)
{
    initField();
    roleHash[CellRoles::IndexElementRole] = "indexElement";
    roleHash[CellRoles::PointerObjectCell] = "pointerObjectCell";
    roleHash[CellRoles::StateCellRole] = "stateCell";
}

int Field::rowCount(const QModelIndex &) const
{
    return Config::COUNT_CELL;
}

QVariant Field::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return {};
    auto element = field.at(index.row());
    switch (role) {
    case CellRoles::IndexElementRole:
        return QVariant(element->index());
//    case CellRoles::StateCellRole:
//        return static_cast<int>(element->getStateCell());
    case CellRoles::PointerObjectCell:
        QVariant pointerToMyClass = QVariant::fromValue(element);
        return pointerToMyClass;
    }
    return {};
}

bool Field::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return false;
    emit dataChanged(index, index);
    return true;
}

QHash<int, QByteArray> Field::roleNames() const
{
    return roleHash;
}

AbstractFieldElement *Field::getFieldElementCell(int index)
{
    return field.at(index);
}

//void Field::setFigureOnField(AbstractGameFigure *element)
//{

//}

void Field::shipsArragement(int currentIndex, int countPalubs, int position)
{
    qDebug() << "currentIndex = " << currentIndex << " countPalubs " << countPalubs << " angle = " << position;
}

int Field::state() const
{
    return m_state;
}

void Field::setState(int state)
{
    qDebug() << "state Field = " << state;
    if (m_state == state)
        return;
    m_state = state;
    emit stateChanged(m_state);
}

void Field::initField()
{
    for(int i = 0; i < Config::COUNT_CELL; ++i)
        field.push_back(new FieldElement(nullptr, this));
}

