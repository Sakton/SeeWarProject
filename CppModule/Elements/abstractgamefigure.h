#ifndef ABSTRACTGAMEFIGURE_H
#define ABSTRACTGAMEFIGURE_H
#include <QColor>
#include <QObject>

class Field;

class AbstractGameFigure : public QObject
{
    Q_OBJECT
public:
    AbstractGameFigure(QObject *parent = nullptr);
    virtual ~AbstractGameFigure();
    virtual QColor getColor() = 0;
    virtual QString getResourceImg() = 0;
    virtual int getRotateAngleFigure() = 0;
    virtual void setSelfToField(Field *field) = 0;
    virtual void resetSelfToField() = 0;
};

Q_DECLARE_OPAQUE_POINTER(AbstractGameFigure)
Q_DECLARE_INTERFACE(AbstractGameFigure, "CppInterface_AbstractGameFigure")

#endif // ABSTRACTGAMEFIGURE_H
