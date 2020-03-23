#include "testpalubnew.h"

TestPalubNew::TestPalubNew(QObject *parent)
    : AbstractGameFigure(parent), testRes{"qrc:/QmlModule/qml/DefaultGui/img/cherep.gif"}
{
}

QColor TestPalubNew::getColor()
{
    return {};
}

QString TestPalubNew::getResourceImg()
{
    return testRes;
}

int TestPalubNew::getRotateAngleFigure()
{
    return 0;
}

void TestPalubNew::setSelfToField(Field *field)
{
    Q_UNUSED(field)
}

void TestPalubNew::resetSelfToField()
{

}
