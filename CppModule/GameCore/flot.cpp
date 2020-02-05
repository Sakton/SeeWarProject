#include "flot.h"
#include "../Model/config.h"
#include <QDebug>
#include <QRandomGenerator>

Flot::Flot(AbstractField *field, QObject *parent):QAbstractListModel(parent), m_field{field}
{
    for(int i = 1; i <= 4; i++) {
        for(int j = i; j <= 4; ++j) {
            Ship *t = new Ship(i, 0, this);
            t->setResourceImg(Config::imgShips.at(i - 1));
            t->setField(field);
            m_ships.push_back(t);
        }
    }
    m_flotRoles[FlotRole::CountPalubRole] = "countPalub";
    m_flotRoles[FlotRole::ImgRole] = "img";
    m_flotRoles[FlotRole::IndexRole] = "currentThisShipFirstIndex";
    m_flotRoles[FlotRole::AngleRole] = "currentThisShipAngle";
}

int Flot::rowCount(const QModelIndex &parent) const
{
    return Config::COUNT_SHIPS;
    Q_UNUSED(parent)
}

QVariant Flot::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return {};
    auto currentShip = m_ships.at(index.row());
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
    return m_flotRoles;
}

bool Flot::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return false;
    auto elem = m_ships.at(index.row());
    switch (role) {
    case FlotRole::IndexRole: {
        int index = value.toInt();
        elem->fillIndexes(index);
        return true;
    }
    case FlotRole::AngleRole:
        elem->setAngle(value.toInt());
        return true;
    }
    return false;
}

void Flot::setSelfToField(AbstractField *field)
{
    Q_UNUSED(field)
}

void Flot::setSelfToFieldAuto(AbstractField *field)
{
    Q_UNUSED(field)
}

void Flot::resetAll()
{
    for(auto el : m_ships)
        el->resetAll();
}

void Flot::autoArragement()
{
//    resetAll();
    //std::vector<int> probes(81, 0);
    QVector<quint32> vector;
    QRandomGenerator gen;
    vector.resize(81);
    gen.fillRange(vector.data(), vector.size());
    for(auto a : vector)
        qDebug() << a % 81;
    //    QRandomGenerator *random = new QRandomGenerator;
//    for(int i = Config::COUNT_SHIPS - 1; i >= 0; --i) {
//        bool res = false;
//        do {
//            auto ind = QRandomGenerator::global()->generate() % 81;
//            if(1 == probes[ind]) continue;
//            else {
//                res = m_ships[i]->fillIndexes(ind);
//                if(!res) {
//                    m_ships[i]->setAngle(90);
//                    res = m_ships[i]->fillIndexes(ind);
//                }
//                probes[ind] = 1;
//            }
//        } while (!res);
//    }
    //delete random;
}

