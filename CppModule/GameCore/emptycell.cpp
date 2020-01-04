#include "emptycell.h"

EmptyCell::EmptyCell(QObject *parent) : AbstractGameFigure(parent)
{

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

void EmptyCell::setSelfToField(AbstractField *field)
{
    Q_UNUSED(field)
}

void EmptyCell::resetSelfToField()
{

}

void EmptyCell::setImg(QString img)
{
    if (m_img == img)
        return;
    m_img = img;
    emit imgChanged(m_img);
}
