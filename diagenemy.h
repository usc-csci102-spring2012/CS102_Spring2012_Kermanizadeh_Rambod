#ifndef DIAGENEMY_H
#define DIAGENEMY_H

#include "brick.h"

class DiagEnemy : public Brick
{
public:
    DiagEnemy(int, int);
    virtual ~DiagEnemy();
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

#endif // DIAGENEMY_H
