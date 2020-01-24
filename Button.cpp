#include "Button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>
Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rect
    setRect(0,0,300,100);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    brush.setColor(Qt::darkCyan);
//    brush.setColor(Qt::darkRed);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);

    QFont titleFont("comic sans",18);
    text->setFont(titleFont);

    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);


    // allow responding to hover events
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    // change color to cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    // change color to dark cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
