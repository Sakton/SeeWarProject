#ifndef FIELD_H
#define FIELD_H
#include <vector>
//#include "../Field/abstractfield.h"
#include <QAbstractListModel>
#include "../Field/fieldelement.h"


class Field : public QAbstractListModel
{
    Q_OBJECT
public:
    enum CellRoles {
        IndexElementRole = Qt::UserRole,
        ColorRole,
        ImageResourceRole,
        AngleRotationFigure
    };

    explicit Field(QObject *parent = nullptr);
    // QAbstractListModel interface
    int rowCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QHash<int, QByteArray> roleNames() const override;

    AbstractFieldElement *getFieldElementCell(int index);
    void initField();

public slots:
    void figureChangedSlot(int index);

private:
    QHash<int, QByteArray> roleHash;
    std::vector<FieldElement *> m_field;
    int m_state;
};

//Q_DECLARE_METATYPE(Field)
Q_DECLARE_OPAQUE_POINTER(Field*)

#endif // FIELD_H
