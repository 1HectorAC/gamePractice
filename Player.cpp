#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QGraphicsScene>
#include <QKeyEvent>

extern Game * game;
Player::Player(int width, int height, QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    this->width = width;
    this->height = height;
    // Set player graphic.
    QImage image("images/player1.png");
    setPixmap(QPixmap::fromImage(image.scaled(width, height)));

    // Setup timer for shots.
    shotTime = new QTimer(this);
    shotTime->start(7);

}

void Player::keyPressEvent(QKeyEvent *event){
    // Move left if x position not past left boundary.
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-(height * 1.4),y());
    }
    // Move right if x position not past right boundary.
    else if (event->key() == Qt::Key_Right){
        if (pos().x() < game->screenWidth - (height * 2.8))
            setPos(x()+(height * 1.4) ,y());
    }

   // Shoot bullet.
    else if (event->key() == Qt::Key_Space ||
             event->key() == Qt::Key_B){

   // Create a bullet.
        Bullet * bullet = new Bullet(0);
        bullet->setTimer(shotTime);
        // Adjust position to be at the center of player.
        bullet->setPos(x()+height/2.2,y());
        scene()->addItem(bullet);


    }
    //Shot a stronger bullet.
    else if (event->key() == Qt::Key_V){
        // Check if player has a strong shot with the limits count and if one is already on screen with powBulletCheck before firing.
        if (game->limits->getLimit() > 0 && game->powBulletCheck != 0 ){
            Bullet * bullets = new Bullet(1);
            bullets->setTimer(shotTime);
            // Adjust position to be at the center of player.
            bullets->setPos(x()-height/4,y());
            scene()->addItem(bullets);
            game->limits->decrease();
            game->powBulletCheck = 0;
        }
    }
}



void Player::spawn(){

    // Create an enemy.
    Enemy * enemy = new Enemy(height);
    enemy->setTimer(game->ti );
    scene()->addItem(enemy);
    int check = rand() % 4;
    // Make more enemies when reach a certain score.
    if (game->score->getScore() > 50 && check == 1){
        Enemy * enemy2 = new Enemy(height);
        enemy2->setTimer(game->ti );
        scene()->addItem(enemy2);

    }

}
