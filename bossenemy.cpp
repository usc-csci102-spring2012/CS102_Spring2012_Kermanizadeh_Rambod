#include "bossenemy.h"

BossEnemy::BossEnemy(int x, int y) : Brick(x, y)
{
    image.load("boss.png");
    shoot = false;
    moveRight = true;
    xDir = 1;
    tracker = false;
    hp = 5;
    rect  = image.rect();
    rect.translate(x, y);
}

BossEnemy::~BossEnemy()
{
    //std::cout << ("Basic enemy deleted\n");
}

void BossEnemy::autoMove(int level)
{
    for (int i=0; i<level; i++){
        rect.translate(0, 0);

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

void BossEnemy::setDir(int playerX){

}

bool BossEnemy::timeToShoot(int x)
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
