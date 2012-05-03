#ifndef MONEYDROP_H
#define MONEYDROP_H

#include "drop.h"

class MoneyDrop : public Drop
{
public:
    MoneyDrop(int, int);
    virtual ~MoneyDrop();
    virtual void pickedUp();
};


#endif // MONEYDROP_H
