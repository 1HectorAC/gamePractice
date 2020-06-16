#include "EnemyManager.h"
#include "Enemy.h"
#include "Game.h"
#include <QGraphicsScene>

extern Game * game;

EnemyManager::EnemyManager(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // Setup enemySpawnTimer.
    enemySpawnTimer = new QTimer();
    enemySpawnTimer->start(1900);

    //Setup enemyMoveTimer.
    enemyMoveTimer = new QTimer();
    enemyMoveTimer->start(10);

    QObject::connect(enemySpawnTimer,SIGNAL(timeout()),this,SLOT(spawn()));

}

void EnemyManager::spawn(){
    // Create an enemy.
    addEnemy();

    // Adjust chance of more enemies spawning and spawn speed based on current score.
    int score = game->score->getScore();
    if(score > 60){
        enemySpawnTimer->setInterval(700);
        int check = rand() % 4;
        // Three in four change to add extra enemy.
        if (check < 3){
            addEnemy();
        }
    }
    else if(score > 40){
        enemySpawnTimer->setInterval(900);
        int check = rand() % 4;
        // One in two change to add extra enemy.
        if (check < 2){
            addEnemy();
        }
    }
    else if(score > 20){
        enemySpawnTimer->setInterval(1400);
        int check = rand() % 4;
        // One in four change to add extra enemy.
        if (check < 1){
            addEnemy();
        }
    }
}

// Add an enemy to the scene.
void EnemyManager::addEnemy(){
    Enemy * enemy = new Enemy(108);
    enemy->setTimer(enemyMoveTimer );
    scene()->addItem(enemy);
}
