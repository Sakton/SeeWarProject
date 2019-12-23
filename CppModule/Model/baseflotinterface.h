#ifndef BASEFLOTINTERFACE_H
#define BASEFLOTINTERFACE_H
#include "config.h"

class BaseFlotInterface
{
    public:
        virtual ~BaseFlotInterface();
        virtual int getNumberElementFlot(int index) = 0;
};

#endif // BASEFLOTINTERFACE_H
