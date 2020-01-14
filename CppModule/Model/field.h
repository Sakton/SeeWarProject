#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include "abstractfield.h"
#include "fieldelement.h"


class Field : public AbstractField
{
    Q_OBJECT
public:
    enum CellRoles {
        IndexElementRole = Qt::UserRole,
        ColorRole,
        ImageResourceRole,
        PointerObjectCellRole
    };

    explicit Field(QObject *parent = nullptr);
    // QAbstractItemModel interface
    int rowCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QHash<int, QByteArray> roleNames() const override;

    // AbstractField interface
    AbstractFieldElement *getFieldElementCell(int index) override;

    void initField();

public slots:
    void figureChangedSlot(int index);

private:
    QHash<int, QByteArray> roleHash;
    std::vector<AbstractFieldElement *> m_field;
    int m_state;
};

#endif // FIELD_H
