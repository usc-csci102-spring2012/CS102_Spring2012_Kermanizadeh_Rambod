#ifndef PADDLE_H
#define PADDLE_H

#include <QImage>
#include <QRect>

class Paddle
{

  public:
    Paddle();
    ~Paddle();
    void resetState();
    void moveLeft(int);
    void moveRight(int);
    QRect getRect();
    QImage & getImage();
    bool isDestroyed();
    void setDestroyed(bool);
    void changeShield(int);
    int getShield();
    void setShield(int);

  private:
    QImage image;
    QRect rect;
    bool destroyed;
    int shield;

};

#endif // PADDLE_H
