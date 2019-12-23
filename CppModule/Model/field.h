#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <QAbstractListModel>
#include "baseflotinterface.h"

//TODO может еще вынести интерфейс нашего поля ???

class Field : public QAbstractListModel
{
        Q_OBJECT
    QHash<int, QByteArray> roleHash;
    BaseFlotInterface *flot;

public:
    enum CellRoles {
        IndexElementRole = Qt::UserRole,
        EmptyRoles ,
        PalubaRole,
        BanRole
    };

    explicit Field(BaseFlotInterface *flt = nullptr, QObject *parent = nullptr);
    // QAbstractItemModel interface
    int rowCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QHash<int, QByteArray> roleNames() const override;
//    Qt::ItemFlags flags(const QModelIndex &index) const override;

    Q_INVOKABLE void shipsArragement(int startIndex, int count);
    BaseFlotInterface *getFlot() const;
    void setFlot(BaseFlotInterface *value);
};

#endif // FIELD_H
