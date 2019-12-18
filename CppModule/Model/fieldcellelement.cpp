#include "fieldcellelement.h"

FieldCellElement::FieldCellElement(int ind, QObject *parent):index{ind}
{

}

int FieldCellElement::getIndex() const
{
    return index;
}

void FieldCellElement::setIndex(int value)
{
    index = value;
}

int PalubaElement::getType() const
{
    return type;
}

void PalubaElement::setType(int value)
{
    type = value;
}

PalubaElement::PalubaElement(int tp, int ind, QObject *parent) : FieldCellElement(ind, parent)
{

}
