#include "oneupdrop.h"

OneUpDrop::OneUpDrop(int x, int y) : Drop(x, y)
{
    image.load("OneUpDrop.png");
    isMoney = false;
    isOneUp = true;
    isShield = false;
    rect  = image.rect();
    rect.translate(x, y);
}

OneUpDrop::~OneUpDrop()
{
    //std::cout << ("Basic enemy deleted\n");
}

void OneUpDrop::pickedUp(){
    //Add code for adding a life so it actually does something
}
