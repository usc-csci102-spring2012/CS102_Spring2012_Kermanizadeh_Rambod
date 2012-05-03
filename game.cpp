#include "game.h"
#include <QPainter>
#include <QApplication>
#include <stdlib.h>



Game::Game(QWidget * parent) : QWidget (parent)
{
    x = 0;
    gameOver = false;
    gameWon = false;
    paused = false;
    gameStarted = false;
    score = 0;
    lives = 3;
    shield = 3;
    level = 1;

    paddle = new Paddle();

    spawnEnemies();
}

Game::~Game()
{
    delete paddle;
    for (int i = 0; i < enemyVec.size(); i++){
        delete enemyVec[i];
    }
}

void Game::playerShoot()
{
    Bullet bulletOne(false, false, paddle->getRect().x(), paddle->getRect().y());
    bulletVec.push_back(bulletOne);
}

void Game::enemyDrop(int x, int y)
{
    int dropOrNotDrop = rand() % 100;

    if(dropOrNotDrop >= 0 && dropOrNotDrop <= 5){
        //ShieldDrop temp(x, y);
        dropVec.push_back(new ShieldDrop(x, y));
    }

    if(dropOrNotDrop >= 6 && dropOrNotDrop <= 11){
        //OneUpDrop temp(x, y);
        dropVec.push_back(new OneUpDrop(x, y));
    }

    if(dropOrNotDrop >= 12 && dropOrNotDrop <= 22){
        //MoneyDrop temp(x, y);
        dropVec.push_back(new MoneyDrop(x, y));
    }

    if(dropOrNotDrop >= 23 && dropOrNotDrop <= 24){
        dropVec.push_back(new SlowDrop(x, y));
    }
}

void Game::spawnFloaters()
{
    int spawnOrNotSpawn = rand() % 100;

    if(spawnOrNotSpawn >= 7 && spawnOrNotSpawn <= 9){
        int xPos = rand() % 300;

        if(spawnOrNotSpawn == 7 || spawnOrNotSpawn == 9){
            floaterVec.push_back(new Debris(xPos, 0));
        }

        if(spawnOrNotSpawn == 8){
            floaterVec.push_back(new SpaceMine(xPos, 0));
        }
    }
}

void Game::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if(gameOver){
        QFont font ("Courier", 15, QFont::DemiBold);
        QFontMetrics fm(font);
        int textWidth = fm.width("Game Over");

        painter.setFont(font);
        int h = height();
        int w = width();

        painter.translate(QPoint(w/2, h/2));
        painter.drawText(-textWidth/2, 0, "Game Over");
    }
    else if(gameWon) {
        QFont font("Courier", 15, QFont::DemiBold);
        QFontMetrics fm(font);
        int textWidth = fm.width("Victory");

        painter.setFont(font);
        int h = height();
        int w = width();

        painter.translate(QPoint(w/2, h/2));
        painter.drawText(-textWidth/2, 0, "Victory");
    }

    else if(finishedGame){
        QFont font("Courier", 15, QFont::DemiBold);
        QFontMetrics fm(font);
        int textWidth = fm.width("Victory\nThat is all three levels, you\ncan play again from level one\nkeeping your score");

        painter.setFont(font);
        int h = height();
        int w = width();

        painter.translate(QPoint(w/2, h/2));
        painter.drawText(-textWidth/2, 0, "Victory");
    }

    else {
        painter.drawImage(paddle->getRect(), paddle->getImage());

        for (int i=0; i<enemyVec.size(); i++) {
            if (!enemyVec[i]->isDestroyed())
              painter.drawImage(enemyVec[i]->getRect(), enemyVec[i]->getImage());
        }

        for(int i = 0; i < bulletVec.size(); i++){
            if(!bulletVec[i].isDestroyed()){
                painter.drawImage(bulletVec[i].getRect(), bulletVec[i].getImage());
            }
        }

        for(int i = 0; i < enemyBulletVec.size(); i++){
            if(!enemyBulletVec[i].isDestroyed())
                painter.drawImage(enemyBulletVec[i].getRect(), enemyBulletVec[i].getImage());
        }

        for(int i = 0; i < dropVec.size(); i++){
            if(!dropVec[i]->isDestroyed())
                painter.drawImage(dropVec[i]->getRect(), dropVec[i]->getImage());
        }

        for(int i = 0; i < floaterVec.size(); i++){
            if(!floaterVec[i]->isDestroyed())
                painter.drawImage(floaterVec[i]->getRect(), floaterVec[i]->getImage());
        }
    }
}

void Game::timerEvent(QTimerEvent *event)
{

    for(int i = 0; i < bulletVec.size(); i++){
        bulletVec[i].autoMove(level);
    }

    for(int i = 0; i < enemyBulletVec.size(); i++){
        enemyBulletVec[i].autoMove(level);
    }

    for(int i = 0; i < enemyVec.size(); i++){
        enemyVec[i]->autoMove(level);

        if(enemyVec[i]->tracker){
            enemyVec[i]->setDir(paddle->getRect().x());
        }
    }

    for(int i = 0; i < dropVec.size(); i++){
        dropVec[i]->autoMove();
    }

    for(int i = 0; i < floaterVec.size(); i++){
        floaterVec[i]->autoMove(level);
    }

    spawnFloaters();

    checkCollision();
    repaint();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Left:
        {
            int x = paddle->getRect().x();
            for(int i = 1; i <= 5; i++)
                paddle->moveLeft(x--);
        }
        break;
    case Qt::Key_Right:
        {
            int x = paddle->getRect().x();
            for(int i = 1; i <= 5; i++)
                paddle->moveRight(x++);
        }
        break;
    case Qt::Key_P:
        {
            pauseGame();
        }
        break;
    case Qt::Key_W:
        playerShoot();
        break;
    case Qt::Key_Space:
        {
            startGame();
        }
        break;
    case Qt::Key_Escape:
        qApp->exit();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void Game::startGame()
{
    if (!gameStarted){
        paddle->resetState();

        //for(int i = 0; i < 12; i++){
        //    enemyVec[i]->setDestroyed(false);
        //}

        spawnEnemies();

        for(int i = 0; i < bulletVec.size(); i++){
            bulletVec[i].setDestroyed(true);
        }

        for(int i = 0; i < enemyBulletVec.size(); i++){
            enemyBulletVec[i].setDestroyed(true);
        }

        for(int i = 0; i < dropVec.size(); i++){
            dropVec[i]->setDestroyed(true);
        }

        for(int i = 0; i < floaterVec.size(); i++){
            floaterVec[i]->setDestroyed(true);
        }

        paddle->setDestroyed(false);
        paddle->setShield(3);
        shield = paddle->getShield();

        gameOver = false;
        gameWon = false;
        gameStarted = true;
        finishedGame = false;
        timerId = startTimer(20);
        emit scoreChanged(score);
        emit levelChanged(level);
        emit livesChanged(lives);
        emit shieldChanged(shield);
    }
}

void Game::pauseGame()
{
    if(paused){
        timerId = startTimer(20);
        paused = false;
    }
    else{
        paused = true;
        killTimer(timerId);
    }
}

void Game::stopGame()
{
    killTimer(timerId);
    gameOver = true;
    gameStarted = false;
    score=0;
    level=1;
    lives = 3;

    //for(i = 0; i < enemyVec.size(); i++){
    QVector<Brick*>::iterator it;
    for(it = enemyVec.begin(); it != enemyVec.end(); ){
        delete * it;
        it = enemyVec.erase(it);
    }
}

void Game::victory()
{
    killTimer(timerId);
    gameWon = true;
    gameStarted = false;
    score += 1000;
    emit scoreChanged(score);
    if(level < 3)
        level++;
    else{
        finishedGame = true;
        level = 1;
        emit levelChanged(level);
    }

    QVector<Brick*>::iterator it;
    for(it = enemyVec.begin(); it != enemyVec.end(); ){
        delete * it;
        it = enemyVec.erase(it);
    }
}

void Game::checkCollision()
{

    if(paddle->isDestroyed())
        stopGame();

    for(int i = 0, j = 0; i < enemyVec.size(); i++){
        if(enemyVec[i]->isDestroyed()){
            j++;
        }
        if (j == enemyVec.size())
            victory();
    }


    for(int i = 0; i < bulletVec.size(); i++){
        for(int j = 0; j < enemyVec.size(); j++){
            if(!enemyVec[j]->isDestroyed()){
                if(!bulletVec[i].isDestroyed()){
                    if((bulletVec[i].getRect()).intersects(enemyVec[j]->getRect())){
                        --(enemyVec[j]->hp);
                        if(enemyVec[j]->hp <= 0){
                            enemyDrop(enemyVec[j]->getRect().x() + 10, enemyVec[j]->getRect().y());
                            enemyVec[j]->setDestroyed(true);
                            //bulletVec.erase(bulletVec.begin() + i);
                            bulletVec[i].setDestroyed(true);
                            score += 200 * level;
                            emit scoreChanged(score);
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < enemyBulletVec.size(); i++){
        if(!enemyBulletVec[i].isDestroyed()){
            if((enemyBulletVec[i].getRect()).intersects(paddle->getRect())){
                lowerShields();
                //paddle->setDestroyed(true);
                enemyBulletVec[i].setDestroyed(true);
            }
        }
    }

    for(int i = 0; i < dropVec.size(); i++){
        if(!dropVec[i]->isDestroyed()){
            if((dropVec[i]->getRect()).intersects(paddle->getRect())){
                dropVec[i]->pickedUp();
                if(dropVec[i]->isMoney == true){
                    score +=100;
                    emit scoreChanged(score);
                }
                if(dropVec[i]->isOneUp == true){
                    score += 50;
                    emit scoreChanged(score);
                    lives++;
                    emit livesChanged(lives);
                }
                if(dropVec[i]->isShield == true){
                    score +=25;
                    emit scoreChanged(score);
                    paddle->setShield(3);
                    shield = paddle->getShield();
                    emit shieldChanged(shield);
                }

                if(dropVec[i]->isShield == false && dropVec[i]->isOneUp == false && dropVec[i]->isMoney == false){
                    score +=125;
                    emit scoreChanged(score);
                    timerId = startTimer(30);
                }
                dropVec[i]->setDestroyed(true);
            }
        }
    }

    for(int i = 0; i < floaterVec.size(); i++){
        if(!floaterVec[i]->isDestroyed()){
            if((floaterVec[i]->getRect()).intersects(paddle->getRect())){
                floaterVec[i]->hit();
                if(floaterVec[i]->isMine == true){
                    lowerShields();
                }
                floaterVec[i]->setDestroyed(true);
            }
        }
    }

    for(int i = 0; i < enemyVec.size(); i++){
        if(!enemyVec[i]->isDestroyed()){
            if(enemyVec[i]->getRect().x() == paddle->getRect().x()){
                Bullet bulletOne(true, false, enemyVec[i]->getRect().x(), enemyVec[i]->getRect().y());
                enemyBulletVec.push_back(bulletOne);
            }
        }
    }
}

void Game::changeScore(int x)
{
    score += x;
}

int Game::getScore()
{
    return score;
}

void Game::changeLives(int x)
{
    lives += x;
}

int Game::getLives()
{
    return lives;
}

void Game::lowerShields()
{
    paddle->changeShield(-1);
    shield = paddle->getShield();
    emit shieldChanged(shield);
    if(shield <= 0){
        lives--;
        paddle->changeShield(3);
        shield = paddle->getShield();
        emit shieldChanged(shield);
        emit livesChanged(lives);

        if(lives <= 0){
            stopGame();
            lives = 0;
            emit livesChanged(lives);
        }
    }
}

void Game::spawnEnemies()
{
    switch(level){

    case 1:
        {
            //int k = 0;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 5; j++) {
                    //bricks[k] = new Brick(j*40+30, i*10+50);
                    //BasicEnemy *tempEnemy = new BasicEnemy(j*40+30, i*10+50);
                    //DiagEnemy *tempEnemy = new DiagEnemy(j*40+30, j*10+50);
                    //TrackerEnemy *tempEnemy = new TrackerEnemy(0,0);
                    //enemyVec[k] = tempEnemy;
                    enemyVec.push_back(new BasicEnemy(j*40+30, i*10+50));
                    //k++;
                }
            }
        }
      break;

    case 2:
        {
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 5; j++){
                    enemyVec.push_back(new DiagEnemy(j*40+30, j*10+50));
                }
            }
        }
        break;

    case 3:
        {
            for(int i = 0; i < 2; i++){
                enemyVec.push_back(new TrackerEnemy(i * 240 + 30, 50));
            }

            enemyVec.push_back(new BossEnemy(150, 50));
        }
        break;
    }
}

