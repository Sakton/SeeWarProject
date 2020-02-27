#ifndef BASEUSER_H
#define BASEUSER_H
#include <QObject>
#include <QDebug>

class BaseUser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int countMoves READ countMoves WRITE setCountMoves)

    public:
    enum ResultMakeMove { //Результат сделанного хода //
        DAMAGE = 0, MISS, HIT
    };
    explicit BaseUser(QObject *parent = nullptr);

    ResultMakeMove damag() const
    {
        return m_damag;
    }

    int countMoves() const
    {
        return m_countMoves;
    }

    public slots:
    void setDamag(int damag)
    {
       // m_damag = (damag == 0) ? ResultMakeMove::YES : ResultMakeMove::NO;
    }

    void setCountMoves(int countMoves)
    {
        qDebug() << "countMoves = " << countMoves;
        m_countMoves = countMoves;
    }

    protected:
        ResultMakeMove m_damag;
        int m_countMoves;
};

#endif // BASEUSER_H
