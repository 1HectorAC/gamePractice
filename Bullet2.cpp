#include "Bullet2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include <typeinfo>

extern Game * game;

Bullet2::Bullet2(QGraphicsItem *parent)
    :QObject(), QGraphicsPixmapItem(parent){

    //Setup Image of bullet2.
    QImage image("images/threeround.png");
    setPixmap(QPixmap::fromImage(image.scaled(250,100)));
}

void Bullet2::move(){
    // Get a list of all the items currently colliding with this bullet.
    QList<QGraphicsItem *> colliding_items = collidingItems();

  // If one of the colliding items is an Enemy, destroy both the bullet and the enemy.
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // Increase the score for destroying enemy.
            game->score->increase();

            // Remove collided objects from the scene.
            scene()->removeItem(colliding_items[i]);

            // Delete them from the heap to save memory.
            delete colliding_items[i];

            // Return (all code below refers to a non existint bullet).
            return;
        }
    }
    // If there was no collision with an Enemy, move the bullet upwards.
    setPos(x(),y()-2);

    // If the bullet is off the screen, destroy it.
    if (pos().y() < 0){
        scene()->removeItem(this);
        game->powBulletCheck =1;
        delete this;
    }
}


void Bullet2::setTimer(QTimer *timers){
    connect(timers,SIGNAL(timeout()),this,SLOT(move()));
}
