#ifndef PLAYER2_H
#define PLAYER2_H


#include <QGraphicsPixmapItem>

#include <QObject>

#include <QGraphicsItem>

//#include <QMediaPlayer>



class Player2:public QObject, public QGraphicsPixmapItem{

    Q_OBJECT

public:

    Player2(QGraphicsItem * parent=0);

    void keyPressEvent(QKeyEvent * event);

public slots:

    void spawn();

//private:

//    QMediaPlayer * bulletsound;

};


#endif // PLAYER2_H
