#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>

extern Game * game;

Bullet::Bullet(int bulletType, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent){

    // Setup type of bullet used, normal(0) or slow big(1).
    this->bulletType = bulletType;

    // Setup speed and image of bullet based on type.
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
    // Get a list of all the items currently colliding with this bullet.
    QList<QGraphicsItem *> colliding_items = collidingItems();

  // If one of the colliding items is an Enemy act accordingly (destroy enemy and maybe bullet depending on type)
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // Increase the score.
            game->score->increase2();



            // Remove and delete collided item.
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];

            // Remove and delete bullet if a certain bullet type.
            if(bulletType == 0){
                scene()->removeItem(this);
                delete this;
            }

            return;
        }
    }

    // If there was no collision with an Enemy, move the bullet forward
        setPos(x(),y()-speed);

    // If the bullet is off the screen, destroy it.
    if (pos().y() < 0){
        scene()->removeItem(this);

        // Increase powBulletCheck depending on the bulletType.
        if(bulletType == 1){
            game->powBulletCheck =1;
        }
        delete this;
    }
}

// Add movement timer.
void Bullet::setTimer(QTimer *timers){
    connect(timers,SIGNAL(timeout()),this,SLOT(move()));
}
