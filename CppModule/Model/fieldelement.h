#ifndef FIELDELEMENT_H
#define FIELDELEMENT_H
#include <QString>

class FieldElement
{
    QString img;
    bool destroed;
public:
    FieldElement(const QString &path = "");
    virtual ~FieldElement();
    virtual void getDamage() = 0;
    QString getImg() const;
    void setImg(const QString &value);
    bool getDestroed() const;
    void setDestroed(bool value);
};

#endif // FIELDELEMENT_H
