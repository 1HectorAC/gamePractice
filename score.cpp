#include "Score.h"
#include <QFont>
#include "Game.h"
extern Game * game;
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    if (score % 30 == 1){
        game->limits->increase();
    }

    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

void Score::increase2(){
    score+=3;
    if (score % 10 == 1){
        game->limits->increase();
    }

    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

int Score::getScore(){
    return score;
}
