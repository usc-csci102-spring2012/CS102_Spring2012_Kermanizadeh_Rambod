#ifndef DROP_H
#define DROP_H

#include <QImage>
#include <QRect>

class Drop
{

  public:
    Drop(int, int);
    virtual ~Drop();

  public:
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();
    void autoMove();
    virtual void pickedUp() = 0;
    bool isMoney;
    bool isOneUp;
    bool isShield;

  protected:
    QImage image;
    QRect rect;
    int position;
    bool destroyed;
    int yDir;

};
#endif // DROP_H
