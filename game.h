#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "brick.h"
#include "paddle.h"
#include "bullet.h"
#include "basicenemy.h"
#include "diagenemy.h"
#include "trackerenemy.h"
#include "drop.h"
#include "shielddrop.h"
#include "oneupdrop.h"
#include "moneydrop.h"
#include "floaters.h"
#include "spacemine.h"
#include "debris.h"
#include "bossenemy.h"
#include "slowdrop.h"
#include <QWidget>
#include <QKeyEvent>
#include <QVector>

class Game : public QWidget
{
  Q_OBJECT

  public:
    Game(QWidget *parent = 0);
    ~Game();

  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void playerShoot();
    void victory();
    void checkCollision();
    void enemyDrop(int, int);
    void spawnFloaters();
    void changeScore(int);
    int getScore();
    void changeLives(int);
    int getLives();
    void lowerShields();
    void spawnEnemies();

  private:
    int x;
    int timerId;
    Ball *ball;
    Paddle *paddle;
    //Brick * bricks[30];
    //QVector<Brick> enemyVec;
    //Brick * enemyVec[12];
    QVector<Brick*> enemyVec;
    QVector<Bullet> bulletVec;
    QVector<Bullet> enemyBulletVec;
    QVector<Drop*> dropVec;
    QVector<Floaters*> floaterVec;
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
    int level;
    int lives;
    int score;
    int shield;
    bool finishedGame;

public slots:
    void startGame();
    void pauseGame();
    void stopGame();

signals:
     void scoreChanged(int score);
     void levelChanged(int level);
     void livesChanged(int lives);
     void shieldChanged(int shield);

};

#endif // GAME_H
