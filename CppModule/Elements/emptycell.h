#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "abstractgamefigure.h"

class EmptyCell : public AbstractGameFigure
{
    Q_OBJECT
    Q_INTERFACES(AbstractGameFigure)
    Q_PROPERTY(QColor color READ getColor NOTIFY getColorChanged)
    Q_PROPERTY(QString img READ getResourceImg WRITE setImg NOTIFY imgChanged)

public:
    explicit EmptyCell(QObject *parent = nullptr);
    void setColor(const QColor &color);
    // AbstractGameFigure interface
    QColor getColor() override;
    QString getResourceImg() override;
    void setSelfToField(Field *field) override;
    void resetSelfToField() override;
    int getRotateAngleFigure() override;

signals:
    void getColorChanged(QColor getColor);
    void imgChanged(QString img);

public slots:
    void setImg(QString img);

private:
    QColor m_color;
    QString m_img;
};

#endif // EMPTYCELL_H
