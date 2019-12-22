#ifndef PALUB_H
#define PALUB_H
#include "elementfieldgame.h"

class Palub : public ElementFieldGame
{
        Q_OBJECT
    public:
        explicit Palub(int indx = 0, QObject *parent = nullptr);
        // ElementFieldGame interface
        void getDamage(int index) override;
        //состояние жизни: ты жив? - да / нет
        int idx() const;

    public slots:
        void setIdx(int idx);

    signals:
        void palubIsDead();

    private:
        //TODO Q_PROPERTY - нужно ли?
//        Q_PROPERTY(bool stateLife READ stateLife WRITE setStateLife NOTIFY palubIsDead)
        Q_PROPERTY(int idx READ idx WRITE setIdx)
        bool m_stateLife;
        int m_idx;
};

#endif // PALUB_H
