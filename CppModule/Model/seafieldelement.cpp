#include "seafieldelement.h"
#include <QDebug>

SeaFieldElement::SeaFieldElement(const QString &path) : FieldElement(path)
{

}

void SeaFieldElement::getDamage()
{
    qDebug() << "SeaFieldElement::damage \n";
}

