#include "arragementmodel.h"
#include "config.h"
#include <QDebug>

//ИЗ СТАРОЙ ВЕРСИИ

ArragementModel::ArragementModel(QObject *parent) : QAbstractListModel(parent) {
    spaces = std::vector<ColorCell>(Config::COUNT_CELL, ColorCell::NeytralColor);
    roleHash[IndexRoles::ColorIdTypeRole] = "color";
    roleHash[IndexRoles::IndexElementRole] = "indexElement";
    roleHash[IndexRoles::PointerObjectCell] = "pointerObjectCell";
}

void ArragementModel::setMyData(int index, const QVariant& value)
{
    //    qDebug() << "PlayingField::setMyData";
    QModelIndex modIndex = QAbstractItemModel::createIndex(index, 0);
    setData(modIndex, value, IndexRoles::ColorIdTypeRole);
}

int ArragementModel::rowCount(const QModelIndex &parent) const {
    return static_cast<int>(spaces.size());
    Q_UNUSED(parent)
}

QVariant ArragementModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return {};
    switch (role) {
    case IndexRoles::ColorIdTypeRole:
        return spaces.at(static_cast<std::size_t>(index.row()));
    case IndexRoles::IndexElementRole:
        return index.row();
    case IndexRoles::PointerObjectCell:
        return this;
    }
    return {};
}

bool ArragementModel::setData(const QModelIndex &index, const QVariant &value,
    int role) {
    qDebug() << "PlayingField::setData index = " << index;
    if (!index.isValid())
        return false;
    switch (role) {
    case IndexRoles::ColorIdTypeRole: {
        //WARNING Касты!!!
        spaces.at(static_cast<std::size_t>(index.row())) = static_cast<ColorCell>(value.toInt());
        qDebug() << "PlayingField::setData";
        emit dataChanged(index, index, {role});
        return true;
    }
    default:
        return false;
    }
}

QHash<int, QByteArray> ArragementModel::roleNames() const
{
    return roleHash;
}


//
void ArragementModel::backlightShipsToSpaces(
    int index, int palub, bool gorizontal , ColorCell color) {
    if (gorizontal) {
        if (inHorizontally(index, palub))
            paintOverHorizontally(index, palub,
                color);
    } else {
        if (inVertically(index, palub))
            paintOverVertically(index, palub,
                color);
    }
}

void ArragementModel::backlightBoundingBox(int index, int palub, bool gorizontal, ColorCell color) {
    int row_line_start = row(index);
    int col_line_start = col(index);
    int row_line_end = -1;
    int col_line_end = -1;

    int top = -1;
    int bottom = -1;
    int left = -1;
    int right = -1;

    int i_topLeft = -1;
    int i_topRight = -1;
    int i_bottomLeft = -1;
    int i_bottomRight = -1;

    if (gorizontal) {
        row_line_end = row_line_start;
        col_line_end = col_line_start + palub - 1;
    } else {
        row_line_end = row_line_start + palub - 1;
        col_line_end = col_line_start;
    }

    top = (row_line_start - 1 >= 0) ? row_line_start - 1 : row_line_start;
    left = (col_line_start - 1 >= 0) ? col_line_start - 1 : col_line_start;
    right = (col_line_end + 1 < Config::NUM_COL) ? col_line_end + 1 : col_line_end;
    bottom =
        (row_line_end + 1 < Config::NUM_ROW) ? row_line_end + 1 : row_line_end;

    i_topLeft = indexFromRowCol(top, left);
    i_topRight = indexFromRowCol(top, right);
    i_bottomLeft = indexFromRowCol(bottom, left);
    i_bottomRight = indexFromRowCol(bottom, right);

    if(row_line_start > 0)
        paintOverHorizontally(i_topLeft, (i_topRight - i_topLeft + 1),
            color);
    if(row_line_end < Config::NUM_ROW - 1)
        paintOverHorizontally(i_bottomLeft, (i_topRight - i_topLeft + 1),
            color);
    if(col_line_start > 0)
        paintOverVertically(i_topLeft,
            (((i_bottomLeft - i_topLeft) / Config::NUM_COL) + 1),
            color);
    if(col_line_end < Config::NUM_COL - 1)
        paintOverVertically(i_topRight,
            (((i_bottomRight - i_topRight) / Config::NUM_COL) + 1),
            color);
}

void ArragementModel::refreshModel() {
    emit dataChanged(QAbstractListModel::createIndex(0, 0),
        QAbstractListModel::createIndex(
            static_cast<int>(spaces.size() - 1), 0));
}

void ArragementModel::slotChangedState(int oldIndex, int newIndex, int len, bool oldHorizont, bool newHorizont)
{

        if (oldIndex > 0) {
            //закрашивание
            backlightShipsToSpaces(oldIndex, len, oldHorizont, ColorCell::NeytralColor);
            backlightBoundingBox(oldIndex, len, oldHorizont, ColorCell::NeytralColor);
            //новое раскрашивание
            backlightShipsToSpaces(newIndex, len, newHorizont, ColorCell::ShipColor);
            backlightBoundingBox(newIndex, len, newHorizont, ColorCell::CloseArea);
        }
}

void ArragementModel::paintOverHorizontally(
    int index, int len, ColorCell color) noexcept {
    for (int i = index; i < index + len; ++i) {
        spaces.at(static_cast<std::size_t>(i)) = color;
        emit dataChanged(QAbstractListModel::createIndex(i, 0),
            QAbstractListModel::createIndex(i, 0));
    }
}

void ArragementModel::paintOverVertically(int index, int len,
    ColorCell color) noexcept {
    for (int i = index; i < index + len * Config::NUM_COL; i += Config::NUM_COL) {
        spaces.at(static_cast<std::size_t>(i)) = color;
        emit dataChanged(QAbstractListModel::createIndex(i, 0),
            QAbstractListModel::createIndex(i, 0));
    }
}

int ArragementModel::row(int index) { return (index / Config::NUM_ROW); }

int ArragementModel::col(int index) { return (index % Config::NUM_COL); }

int ArragementModel::indexFromRowCol(int i_row, int i_col) {
    return (i_row * Config::NUM_ROW + i_col);
}

bool ArragementModel::inHorizontally(int index, int lenth) {
    return (col(index) >= 0 && (col(index) + lenth - 1) < Config::NUM_COL);
}

bool ArragementModel::inVertically(int index, int lenth) {
    return (row(index) >= 0 && (row(index) + lenth - 1) < Config::NUM_ROW);
}

bool ArragementModel::isEmptyIndex(int index)
{
    return (spaces.at(static_cast<std::size_t>(index)) == ColorCell::NeytralColor);
}
