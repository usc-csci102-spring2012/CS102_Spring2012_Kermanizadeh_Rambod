#ifndef BULLET_H
#define BULLET_H

#include <QRect>
#include <QImage>

class Bullet
{
 private:
  int xPos, yPos;
  char symbol;
  bool attackPlayer;
  bool isDiagonal;
  bool destroyed;

  int yDir;
  int xDir;
  int speed;
  QImage image;
  QRect rect;

 public:
  Bullet();
  Bullet (bool, bool, int, int);
  ~Bullet();

  void moveBullet();

  bool getAttackPlayer() const;

  bool getDiag() const;

  int getX () const;

  int getY () const;

  char getSymbol () const;

  void setX (int);

  void setY (int);

  void moveBulletDiag();

  bool isDestroyed();
  void setDestroyed(bool);

  void setXDir(int);
  int getXDir();
  int getYDir();
  void setYDir(int);
  void moveBottom(int);
  void moveTop(int);
  void moveLeft(int);
  void moveRight(int);
  void autoMove(int);
  QRect getRect();
  QImage & getImage();
};


#endif // BULLET_H
