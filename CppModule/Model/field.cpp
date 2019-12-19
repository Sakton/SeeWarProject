#include "field.h"
#include <QDebug>

void Field::datatest()
{
    testNabor = std::vector<int>(81);
    for(int i = 0; i < 81; ++i)
        testNabor.at(i) = i;

    int ttt = 0;
}

Field::Field(QObject *parent)
{
    qDebug() << "createField";
    datatest();

    roleHash[CellRoles::EmptyRoles] = "Empty";
    roleHash[CellRoles::PalubaRole] = "Paluba";
    roleHash[CellRoles::BanRole] = "Ban";
    roleHash[CellRoles::ObjectRole] = "ObjectFieldCell";
}

int Field::rowCount(const QModelIndex &) const
{
    //TODO !!!
    return 81;
}

QVariant Field::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return {};
    switch (role) {
    case CellRoles::ObjectRole:
        try {
    } catch (std::exception) {
            qDebug() << "OUT OF RANGE";
        }
    }
    return {};
}

bool Field::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return true;
}

QHash<int, QByteArray> Field::roleNames() const
{
    return roleHash;
}
