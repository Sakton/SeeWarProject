#ifndef TESTPALUBNEW_H
#define TESTPALUBNEW_H
#include "abstractgamefigure.h"

class TestPalubNew : public AbstractGameFigure
{
    Q_OBJECT
public:
    TestPalubNew(QObject *parent = nullptr);
    // AbstractGameFigure interface
    public:
    QColor getColor() override;
    QString getResourceImg() override;
    int getRotateAngleFigure() override;
    void setSelfToField(Field *field) override;
    void resetSelfToField() override;

private:
    QString testRes;
};

#endif // TESTPALUBNEW_H
