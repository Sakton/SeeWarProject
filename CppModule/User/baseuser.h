#ifndef BASEUSER_H
#define BASEUSER_H
#include <QObject>
#include <QDebug>

class BaseUser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int countMoves READ countMoves WRITE setCountMoves)

public:
    enum StateMovesUser { //Результат сделанного хода //
        MISS = 0, SHIP_DAMAGE ,SHIP_DEAD, FLOT_DEAD/* HIT, TEST = 100 */
    };

    explicit BaseUser(QObject *parent = nullptr);

    StateMovesUser stateMovesUser() const;
    int countMoves() const;

    QString name() const;
    void setName(const QString &name);

    void setDamageState();
    void setMissState();
//    void setHitState();

    public slots:
    void setCountMoves(int countMoves);


    protected:
    StateMovesUser m_stateMovesUser;
    int m_countMoves;
    QString m_name;
};

#endif // BASEUSER_H
