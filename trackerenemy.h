#ifndef TRACKERENEMY_H
#define TRACKERENEMY_H

#include "brick.h"

class TrackerEnemy : public Brick
{
public:
    TrackerEnemy(int, int);
    virtual ~TrackerEnemy();
    virtual void autoMove(int);
    virtual bool timeToShoot(int);
    void reset();
    virtual void setDir(int);


private:
    bool moveRight;
    bool shoot;
    int xDir;
    int yDir;
    int origPosX;
    int origPosY;
};

#endif // TRACKERENEMY_H
