#ifndef ONEUPDROP_H
#define ONEUPDROP_H

#include "drop.h"

class OneUpDrop : public Drop
{
public:
    OneUpDrop(int, int);
    virtual ~OneUpDrop();
    virtual void pickedUp();
};

#endif // ONEUPDROP_H
