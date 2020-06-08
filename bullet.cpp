#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include <typeinfo>

extern Game * game; // there is an external global object called game

Bullet::Bullet(int bulletType, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent){
    //bullet

    this->bulletType = bulletType;
    if(bulletType == 0){
        QImage image("images/singleround.png");
        setPixmap(QPixmap::fromImage(image.scaled(125,170)));
        speed = 15;
    }
    else{
        QImage image("images/threeround.png");
        setPixmap(QPixmap::fromImage(image.scaled(250,100)));
        speed = 2;
    }

}

void Bullet::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

  //   if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // increase the score
            game->score->increase2();

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            if(bulletType == 0){
                scene()->removeItem(this);
            }

            // delete them from the heap to save memory
            delete colliding_items[i];
            if(bulletType == 0){
            delete this;
            }
            // return (all code below refers to a non existint bullet)
            return;
        }
    }
    // if there was no collision with an Enemy, move the bullet forward
        setPos(x(),y()-speed);
    // if the bullet is off the screen, destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        if(bulletType == 1){
            game->powBulletCheck =1;
        }
        delete this;
    }
}

void Bullet::setTimer(QTimer *timers)
{
    connect(timers,SIGNAL(timeout()),this,SLOT(move()));
}
