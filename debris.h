#ifndef DEBRIS_H
#define DEBRIS_H

#include "floaters.h"

class Debris : public Floaters
{
public:
    Debris(int, int);
    virtual ~Debris();
    virtual void hit();
};

#endif // DEBRIS_H
