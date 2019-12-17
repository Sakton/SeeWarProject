#ifndef FIELD_H
#define FIELD_H
#include "interfacefieldmodel.h"
#include "fieldelement.h"
#include <vector>

class Field : public InterfaceFieldModel
{
    Q_OBJECT
    //????? клетка и палуба одно и то-же???
    QHash<int, QByteArray> roleHash;
    std::vector<FieldElement *> elements;
//    std::vector< std::pair<int, int> > elements;

    void datatest();

public:
    enum CellRoles {
        IdexViewRole = Qt::UserRole,
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

    // InterfaceFieldModel interface
    void setElementInToModel(int index) override;
};

#endif // FIELD_H
