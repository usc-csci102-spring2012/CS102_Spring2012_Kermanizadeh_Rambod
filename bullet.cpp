#include "bullet.h"
#include <iostream>


  bool Bullet::getAttackPlayer() const
    {return attackPlayer;}

  bool Bullet::getDiag() const
    {return isDiagonal;}

  int Bullet::getX () const
    {return xPos;}

  int Bullet::getY () const
    {return yPos;}

  char Bullet::getSymbol () const
    {return symbol;}

  void Bullet::setX (int x)
    {xPos = x;}

  void Bullet::setY (int y)
    {yPos = y;}

Bullet::Bullet (bool enemyLaunch, bool moveDiag, int x, int y)
{
  attackPlayer = enemyLaunch;
  isDiagonal = moveDiag;

  image.load("bullet.png");

  rect = image.rect();

  if(isDiagonal == true){
    symbol = '.';
    xDir = 1;
  }

  else if(attackPlayer == true){
    symbol = '*';
    yDir = 1;
    xDir = 0;
  }
  else{
    symbol = '!';
    yDir = -1;
    xDir = 0;
  }

  xPos = x + 15;
  yPos = y;

  destroyed = false;

  rect.moveTo(xPos, yPos);
}

Bullet::Bullet()
{
    xDir = 1;
    yDir = -1;
    attackPlayer = false;
    isDiagonal = false;
    symbol = '!';
    //xPos = 200;
    //yPos = 300;

    image.load("ball.png");

    rect = image.rect();
    destroyed = false;
    rect.moveTo(xPos, yPos);
}

void Bullet::moveBullet (){
  if(attackPlayer == true)
    yPos++;

  else
    yPos--;
}

void Bullet::moveBulletDiag(){
  yPos++;
  xPos++;
}

Bullet::~Bullet() {
  std::cout << ("Ball deleted\n");
}

void Bullet::autoMove(int level)
{
    for (int i=0; i<=(level+1); i++){
        rect.translate(xDir, yDir);

        if(rect.left() == 0){
            destroyed = true;
        }

        if(rect.right() == 300){
            //delete this;
            destroyed = true;
        }

        if(rect.top() == 0){
            destroyed = true;
            //delete this;
        }
    }
}

void Bullet::moveBottom(int bottom)
{
    rect.moveBottom(bottom);
}

void Bullet::moveTop(int top)
{
    rect.moveTop(top);
}

void Bullet::moveLeft(int left)
{
    rect.moveLeft(left);
}

void Bullet::moveRight(int right)
{
    rect.moveRight(right);
}

void Bullet::setXDir(int x)
{
    xDir = x;
}

void Bullet::setYDir(int y)
{
    yDir = y;
}

int Bullet::getXDir()
{
    return xDir;
}

int Bullet::getYDir()
{
    return yDir;
}

QRect Bullet::getRect()
{
    return rect;
}

QImage & Bullet::getImage()
{
    return image;
}

bool Bullet::isDestroyed()
{
    return destroyed;
}

void Bullet::setDestroyed(bool destr)
{
    destroyed = destr;
}

