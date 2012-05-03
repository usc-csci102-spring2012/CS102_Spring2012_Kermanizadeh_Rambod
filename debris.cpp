#include "debris.h"

Debris::Debris(int x, int y) : Floaters(x, y)
{
    image.load("debris.png");
    isDebris = true;
    isMine = false;
    rect  = image.rect();
    rect.translate(x, y);
}

Debris::~Debris()
{
    //std::cout << ("Basic enemy deleted\n");
}

void Debris::hit(){
    //debris does nothing when hit
}

