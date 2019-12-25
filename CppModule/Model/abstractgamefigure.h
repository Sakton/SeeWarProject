#ifndef ABSTRACTGAMEFIGURE_H
#define ABSTRACTGAMEFIGURE_H
#include <QObject>
#include <QColor>

class AbstractGameFigure : public QObject
{
    Q_OBJECT
public:
    explicit AbstractGameFigure(QObject *parent = nullptr);
    virtual ~AbstractGameFigure();
    virtual void testFunction() = 0;
    virtual QColor getColor() = 0;
    virtual QString getResourceImg() = 0;
};

#endif // ABSTRACTGAMEFIGURE_H
