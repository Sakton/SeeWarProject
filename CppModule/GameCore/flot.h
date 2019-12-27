#ifndef FLOT_H
#define FLOT_H
#include "vector"
#include "../Model/field.h"
#include "ship.h"
#include <QAbstractListModel>

class Flot : public QAbstractListModel
{
    Q_OBJECT
public:
    enum FlotRole {
        CountPalubRole = Qt::UserRole,
        ImgRole
    };

    explicit Flot(QAbstractListModel *field = nullptr, QObject *parent = nullptr);
    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    std::vector<Ship *> ships;
    QAbstractListModel *m_field;
    QHash<int, QByteArray> flotRoles;
};

#endif // FLOT_H
