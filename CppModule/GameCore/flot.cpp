#include "flot.h"
#include "../Model/config.h"
#include <QDebug>

Flot::Flot(QAbstractListModel *field, QObject *parent):QAbstractListModel(parent),  m_field{field}
{
    for(int i = 1; i <= 4; i++) {
        for(int j = i; j <= 4; ++j) {
            Ship *t = new Ship(i, 0);
            t->setResourceImg(Config::imgShips.at(i - 1));
            ships.push_back(t);
        }
    }
    flotRoles[FlotRole::CountPalubRole] = "countPalub";
    flotRoles[FlotRole::ImgRole] = "img";
}

int Flot::rowCount(const QModelIndex &parent) const
{
    return Config::COUNT_SHIPS;
    Q_UNUSED(parent)
}

QVariant Flot::data(const QModelIndex &index, int role) const
{
    qDebug() << "Запрос Flot::data";
    if(!index.isValid())
        return {};
    auto currentShip = ships.at(index.row());
    switch (role) {
    case FlotRole::CountPalubRole:
        return currentShip->getCountPalub();
    case FlotRole::ImgRole:
        return currentShip->getResourceImg();
    }
    return {};
}

QHash<int, QByteArray> Flot::roleNames() const
{
    return flotRoles;
}
