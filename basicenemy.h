#ifndef BASICENEMY_H
#define BASICENEMY_H

#include "brick.h"

class BasicEnemy : public Brick
{
public:
    BasicEnemy(int, int);
    virtual ~BasicEnemy();
    virtual void autoMove(int);
    virtual bool timeToShoot(int);
    virtual void setDir(int);

private:
    bool moveRight;
    bool shoot;
    int xDir;
};

#endif // BASICENEMY_H
