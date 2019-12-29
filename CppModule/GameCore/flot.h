#ifndef FLOT_H
#define FLOT_H
#include "vector"
#include "../Model/field.h"
#include "ship.h"
#include <QAbstractListModel>
#include "../Model/abstractgamefigure.h"

class Flot : public QAbstractListModel/*, public AbstractGameFigure*/
{
    Q_OBJECT
//    Q_INTERFACES(AbstractGameFigure)
public:
    enum FlotRole {
        CountPalubRole = Qt::UserRole,
        ImgRole,
        IndexRole,
        AngleRole
    };

    explicit Flot(QAbstractListModel *field = nullptr, QObject *parent = nullptr);
    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    //некий общий интерфейс
//    void setSelfToField(Field *field);
    // AbstractGameFigure interface
public:
//    QColor getColor() override;
//    QString getResourceImg() override;
    void setSelfToField(AbstractField *field)/* override*/;

private:
    std::vector<Ship *> m_ships;
    QAbstractListModel *m_field;
    QHash<int, QByteArray> m_flotRoles;
};

#endif // FLOT_H
