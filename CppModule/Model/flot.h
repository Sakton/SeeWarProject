#ifndef FLOT_H
#define FLOT_H
#include "baseflotinterface.h"
#include "ship.h"

class Flot : public BaseFlotInterface
{
    std::vector<Ship *> ships;
    public:
        Flot();
        // BaseFlotInterface interface
        int getNumberElementFlot(int index) override;
};

#endif // FLOT_H
