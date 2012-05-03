#ifndef BRICK_H
#define BRICK_H

//base class for all enemies

#include <QImage>
#include <QRect>

class Brick
{

  public:
    Brick(int, int);
    virtual ~Brick();

  public:
    void resetState();
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();
    virtual void autoMove(int) = 0;
    virtual bool timeToShoot(int) = 0;
    virtual void setDir(int) = 0;
    bool tracker;
    int hp;


  protected:
    QImage image;
    QRect rect;
    int position;
    bool destroyed;


};

#endif // BRICK_H
