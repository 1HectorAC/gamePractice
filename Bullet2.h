#ifndef BULLET2_H
#define BULLET2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet2: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet2(QGraphicsItem * parent=0);
    void setTimer(QTimer *timers);

public slots:
    void move();
};

#endif // BULLET2_H
