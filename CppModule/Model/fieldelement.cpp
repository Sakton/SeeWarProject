#include "fieldelement.h"

int FieldElement::countFieldElements = 0;

FieldElement::FieldElement() : m_index{ countFieldElements++ }
{

}

int FieldElement::index() const
{
    return m_index;
}
