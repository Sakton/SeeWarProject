#include "field.h"
#include <QDebug>

BaseFlotInterface *Field::getFlot() const
{
    return flot;
}

void Field::setFlot(BaseFlotInterface *value)
{
    flot = value;
}

Field::Field(BaseFlotInterface *flt, QObject *parent):QAbstractListModel(parent),flot{flt}
{
    roleHash[CellRoles::EmptyRoles] = "empty";
    roleHash[CellRoles::PalubaRole] = "paluba";
    roleHash[CellRoles::BanRole] = "ban";
    roleHash[CellRoles::IndexElementRole] = "indexElement";
}

int Field::rowCount(const QModelIndex &) const
{
    return Config::SIZE_CELL;
}

QVariant Field::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || !flot)
        return {};
    switch (role) {
    case CellRoles::IndexElementRole:
        return QVariant(flot->getNumberElementFlot(index.row()));
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

//Qt::ItemFlags Field::flags(const QModelIndex &index) const
//{
////    if (!index.isValid())
////        return Qt::ItemIsEnabled;
////    return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
//    return Qt::NoItemFlags;
//}

void Field::shipsArragement(int startIndex, int count)
{
    qDebug() << "c++ startIndex = " << startIndex << " countPalubs = " << count;
}
