#include "Enemy.h"
#include <stdlib.h>
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = rand() % game->screenWidth - 50;
    setPos(random_number,0);

    // drew the rect and sizes it
        QImage images("images/rock.png");
        setPixmap(QPixmap::fromImage(images.scaled(100,100)));
    setTransformOriginPoint(50,50);

    //set random direction
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

void Enemy::setTimer(QTimer *timers)
{
    connect(timers,SIGNAL(timeout()),this,SLOT(move()));
}


void Enemy::move(){
    if (pos().x() > game->screenWidth && pos().y() < 500){
        setPos(0,y());
    }
    if (pos().x() < 0 && pos().y() < 500){
        setPos(game->screenWidth,y());
    }
    // move enemy down
        setPos(x()-direction,y()+3);

    // destroy enemy when it goes out of the screen
    if (pos().y() > game->screenHeight -100){

        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;

    }

}

