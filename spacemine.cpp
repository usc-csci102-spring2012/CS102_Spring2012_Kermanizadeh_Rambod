#include "spacemine.h"

SpaceMine::SpaceMine(int x, int y) : Floaters(x, y)
{
    image.load("spaceMine.png");
    isDebris = false;
    isMine = true;
    rect  = image.rect();
    rect.translate(x, y);
}

SpaceMine::~SpaceMine()
{
    //std::cout << ("Basic enemy deleted\n");
}

void SpaceMine::hit(){
    //do damage to player
}

