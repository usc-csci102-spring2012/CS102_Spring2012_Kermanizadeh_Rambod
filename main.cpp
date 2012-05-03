/*#include <QtGui/QApplication>
#include <QDesktopWidget>
#include "game.h"


void center(QWidget &widget)
{
    int x, y;
    int screenWidth;
    int screenHeight;

    int WIDTH = 300;
    int HEIGHT = 400;

    QDesktopWidget *desktop = QApplication::desktop();

    screenWidth = desktop->width();
    screenHeight = desktop->height();\

    x = (screenWidth - WIDTH) / 2;
    y = (screenHeight - HEIGHT) / 2;

    widget.setGeometry(x, y, WIDTH, HEIGHT);
    widget.setFixedSize(WIDTH, HEIGHT);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Game window;

    window.setWindowTitle("Rambod Kermanizadeh's Game");
    window.show();
    center(window);

    return app.exec();
}*/


#include "gamewindow.h"
#include <QDesktopWidget>
#include <QApplication>


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  GameWindow window;

  //window.setWindowTitle("Breakout");
  window.show();
  //center(window);

  return app.exec();
}
