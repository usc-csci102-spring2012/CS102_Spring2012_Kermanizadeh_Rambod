#include "paddle.h"
#include <iostream>

Paddle::Paddle()
{
    image.load("player.png");
    rect = image.rect();
    destroyed = false;
    shield = 3;
    resetState();
}

Paddle::~Paddle()
{
    std::cout << ("Paddle deleted\n");
}

void Paddle::moveLeft(int left)
{
    if(rect.left() >= 2)
        rect.moveTo(left, rect.top());
}

void Paddle::moveRight(int right)
{
    if(rect.right() <= 298)
        rect.moveTo(right, rect.top());
}

void Paddle::resetState()
{
    rect.moveTo(200, 360);
}

QRect Paddle::getRect()
{
    return rect;
}

QImage & Paddle::getImage()
{
    return image;
}

bool Paddle::isDestroyed()
{
    return destroyed;
}

void Paddle::setDestroyed(bool destr)
{
    destroyed = destr;
}

void Paddle::changeShield(int x)
{
    shield += x;
}

int Paddle::getShield()
{
    return shield;
}

void Paddle::setShield(int x)
{
    shield = x;
}
