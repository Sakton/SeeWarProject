#include "field.h"
#include "config.h"
#include <QDebug>


Field::Field(QObject *parent):AbstractField(parent)
{
    initField();
    roleHash[CellRoles::IndexElementRole] = "indexElement";
    roleHash[CellRoles::ColorRole] = "colorElement";
    roleHash[CellRoles::ImageResourceRole] = "imageResourceCell";
//    roleHash[CellRoles::PointerObjectCellRole] = "pointerObjectCell";
}

int Field::rowCount(const QModelIndex &) const
{
    return Config::COUNT_CELL;
}

QVariant Field::data(const QModelIndex &index, int role) const
{
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
//        case CellRoles::PointerObjectCellRole: {
//            QVariant pointerToMyClass = QVariant::fromValue((element));
//            return pointerToMyClass;
//        }
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

void Field::figureChangedSlot(int index)
{
//    qDebug() << "dataChanged index  = " << index;
    auto ind = QAbstractItemModel::createIndex(index, 0);
    emit dataChanged(ind, ind);
}

void Field::initField()
{
    for(int i = 0; i < Config::COUNT_CELL; ++i) {
        auto el = new FieldElement(nullptr, this);
        connect(el, static_cast<void (FieldElement::*)(int)>(&FieldElement::figureChanged),
                this, static_cast<void(Field::*)(int)>(&Field::figureChangedSlot));
        m_field.push_back(el);
    }
}

