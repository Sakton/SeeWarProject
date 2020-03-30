#ifndef FLOT_H
#define FLOT_H
#include <vector>
#include <QAbstractListModel>
//#include "../Field/abstractfield.h"
#include "../Figure/ship.h"
#include "../Elements/abstractgamefigure.h"

class Field;

class Flot : public QAbstractListModel
{
    Q_OBJECT
public:
    enum FlotRole {
        CountPalubRole = Qt::UserRole,
        ImgRole,
        IndexRole,
        AngleRole
    };

    explicit Flot(Field *field = nullptr, QObject *parent = nullptr);
    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
public:
    void setSelfToField(Field *field);
    void setSelfToFieldAuto(Field *field);

public slots:
    //возврат к первоначальному состоянию
    void resetAll();
    void autoArragement();
    void slotFlot_onDeadShip();
    void slotFlot_onDamageShip();

signals:
    //сигнал для блокировки ручного размещения в qml(коннект в Arragement.qml)
    void autoArragementMode();
    void signalFlot_DamageShip();
    void signalFlot_DeadShip();
    void signalFlot_FlotDead();

private:
    std::vector<Ship *> m_ships;
    Field *m_field;
    QHash<int, QByteArray> m_flotRoles;
    //*****
    static QColor colorsForTest[10];
    int m_countShips;
};

//Q_DECLARE_METATYPE(Flot)
//Q_DECLARE_OPAQUE_POINTER(Flot)

#endif // FLOT_H
