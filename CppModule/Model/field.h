#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <QAbstractListModel>
#include "cell.h"

class Field : public QAbstractListModel
{
        Q_OBJECT
    //????? клетка и палуба одно и то-же???
    QHash<int, QByteArray> roleHash;
    std::vector<Cell> field;


private:
    void createFieldCells();

public:
    enum CellRoles {
        IndexElementRole = Qt::UserRole,
        EmptyRoles ,
        PalubaRole,
        BanRole
    };

    explicit Field(QObject *parent = nullptr);
    // QAbstractItemModel interface
    int rowCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QHash<int, QByteArray> roleNames() const override;
//    Qt::ItemFlags flags(const QModelIndex &index) const override;

    Q_INVOKABLE void shipsArragement(int startIndex, int count);
};

#endif // FIELD_H
