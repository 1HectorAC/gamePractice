#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <chrono>

using namespace std::chrono;

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(int width, int height, QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);

    QTimer * shotTime;
    int width;
    int height;
    int speed;
    high_resolution_clock::time_point repeatShotTime;

public slots:

};

#endif // PLAYER_H
