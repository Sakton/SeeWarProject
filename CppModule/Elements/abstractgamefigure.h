#ifndef ABSTRACTGAMEFIGURE_H
#define ABSTRACTGAMEFIGURE_H
#include <QColor>
#include <QObject>
//#include "../Field/abstractfield.h"
//#include "../Model/field.h"

class Field;

//class AbstractField;

class AbstractGameFigure : public QObject
{
    Q_OBJECT
public:
    AbstractGameFigure(QObject *parent = nullptr);
    virtual ~AbstractGameFigure();
    virtual QColor getColor() = 0;
    virtual QString getResourceImg() = 0;
    virtual int getRotateAngleFigure() = 0; //TODO нужен ли этот метод тут
    virtual void setSelfToField(Field *field) = 0;
    virtual void resetSelfToField() = 0;
};

Q_DECLARE_OPAQUE_POINTER(AbstractGameFigure)
Q_DECLARE_INTERFACE(AbstractGameFigure, "CppInterface_AbstractGameFigure")

#endif // ABSTRACTGAMEFIGURE_H
