#include "Enemy.h"
#include <stdlib.h>
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <cmath>

extern Game * game;

Enemy::Enemy(int length, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    this->length = length;

    // Set position to random in x axis and 0 in y.
    int random_number = rand() % game->screenWidth - round(length / 2);
    setPos(random_number,0);

    // Draw the enemy and set origin point to center of object
    QImage images("images/rock.png");
    setPixmap(QPixmap::fromImage(images.scaled(length,length)));
    setTransformOriginPoint(length/2,length/2);

    // Randomly set direction (just by 30 degrees).
    int randDir = rand() % 5;
    if (randDir == 1){
        direction = 3;
        setRotation(30);
    }
    else if (randDir == 2){
        direction = -3;
        setRotation(-30);
    }
    else{
        direction = 0;
        setRotation(0);
    }
}

void Enemy::move(){
    // Check if it crosses right boundary and circle back around the other side if not below a certain point.
    if (pos().x() > game->screenWidth && pos().y() < game->screenHeight / 2){
        setPos(0,y());
    }
    // Check if it crosses left boundary and circle back around the other side if not below a certain point.
    else if (pos().x() < 0 && pos().y() < game->screenHeight /2){
        setPos(game->screenWidth,y());
    }

    // Move enemy down the screen. Also move horizontaly depending if it has a direction value other than 0.
    setPos(x()-direction,y()+3);

    // Destroy enemy when it goes out of the screen in the bottom.
    if (pos().y() > game->screenHeight -length){
        //Decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}

// Add timer to call move.
void Enemy::setTimer(QTimer *timers){
    connect(timers,SIGNAL(timeout()),this,SLOT(move()));
}
