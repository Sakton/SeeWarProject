#include "field.h"
#include <QDebug>

void Field::datatest()
{
    for(int i = 0; i < 81; ++i)
        elements.push_back(FieldElement(i));

    for(int i = 0; i < 81; ++i) {
        if(i%2)
            cellElement.push_back(new FieldCellElement(i, this));
        else
            cellElement.push_back(new PalubaElement(i, i, this));
    }

//    elements.at(10)->setType(0);
//    elements.at(11).setType(1);
//    elements.at(12).setType(2);
//    elements.at(13).setType(3);
}

Field::Field(QObject *parent):InterfaceFieldModel(parent)
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
//    case CellRoles::IdexViewRole:
//        try {
//        qDebug() << "index.row() = " << index.row();
//        return QVariant(elements.at(index.row()).getIndex());
//    } catch (std::exception) {
//            qDebug() << "OUT OF RANGE";
//        }
//    }
    case CellRoles::ObjectRole:
    try {
        QVariant t = QVariant::fromValue(cellElement.at(index.row()));
//        return QVariant(cellElement.at(index.row()));
        return t;
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

void Field::setElementInToModel(int index)
{

}
