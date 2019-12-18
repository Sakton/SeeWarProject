#ifndef CELL_H
#define CELL_H
#include "fieldelement.h"

class Cell
{
    int index;
    FieldElement *elementGame;
public:
    Cell(FieldElement *el = nullptr);
};

#endif // CELL_H
