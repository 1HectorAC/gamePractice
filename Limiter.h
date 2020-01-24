#ifndef LIMITER_H
#define LIMITER_H

#include <QGraphicsTextItem>

class Limiter: public QGraphicsTextItem{
public:
    Limiter(QGraphicsItem * parent=0);
    void decrease();
    void increase();
    int getLimit();
private:
    int limit;
};
#endif // LIMITER_H
