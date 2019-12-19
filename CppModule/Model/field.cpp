#include "field.h"
#include <QDebug>

void Field::createFieldCells()
{
    field.resize(Config::SIZE_CELL);
}

Field::Field(QObject *parent)
{
    createFieldCells();

    roleHash[CellRoles::EmptyRoles] = "Empty";
    roleHash[CellRoles::PalubaRole] = "Paluba";
    roleHash[CellRoles::BanRole] = "Ban";
    roleHash[CellRoles::IndexElementRole] = "IndexElement";
}

int Field::rowCount(const QModelIndex &) const
{
    return Config::SIZE_CELL;
}

QVariant Field::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return {};
    switch (role) {
    case CellRoles::IndexElementRole:
        return QVariant(field.at(index.row()).getIndex());
    }

    return {};
}

bool Field::setData(const QModelIndex &index, const QVariant &value, int role)
{
    qDebug() << "CPP Field::setData -> index = " << index.row() << " value = " << value;
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
