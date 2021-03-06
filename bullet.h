#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(int bulletType, QGraphicsItem * parent=0);
    void setTimer(QTimer *timers);

    int speed;
    int bulletType;
public slots:
    void move();

};

#endif // BULLET_H
