#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <chrono>

using namespace std::chrono;
extern Game * game;
Player::Player(int width, int height, QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    this->width = width;
    this->height = height;
    // Set player graphic.
    QImage image("images/player1.png");
    setPixmap(QPixmap::fromImage(image.scaled(width, height)));

    // Setup timer for shots.
    shotTime = new QTimer(this);
    shotTime->start(10);

    speed = 90;
    repeatShotTime = high_resolution_clock::now();

}

void Player::keyPressEvent(QKeyEvent *event){
    //Increase speed when key is held down.
    if(event->isAutoRepeat()){
        if(speed <= 150)
            speed+= 10;
    }
    else{
        speed = 90;
    }
    // Move left if x position not past left boundary.
    if (event->key() == Qt::Key_Left){
        if (pos().x() - speed > 0 - width / 2)
            setPos(x()-speed,y());

    }
    // Move right if x position not past right boundary.
    else if (event->key() == Qt::Key_Right){
        if (pos().x()+ speed < game->screenWidth - (width /2))
            setPos(x()+speed ,y());

    }

    // Shoot bullet.
    else if ((event->key() == Qt::Key_Space ||
             event->key() == Qt::Key_B) && !event->isAutoRepeat() ){

        // Check to make sure key can only be clicked every 200 milliseconds.
        auto timeNow = high_resolution_clock::now();
        if(duration_cast<milliseconds>(timeNow - repeatShotTime).count() >= 200){
            // Create a bullet.
            Bullet * bullet = new Bullet(0);
            bullet->setTimer(shotTime);
            // Adjust position to be at the center of player.
            bullet->setPos(x()+height/2.2,y());
            scene()->addItem(bullet);
            repeatShotTime = high_resolution_clock::now();
        }
    }
    // Shot a stronger bullet.
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



