#include "field.h"
#include "config.h"
#include <QDebug>


Field::Field(QObject *parent):QAbstractListModel(parent)
{
    initField();
    roleHash[CellRoles::IndexElementRole] = "indexElement";
    roleHash[CellRoles::PointerObjectCell] = "pointerObjectCell";
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
    case CellRoles::PointerObjectCell:
//        qDebug() << "Запрос PointerObjectCell";
        QVariant pointerToMyClass = QVariant::fromValue(element);
        return pointerToMyClass;
    }
    return {};
}

bool Field::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return false;
    qDebug() << "CPP Field::setData -> index = " << index.row() << " value = " << value;
//    field.at(index.row()).setIndex(value.toInt());
    emit dataChanged(index, index);
    return true;
}

QHash<int, QByteArray> Field::roleNames() const
{
    return roleHash;
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
        field.push_back(new FieldElement(nullptr, this));
}

//Qt::ItemFlags Field::flags(const QModelIndex &index) const
//{
////    if (!index.isValid())
////        return Qt::ItemIsEnabled;
////    return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
//    return Qt::NoItemFlags;
//}

