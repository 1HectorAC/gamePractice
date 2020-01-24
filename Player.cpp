#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Bullet2.h"
#include "Enemy.h"
#include "Game.h"


extern Game * game;
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    // set graphic
    QImage image("images/player1.png");
    setPixmap(QPixmap::fromImage(image.scaled(200,100)));

    //setPixmap(QPixmap("player.png"));
    shotTime = new QTimer(this);
    shotTime->start(7);

}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-150,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 1500)
            setPos(x()+150,y());
    }

   //  shoot with the spacebar
    else if (event->key() == Qt::Key_Space ||
             event->key() == Qt::Key_B){

   //      create a bullet
        Bullet * bullet = new Bullet();
        bullet->setTimer(shotTime);
        bullet->setPos(x()+1,y());
        scene()->addItem(bullet);


    }
    else if (event->key() == Qt::Key_V){

   //      create a bullet
        if (game->limits->getLimit() > 0 && game->powBulletCheck != 0 ){
            Bullet2 * bullets = new Bullet2();
            bullets->setPos(x()-25,y());
            scene()->addItem(bullets);
            game->limits->decrease();
            game->powBulletCheck = 0;
            //game->health->increase();
        }

    }
}



void Player::spawn(){

    // create an enemy
    Enemy * enemy = new Enemy();
    enemy->setTimer(game->ti );
    scene()->addItem(enemy);
    int check = rand() % 4;
    if (game->score->getScore() > 50 && check == 1){
        Enemy * enemy2 = new Enemy();
        enemy2->setTimer(game->ti );
        scene()->addItem(enemy2);

    }
//    if (game->score->getScore() > 10){
//        Enemy * enemy3 = new Enemy();
//        scene()->addItem(enemy3);
//    }
   // scene()->addItem(enemy);
}
