#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent)
    : QGraphicsTextItem(parent){
    health = 10;

    // Draw text of health.
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

// Decrease health by 1 and update text of health.
void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
}

// Increase health by 1 and update text of health.
void Health::increase(){
    health+=1;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
}

// Get health.
int Health::getHealth(){
    return health;
}
