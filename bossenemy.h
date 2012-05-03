#ifndef BOSSENEMY_H
#define BOSSENEMY_H

#include "brick.h"

class BossEnemy : public Brick
{
public:
    BossEnemy(int, int);
    virtual ~BossEnemy();
    virtual void autoMove(int);
    virtual bool timeToShoot(int);
    virtual void setDir(int);

private:
    bool moveRight;
    bool shoot;
    int xDir;
};

#endif // BOSSENEMY_H
