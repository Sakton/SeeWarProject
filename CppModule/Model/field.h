#ifndef FIELD_H
#define FIELD_H
#include <QAbstractListModel>
#include "interfacefieldmodel.h"
#include <vector>

class Field : public QAbstractListModel, public InterfaceFieldModel
{
    //????? клетка и палуба одно и то-же???
public:
    Field();
    // QAbstractItemModel interface
    int rowCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QHash<int, QByteArray> roleNames() const override;

    // InterfaceFieldModel interface
    void setElementInToModel(int index) override;
};

#endif // FIELD_H
