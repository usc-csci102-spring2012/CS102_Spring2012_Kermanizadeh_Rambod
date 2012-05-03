#include <QtGui>
#include <QDesktopWidget>
#include <QApplication>
#include "game.h"
#include "gamewindow.h"

GameWindow::GameWindow()
{
    board = new Game(this);
    board->setFocusPolicy(Qt::StrongFocus);

    scoreLcd = new QLCDNumber(5);
    scoreLcd->setSegmentStyle(QLCDNumber::Filled);
    levelLcd = new QLCDNumber(2);
    levelLcd->setSegmentStyle(QLCDNumber::Filled);
    shieldLcd = new QLCDNumber(1);
    shieldLcd->setSegmentStyle(QLCDNumber::Filled);
    livesLcd = new QLCDNumber(2);
    livesLcd->setSegmentStyle(QLCDNumber::Filled);


    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("&Pause"));
    pauseButton->setFocusPolicy(Qt::NoFocus);

    connect(startButton, SIGNAL(clicked()), board, SLOT(startGame()));
    connect(quitButton , SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(pauseButton, SIGNAL(clicked()), board, SLOT(pauseGame()));
    connect(board, SIGNAL(shieldChanged(int)), shieldLcd, SLOT(display(int)));
    connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));
    connect(board, SIGNAL(levelChanged(int)), levelLcd, SLOT(display(int)));
    connect(board, SIGNAL(livesChanged(int)), livesLcd, SLOT(display(int)));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("LEVEL")), 0, 1);
    layout->addWidget(levelLcd, 1, 1);
    layout->addWidget(board, 0, 0, 6, 0 );
    layout->addWidget(createLabel(tr("SCORE")), 2, 1);
    layout->addWidget(scoreLcd, 3, 1);
    layout->addWidget(createLabel(tr("SHIELDS")), 4, 1);
    layout->addWidget(shieldLcd, 5, 1);
    layout->addWidget(createLabel(tr("LIVES")), 6, 1);
    layout->addWidget(livesLcd, 7, 1);
    layout->addWidget(startButton, 8, 1);
    layout->addWidget(quitButton, 9, 1);
    layout->addWidget(pauseButton, 10, 1);
    setLayout(layout);

    setWindowTitle(tr("Rambod Kermanizadeh's Game"));
    resize(640, 700);
}


void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 300;
  int HEIGHT = 400;


  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
  widget.setFixedSize(WIDTH, HEIGHT);
}

QLabel *GameWindow::createLabel(const QString &text)
{
    QLabel *lbl = new QLabel(text);
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return lbl;
}
