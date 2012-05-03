#ifndef SLOWDROP_H
#define SLOWDROP_H

#include "drop.h"

class SlowDrop : public Drop
{
public:
    SlowDrop(int, int);
    virtual ~SlowDrop();
    virtual void pickedUp();
};

#endif // SLOWDROP_H
