#ifndef SHIP_H
#define SHIP_H
#include "elementfieldgame.h"
#include "config.h"
#include "palub.h"
#include <vector>

class Ship : public ElementFieldGame
{
        Q_OBJECT
    public:
        enum Location {
            HORIZONTAL = 0,
            VERTICAl
        };

        explicit Ship(int countPalubs = 0, int startIndex = 0, Location location = Location::HORIZONTAL, QObject *parent = nullptr);
        // ElementFieldGame interface
        void getDamage(int index) override;
        bool stateLife() const;
        int countLifePalub() const;
    public slots:
        void setCountLifePalub(int countLifePalub);
        void palubDamaged();

    signals:
        void shipIsDead(bool stateLife);
        void countLifePalubChanged(int countLifePalub);

    private:
        Q_PROPERTY(bool stateLife READ stateLife NOTIFY shipIsDead)
        Q_PROPERTY(int countLifePalub READ countLifePalub WRITE setCountLifePalub NOTIFY countLifePalubChanged)
        Q_PROPERTY(bool location READ location WRITE setLocation NOTIFY locationChanged)

        bool m_stateLife;
        int m_countLifePalub;
        std::vector<ElementFieldGame *> palubs;
};

#endif // SHIP_H
