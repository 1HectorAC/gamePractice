#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
//#include <QMediaPlayer>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(int width, int height, QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    QTimer * shotTime;

    int width;
    int height;
public slots:
    void spawn();
//private:

//    QMediaPlayer * bulletsound;

};



#endif // PLAYER_H
