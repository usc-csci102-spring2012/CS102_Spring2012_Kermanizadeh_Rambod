#include "trackerenemy.h"

TrackerEnemy::TrackerEnemy(int x, int y) : Brick(x, y)
{
    image.load("trackerEnemy.png");
    hp = 1;
    shoot = false;
    moveRight = true;
    xDir = 1;
    yDir = 0;
    origPosX = x;
    origPosY = y;
    tracker = true;
    rect  = image.rect();
    rect.translate(x, y);
}

TrackerEnemy::~TrackerEnemy()
{
    //std::cout << ("Basic enemy deleted\n");
}

void TrackerEnemy::autoMove(int level)
{
    for (int i=0; i<level; i++){
        rect.translate(xDir, yDir);

        if(rect.left() == 0){
            moveRight = true;
            xDir = 1;
        }

        if(rect.right() == 300){
            moveRight = false;
            xDir = -1;
        }

        if(rect.bottom() == 400){
            reset();
        }
    }

    //setDir();
}

void TrackerEnemy::setDir(int playerX){
    if(rect.x() >= playerX){
        moveRight = false;
        xDir = -1;
    }

    else if (rect.x() <= playerX){
        moveRight = true;
        xDir = 1;
    }

    else{
        moveRight = false;
        xDir = 0;
    }
}

bool TrackerEnemy::timeToShoot(int x)
{
    if(this->getRect().x() == x){
        shoot = true;
        return shoot;
    }

    else{
        shoot = false;
        return shoot;
    }
}

void TrackerEnemy::reset()
{
    rect.moveTo(origPosX, origPosY);
}
