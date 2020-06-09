#include "Button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // Draw the rectangle.
    setRect(0,0,300,100);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    // Draw the text.
    text = new QGraphicsTextItem(name,this);

    QFont titleFont("comic sans",18);
    text->setFont(titleFont);

    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);


    // Allow responding to hover events.
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    //Cchange color to cyan.
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    // Change color to dark cyan.
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
