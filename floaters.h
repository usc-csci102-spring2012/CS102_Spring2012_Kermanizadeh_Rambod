#ifndef FLOATERS_H
#define FLOATERS_H

#include <QImage>
#include <QRect>

class Floaters
{
public:
  Floaters(int, int);
  virtual ~Floaters();

public:
  bool isDestroyed();
  void setDestroyed(bool);
  QRect getRect();
  void setRect(QRect);
  QImage & getImage();
  void autoMove(int);
  virtual void hit() = 0;
  bool isDebris;
  bool isMine;

protected:
  QImage image;
  QRect rect;
  int position;
  bool destroyed;
  int yDir;
};

#endif // FLOATERS_H
