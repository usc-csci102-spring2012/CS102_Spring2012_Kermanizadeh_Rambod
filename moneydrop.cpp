#include "moneydrop.h"

MoneyDrop::MoneyDrop(int x, int y) : Drop(x, y)
{
    image.load("moneyDrop.png");
    isMoney = true;
    isOneUp = false;
    isShield = false;
    rect  = image.rect();
    rect.translate(x, y);
}

MoneyDrop::~MoneyDrop()
{
    //std::cout << ("Basic enemy deleted\n");
}

void MoneyDrop::pickedUp(){
    //Add code for adding a life so it actually does something
}
