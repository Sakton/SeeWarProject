#include "fieldelement.h"

int FieldElement::getIndex() const
{
    return index;
}

void FieldElement::setIndex(int value)
{
    index = value;
}

FieldElement::FieldElement(int idx) : index{idx}
{

}

