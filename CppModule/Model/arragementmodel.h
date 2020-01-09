#ifndef ARRAGEMENTMODEL_H
#define ARRAGEMENTMODEL_H
#include <QAbstractListModel>

#include <vector>
#include <set>

//ИЗ СТАРОЙ ВЕРСИИ

class ArragementModel : public QAbstractListModel {
    Q_OBJECT
    Q_ENUMS(IndexRoles)
public:
    enum IndexRoles {
        ColorIdTypeRole = Qt::UserRole,
        IndexElementRole,
        PointerObjectCell
        };
    enum ColorCell { NeytralColor = 0, ShipColor, DamageColor, CloseArea };
    ArragementModel(QObject *parent = nullptr);

    //MY
public:
    Q_INVOKABLE void setMyData(int index, const QVariant &value);

    // QAbstractItemModel interface
    //интерфейс для связи с пердставлением
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value,
        int role) override;
    virtual QHash<int, QByteArray> roleNames() const override;

public slots:
    void refreshModel();
    void slotChangedState(int, int, int, bool, bool);

private:
    void
    backlightShipsToSpaces(int index, int palub, bool gorizontal,
        ColorCell color = ColorCell::ShipColor);
    void
    backlightBoundingBox(int index, int palub, bool gorizontal,
        ColorCell color = ColorCell::CloseArea);
    void paintOverHorizontally(int index, int len, ColorCell color) noexcept;
    void paintOverVertically(int index, int len, ColorCell color) noexcept;
    int row(int index);
    int col(int index);
    int indexFromRowCol(int i_row, int i_col);
    bool inHorizontally(int index, int lenth);
    bool inVertically(int index, int lenth);
    bool isEmptyIndex(int index);

private:
    QHash<int, QByteArray> roleHash;
    std::vector<ColorCell> spaces;
};

#endif // ARRAGEMENTMODEL_H
