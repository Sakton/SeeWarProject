#ifndef ABSTRACTFIELD_H
#define ABSTRACTFIELD_H
#include <QAbstractListModel>
#include "abstractfieldelement.h"

class AbstractFieldElement;

class AbstractField : public QAbstractListModel
{
public:
    AbstractField(QObject *parent = nullptr);
    virtual ~AbstractField();
    //любое поле возвращает обьект - клетку, куда надо что то поставить
    virtual AbstractFieldElement *getFieldElementCell(int index) = 0;
};

#endif // ABSTRACTFIELD_H
