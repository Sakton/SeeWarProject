#ifndef CELL_H
#define CELL_H
#include "elementfieldgame.h"
#include "config.h"


//Отвечает за ...

class Cell
{
    static int sIndex;
    int index;
    ElementFieldGame *element;
public:
    explicit Cell(ElementFieldGame *el = nullptr);

    ElementFieldGame *getElement() const;
    void setElement(ElementFieldGame *value);
    int getIndex() const;
    void setIndex(int value);
};

#endif // CELL_H
