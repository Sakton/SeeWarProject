#include "emptycell.h"

EmptyCell::EmptyCell(QObject *parent) : AbstractGameFigure(parent), m_color{"#00000000"}, m_img{}
{
// "#00000000" - черный прозрачный
}

void EmptyCell::setColor(const QColor &color)
{
    m_color = color;
}

QColor EmptyCell::getColor()
{
    return m_color;
}

QString EmptyCell::getResourceImg()
{
    return m_img;
}

void EmptyCell::setSelfToField(Field *field)
{
    Q_UNUSED(field)
}

void EmptyCell::resetSelfToField()
{

}

int EmptyCell::getRotateAngleFigure()
{
    return {};
}

void EmptyCell::setImg(QString img)
{
    if (m_img == img)
        return;
    m_img = img;
    emit imgChanged(m_img);
}
