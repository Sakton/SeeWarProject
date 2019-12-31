#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "../Model/abstractgamefigure.h"

class EmptyCell : /*public QObject, */public AbstractGameFigure
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
    void setSelfToField(AbstractField *field) override;


signals:
    void getColorChanged(QColor getColor);
    void imgChanged(QString img);

public slots:
    void setImg(QString img);

private:
    QColor m_color{"magenta"};
    QString m_img{"qrc:/QmlModule/qml/DefaultGui/img/Palybs/types1/types1_04.png"};
};

#endif // EMPTYCELL_H
