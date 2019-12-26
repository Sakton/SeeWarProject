#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <QAbstractListModel>
#include "fieldelement.h"

class Field : public QAbstractListModel
{
        Q_OBJECT
        Q_PROPERTY(int state READ state WRITE setState NOTIFY stateChanged)
public:
    enum CellRoles {
        IndexElementRole = Qt::UserRole,
        StateCellRole,
        PointerObjectCell
    };


    explicit Field(QObject *parent = nullptr);
    // QAbstractItemModel interface
    int rowCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QHash<int, QByteArray> roleNames() const override;
//    Qt::ItemFlags flags(const QModelIndex &index) const override;

    //MY
    Q_INVOKABLE void shipsArragement(int currentIndex, int countPalubs, int position);
    int state() const;

public slots:
    void setState(int state);
signals:
    void stateChanged(int state);

private:
    void initField();

private:
    QHash<int, QByteArray> roleHash;
    std::vector<FieldElement *> field;
    std::vector<std::pair<QColor, int>> aragementTemplate;
    int m_state;
};

#endif // FIELD_H
