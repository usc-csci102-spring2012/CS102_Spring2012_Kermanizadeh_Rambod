#include "drop.h"
#include <iostream>

Drop::Drop(int x, int y)
{
    //image.load("C:/Users/Rambod/QtProjects/CS102Project/ball.png");
    destroyed = false;
    //rect  = image.rect();
    //rect.translate(x, y);
    yDir = 1;
}

Drop::~Drop()
{
    std::cout << ("Brick deleted\n");
}

QRect Drop::getRect()
{
    return rect;
}

void Drop::setRect (QRect rct)
{
    rect = rct;
}

QImage & Drop::getImage()
{
    return image;
}

bool Drop::isDestroyed()
{
    return destroyed;
}

void Drop::setDestroyed(bool destr)
{
    destroyed = destr;
}

void Drop::autoMove()
{
    rect.translate(0, yDir);
}
