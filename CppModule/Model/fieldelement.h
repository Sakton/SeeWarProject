#ifndef FIELDELEMENT_H
#define FIELDELEMENT_H
#include <QObject>


//??? удаилить если пройдет FieldCellElement
class FieldElement
{
    int index;
public:
    FieldElement(int idx = 0);
    int getIndex() const;
    void setIndex(int value);
};

Q_DECLARE_METATYPE(FieldElement)
Q_DECLARE_OPAQUE_POINTER(FieldElement)

#endif // FIELDELEMENT_H
