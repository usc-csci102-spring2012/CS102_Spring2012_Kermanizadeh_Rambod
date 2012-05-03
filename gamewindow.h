#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtGui>
#include <QFrame>
#include <QWidget>
#include "game.h"

 class QLCDNumber;
 class QLabel;
 class QPushButton;

 class Game;

 class GameWindow : public QWidget
 {
     Q_OBJECT

 public:
     GameWindow();

 private:
     QLabel *createLabel(const QString &text);
     Game *board;
     QLCDNumber *scoreLcd;
     QLCDNumber *levelLcd;
     QLCDNumber *shieldLcd;
     QLCDNumber *livesLcd;
     QPushButton *startButton;
     QPushButton *quitButton;
     QPushButton *pauseButton;
 };

#endif // GAMEWINDOW_H
