#include "basicenemy.h"

BasicEnemy::BasicEnemy(int x, int y) : Brick(x, y)
{
    image.load("basicEnemy.png");
    shoot = false;
    moveRight = true;
    xDir = 1;
    tracker = false;
    hp = 1;
    rect  = image.rect();
    rect.translate(x, y);
}

BasicEnemy::~BasicEnemy()
{
    //std::cout << ("Basic enemy deleted\n");
}

void BasicEnemy::autoMove(int level)
{
    for (int i=0; i<level; i++){
        rect.translate(xDir, 0);

        if(rect.left() == 0){
            moveRight = true;
            xDir = 1;
        }

        if(rect.right() == 300){
            moveRight = false;
            xDir = -1;
        }
    }
}

void BasicEnemy::setDir(int playerX){

}

bool BasicEnemy::timeToShoot(int x)
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
