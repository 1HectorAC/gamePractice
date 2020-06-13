#include "EnemyManager.h"
#include "Enemy.h"
#include "Game.h"
#include <QGraphicsScene>


extern Game * game;

EnemyManager::EnemyManager(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // Setup enemySpawnTimer.
    enemySpawnTimer = new QTimer();
    enemySpawnTimer->start(1800);

    //Setup enemyMoveTimer.
    enemyMoveTimer = new QTimer();
    enemyMoveTimer->start(7);

    QObject::connect(enemySpawnTimer,SIGNAL(timeout()),this,SLOT(spawn()));

}

void EnemyManager::spawn(){

    // Create an enemy.
    Enemy * enemy = new Enemy(108);
    enemy->setTimer(enemyMoveTimer);
    scene()->addItem(enemy);

    // Adjust chance of more enemies spawn and spawn speed based on current score.
    int score = game->score->getScore();
    if(score > 60){
        enemySpawnTimer->setInterval(500);
        int check = rand() % 4;
        // Make more enemies when reach a certain score.
        if (check < 3){
            Enemy * enemy2 = new Enemy(108);
            enemy2->setTimer(enemyMoveTimer );
            scene()->addItem(enemy2);
        }
    }
    else if(score > 40){
        enemySpawnTimer->setInterval(800);
        int check = rand() % 4;
        // Make more enemies when reach a certain score.
        if (check < 2){
            Enemy * enemy2 = new Enemy(108);
            enemy2->setTimer(enemyMoveTimer );
            scene()->addItem(enemy2);
        }
    }
    else if(score > 20){
        enemySpawnTimer->setInterval(1300);
        int check = rand() % 4;
        // Make more enemies when reach a certain score.
        if (check < 1){
            Enemy * enemy2 = new Enemy(108);
            enemy2->setTimer(enemyMoveTimer );
            scene()->addItem(enemy2);
        }
    }

}
