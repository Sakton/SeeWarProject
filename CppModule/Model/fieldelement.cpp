#include "fieldelement.h"

QString FieldElement::getImg() const
{
    return img;
}

void FieldElement::setImg(const QString &value)
{
    img = value;
}

bool FieldElement::getDestroed() const
{
    return destroed;
}

void FieldElement::setDestroed(bool value)
{
    destroed = value;
}

FieldElement::FieldElement(const QString &path) : img{path}
{

}

FieldElement::~FieldElement()
{
    
}
