#include "diagenemy.h"

DiagEnemy::DiagEnemy(int x, int y) : Brick(x, y)
{
    image.load("diagonalEnemy.png");
    hp = 1;
    shoot = false;
    moveRight = true;
    xDir = 1;
    yDir = 1;
    origPosX = x;
    origPosY = y;
    tracker = false;
    rect  = image.rect();
    rect.translate(x, y);
}

DiagEnemy::~DiagEnemy()
{
    //std::cout << ("Basic enemy deleted\n");
}

void DiagEnemy::autoMove(int level)
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
}

void DiagEnemy::setDir(int playerX){

}

bool DiagEnemy::timeToShoot(int x)
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

void DiagEnemy::reset()
{
    rect.moveTo(origPosX, origPosY);
}
