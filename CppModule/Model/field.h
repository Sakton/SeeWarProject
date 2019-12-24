#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <QAbstractListModel>
#include "fieldelement.h"

//TODO может еще вынести интерфейс нашего поля ???

class Field : public QAbstractListModel
{
        Q_OBJECT
public:
    enum CellRoles {
        IndexElementRole = Qt::UserRole,
        EmptyRoles,
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

    //MY
    Q_INVOKABLE void shipsArragement(int currentIndex, int countPalubs);

private:
    void initField();

private:
    QHash<int, QByteArray> roleHash;
    std::vector<FieldElement *> field;
};

#endif // FIELD_H
