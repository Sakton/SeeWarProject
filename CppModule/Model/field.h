#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <QAbstractListModel>

class Field : public QAbstractListModel
{
    //????? клетка и палуба одно и то-же???
    QHash<int, QByteArray> roleHash;
    std::vector<int> testNabor;

    void datatest();

public:
    enum CellRoles {
        ObjectRole = Qt::UserRole,
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
};

#endif // FIELD_H
