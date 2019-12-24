#ifndef FIELDELEMENT_H
#define FIELDELEMENT_H

class FieldElement
{
public:
    FieldElement();
    int index() const;

private:
    static int countFieldElements;
    int m_index;
};

#endif // FIELDELEMENT_H
