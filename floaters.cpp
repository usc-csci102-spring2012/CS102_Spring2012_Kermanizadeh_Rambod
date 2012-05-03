#include "floaters.h"
#include <iostream>

Floaters::Floaters(int x, int y)
{
    //image.load("C:/Users/Rambod/QtProjects/CS102Project/ball.png");
    destroyed = false;
    //rect  = image.rect();
    //rect.translate(x, y);
    yDir = 1;
}

Floaters::~Floaters()
{
    std::cout << ("Brick deleted\n");
}

QRect Floaters::getRect()
{
    return rect;
}

void Floaters::setRect (QRect rct)
{
    rect = rct;
}

QImage & Floaters::getImage()
{
    return image;
}

bool Floaters::isDestroyed()
{
    return destroyed;
}

void Floaters::setDestroyed(bool destr)
{
    destroyed = destr;
}

void Floaters::autoMove(int level)
{
    for (int i=0; i<level+4; i++){
        rect.translate(0, yDir);
    }
}
