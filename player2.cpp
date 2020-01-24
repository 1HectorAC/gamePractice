#include "Player2.h"




#include <QGraphicsScene>

#include <QKeyEvent>

#include "Bullet.h"

#include "Enemy.h"



Player2::Player2(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    // set bullet sound

   // bulletsound = new QMediaPlayer();

  //  bulletsound->setMedia(QUrl("qrc:/sounds/bullet.wav"));



    // set graphic

    setPixmap(QPixmap("player.png"));

}



void Player2::keyPressEvent(QKeyEvent *event){


    if (event->key() == Qt::Key_A){

        if (pos().x() > 0)

        setPos(x()-150,y());

    }

    else if (event->key() == Qt::Key_D){

        if (pos().x() + 50 < 1500)

        setPos(x()+150,y());

    }
    else if (event->key() == Qt::Key_W){

        if (pos().y() > 0)

        setPos(x(),y()-30);

    }
    else if (event->key() == Qt::Key_S){

        if (pos().y() + 33 < 1200)

        setPos(x(),y()+30);

    }

   //  shoot with the spacebar

    else if (event->key() == Qt::Key_Space){

   //      create a bullet

        Bullet * bullet = new Bullet();

        bullet->setPos(x(),y());

        scene()->addItem(bullet);

//include next part in here if add sound
      }

        // play bulletsound

//        if (bulletsound->state() == QMediaPlayer::PlayingState){

//            bulletsound->setPosition(0);

//        }

//        else if (bulletsound->state() == QMediaPlayer::StoppedState){

//            bulletsound->play();

//        }



    //}

}



void Player2::spawn(){

    // create an enemy

    Enemy * enemy = new Enemy();

    scene()->addItem(enemy);

}


