#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(int length, QGraphicsItem * parent=0);
    void setTimer(QTimer  *timers);
private:
    int direction;
    int length;
public slots:
    void move();

};


#endif // ENEMY_H
