#ifndef SHIELDDROP_H
#define SHIELDDROP_H

#include "drop.h"

class ShieldDrop : public Drop
{
public:
    ShieldDrop(int, int);
    virtual ~ShieldDrop();
    virtual void pickedUp();
};

#endif // SHIELDDROP_H
