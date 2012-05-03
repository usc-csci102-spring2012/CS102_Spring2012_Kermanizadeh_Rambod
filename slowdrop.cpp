#include "slowdrop.h"

SlowDrop::SlowDrop(int x, int y) : Drop(x, y)
{
    image.load("slowDrop.png");
    isMoney = false;
    isOneUp = false;
    isShield = false;
    rect  = image.rect();
    rect.translate(x, y);
}

SlowDrop::~SlowDrop()
{
    //std::cout << ("Basic enemy deleted\n");
}

void SlowDrop::pickedUp(){
    //Add code for adding a life so it actually does something
}
