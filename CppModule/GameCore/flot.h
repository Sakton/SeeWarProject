#ifndef FLOT_H
#define FLOT_H
#include "vector"
#include "../Model/abstractfield.h"
#include "ship.h"
#include <QAbstractListModel>
#include "../Model/abstractgamefigure.h"

class Flot : public QAbstractListModel
{
    Q_OBJECT
public:
    enum FlotRole {
        CountPalubRole = Qt::UserRole,
        ImgRole,
        IndexRole,
        AngleRole
    };

    explicit Flot(AbstractField *field = nullptr, QObject *parent = nullptr);
    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
public:
    void setSelfToField(AbstractField *field);

public slots:
    //возврат к первоначальному состоянию
    void resetAll();

private:
    std::vector<Ship *> m_ships;
    AbstractField *m_field;
    QHash<int, QByteArray> m_flotRoles;
};

#endif // FLOT_H
