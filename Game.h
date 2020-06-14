#ifndef GAME_H

#define GAME_H


#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Limiter.h"
#include "EnemyManager.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=NULL);
 //////////////////////

    void displayMainMenu();
    void displayGameOverWindow(int totalScore);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    Limiter * limits;
    EnemyManager * enemyManager;
    QMediaPlayer * beginMusic;
    QTimer * gameOverTimer;

    int screenHeight;
    int screenWidth;
    int powBulletCheck;
public slots:
    void start();
    void restartGame();
    void gameOver();

private:
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
};
#endif // GAME_H
