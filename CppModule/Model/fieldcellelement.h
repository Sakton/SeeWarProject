#ifndef FIELDCELLELEMENT_H
#define FIELDCELLELEMENT_H
#include <QObject>
//TODO для теста
class FieldCellElement : public QObject
{
    Q_OBJECT
    int index;
public:
    FieldCellElement(int ind = 0, QObject *parent = nullptr);
    Q_INVOKABLE int getIndex() const;
    void setIndex(int value);
};



class PalubaElement : public FieldCellElement {
    Q_OBJECT
    int type;
public:
    PalubaElement(int tp = 0, int ind = 0, QObject *parent = nullptr);
    int getType() const;
    void setType(int value);
};

//Q_DECLARE_METATYPE(FieldCellElement)
//Q_DECLARE_OPAQUE_POINTER(FieldCellElement)
//Q_DECLARE_METATYPE(PalubaElement)
//Q_DECLARE_OPAQUE_POINTER(PalubaElement)

#endif // FIELDCELLELEMENT_H
