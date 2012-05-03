#include "shielddrop.h"

ShieldDrop::ShieldDrop(int x, int y) : Drop(x, y)
{
    image.load("shieldDrop.png");
    isMoney = false;
    isOneUp = false;
    isShield = true;
    rect  = image.rect();
    rect.translate(x, y);
}

ShieldDrop::~ShieldDrop()
{
    //std::cout << ("Basic enemy deleted\n");
}

void ShieldDrop::pickedUp(){
    //Add code for boosting shields so it actually does something
}
