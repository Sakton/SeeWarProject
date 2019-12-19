#include "cell.h"
int Cell::sIndex = 0;

Cell::Cell(ElementFieldGame *el) : element{el}
{
    index = sIndex++;
}

ElementFieldGame *Cell::getElement() const
{
    return element;
}

void Cell::setElement(ElementFieldGame *value)
{
    element = value;
}

int Cell::getIndex() const
{
    return index;
}

