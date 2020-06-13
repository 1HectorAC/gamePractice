#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class EnemyManager: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    EnemyManager(QGraphicsItem * parent=0);
    QTimer * enemySpawnTimer;
    QTimer * enemyMoveTimer;
public slots:
    void spawn();


};


#endif // ENEMYMANAGER_H
