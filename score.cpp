#include "Score.h"
#include "Game.h"
#include <QFont>

extern Game * game;
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Initialize the score to 0.
    score = 0;

    // Draw the score text.
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

// Increase Score by one.
void Score::increase(){
    score++;

    // Increase limiter value after a cetain amount of points earned in score.
    if (score % 30 == 1){
        game->limits->increase();
    }

    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

// Increase Score by three.
void Score::increase2(){
    score+=3;

    // Increase limiter value after a cetain amount of points earned in score.
    if (score % 10 == 1){
        game->limits->increase();
    }

    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

// Get Score.
int Score::getScore(){
    return score;
}
