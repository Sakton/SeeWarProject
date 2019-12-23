#ifndef FLOT_H
#define FLOT_H
#include "baseflotinterface.h"

class Flot : public BaseFlotInterface
{
    public:
        Flot();
        // BaseFlotInterface interface
        int getNumberElementFlot(int index) override;
};

#endif // FLOT_H
