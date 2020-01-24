#include "Limiter.h"
#include <QFont>


Limiter::Limiter(QGraphicsItem *parent)
    : QGraphicsTextItem(parent)
{
    limit = 3;
    setPlainText(QString("Shot Limit: ") + QString::number(limit) + QString("/3"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Limiter::decrease(){
    if (limit > 0){
        limit--;
        setPlainText(QString("Shot Limit: ") + QString::number(limit) + QString("/3"));
    }
}
void Limiter::increase(){
    if (limit < 3){
        limit++;
        setPlainText(QString("Shot Limit: ") + QString::number(limit) + QString("/3"));
    }
}

int Limiter::getLimit(){
    return limit;
}
