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

// Decrease Limit value if above 0 and display it.
void Limiter::decrease(){
    if (limit > 0){
        limit--;
        setPlainText(QString("Shot Limit: ") + QString::number(limit) + QString("/3"));
    }
}

// Increase Limit value if below 3 and display it.
void Limiter::increase(){
    if (limit < 3){
        limit++;
        setPlainText(QString("Shot Limit: ") + QString::number(limit) + QString("/3"));
    }
}

// Get limit value.
int Limiter::getLimit(){
    return limit;
}
