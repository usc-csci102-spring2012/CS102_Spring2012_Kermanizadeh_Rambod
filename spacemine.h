#ifndef SPACEMINE_H
#define SPACEMINE_H

#include "floaters.h"

class SpaceMine : public Floaters
{
public:
    SpaceMine(int, int);
    virtual ~SpaceMine();
    virtual void hit();
};

#endif // SPACEMINE_H
