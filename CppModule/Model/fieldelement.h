#ifndef FIELDELEMENT_H
#define FIELDELEMENT_H

class FieldElement
{
    int index;
public:
    FieldElement(int idx = 0);
    int getIndex() const;
    void setIndex(int value);
};

#endif // FIELDELEMENT_H
