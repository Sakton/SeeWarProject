#ifndef SEAFIELDELEMENT_H
#define SEAFIELDELEMENT_H
#include <QString>
#include "fieldelement.h"

class SeaFieldElement : public FieldElement
{
    QString img;
    bool destroed;
public:
    explicit SeaFieldElement(const QString &path = "");
    // FieldElement interface
    void getDamage() override;
};

#endif // SEAFIELDELEMENT_H
