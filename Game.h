#ifndef GAME_H

#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Limiter.h"
#include <QMediaPlayer>
#include <QTimer>

class Game: public QGraphicsView{
    Q_OBJECT
public:
// changed 0 to null
    Game(QWidget * parent=NULL);
 //////////////////////

    void displayMainMenu();
    void displayGameOverWindow(QString textToDisplay, QString scores);
  ///////////////////////////////////////
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    Limiter * limits;
    QMediaPlayer * beginMusic;
    QTimer * ti;
    QTimer * timer;

    int screenHeight;
    int screenWidth;
    int check1;
    int powBulletCheck;
    ///////////////////////////
public slots:
    void start();
    void restartGame();
    void gameOver();
    //void setGameSizeScreen();

    ////////////////////////////////////

private:
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
};
#endif // GAME_H
