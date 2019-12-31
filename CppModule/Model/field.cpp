#include "field.h"
#include "config.h"
#include <QDebug>


Field::Field(QObject *parent):AbstractField(parent)
{
    initField();
    roleHash[CellRoles::IndexElementRole] = "indexElement";
    roleHash[CellRoles::ColorRole] = "colorElement";
    roleHash[CellRoles::ImageResourceRole] = "imageResourceCell";
    roleHash[CellRoles::PointerObjectCellRole] = "pointerObjectCell";
}

int Field::rowCount(const QModelIndex &) const
{
    return Config::COUNT_CELL;
}

QVariant Field::data(const QModelIndex &index, int role) const
{
    //TODO ПРОГОНЯТЬ ЧЕРЕЗ РОЛИ, ОБЬЕКТ НЕ ПЕРЕДАВАТЬ
    //ДЫРА - ПЕРЕДАЧА ОБЬЕКТА
    if(!index.isValid())
        return {};
    auto element = m_field.at(index.row());
    switch (role) {
    case CellRoles::IndexElementRole:
        return QVariant(element->index());
    case CellRoles::ColorRole:
        return element->figure()->getColor();
    case CellRoles::ImageResourceRole:
        return element->figure()->getResourceImg();
    case CellRoles::PointerObjectCellRole: {
        QVariant pointerToMyClass = QVariant::fromValue((element));
        return pointerToMyClass;
    }
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
    return m_field.at(index);
}

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
        m_field.push_back(new FieldElement(nullptr, this));
}

