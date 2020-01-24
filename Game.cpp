#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QtMultimedia/QMediaPlayer>
#include "Button.h"
#include <QBrush>
#include <QImage>
#include <score.h>
#include "Limiter.h"
#include <random>

using namespace std;
Game::Game(QWidget *parent){

    // create the scene
    scene = new QGraphicsScene();
    screenWidth = 1500;
    screenHeight = 1200;


    scene->setSceneRect(0,0,screenWidth,screenHeight);

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(screenWidth,screenHeight);

}

void Game::start(){
    // clear the screen
    scene->clear();
    check1 = 2;
    powBulletCheck =1;
    //set background image with resize
    QImage stuff("images/background1.png");
    setBackgroundBrush(QBrush(stuff.scaled(screenWidth,screenHeight)));
    // create the player
    player = new Player();
    player->setPos(screenWidth/2 - 100, screenHeight - 100); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(),health->y()+40);
    scene->addItem(health);

    limits = new Limiter();
    limits->setPos(limits->x(),limits->y()+80);
    scene->addItem(limits);

    // spawn enemies
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(3500);

//enemy 2
    QTimer * time = new QTimer();
    QObject::connect(time,SIGNAL(timeout()),player,SLOT(spawn()));
    time->start(3000);

//    QTimer * tim = new QTimer();
//    QObject::connect(tim,SIGNAL(timeout()),player,SLOT(spawn()));
//    tim->start(400);
// game over check
    ti = new QTimer();
    QObject::connect(ti,SIGNAL(timeout()),this,SLOT(gameOver()));
    ti->start(10);
    // play background music
     beginMusic->setMedia(QUrl::fromLocalFile("music/basic.mp3"));
     beginMusic->play();
    show();

}
void Game::restartGame(){
    scene->clear();
    start();
}
void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}
void Game::displayMainMenu(){
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Magical Destruction Force MKZ  XVII"));
    QFont titleFont("comic sans",30);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 300;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the author
    QGraphicsTextItem* titleTexts = new QGraphicsTextItem(QString("By H&A inc."));
    QFont titleFonts("comic sans",15);
    titleTexts->setFont(titleFonts);
    int txPoss = this->width()/2 - titleTexts->boundingRect().width()/2;
    int tyPoss = 390;
    titleTexts->setPos(txPoss,tyPoss);
    scene->addItem(titleTexts);


    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 600;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 800;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
    //begining start music
    beginMusic = new QMediaPlayer();
    //Roku
    beginMusic->setMedia(QUrl::fromLocalFile("music/intro.mp3"));
    beginMusic->setVolume(60);
    beginMusic->play();

    QImage stuff("images/startmenu.png");
    setBackgroundBrush(QBrush(stuff.scaled(screenWidth,screenHeight)));

}
void Game::gameOver(){
    if(check1 == 2 && score->getScore() > 20){
        QTimer * time = new QTimer();
        QObject::connect(time,SIGNAL(timeout()),player,SLOT(spawn()));
        time->start(1000);
        check1--;
    }
    if(check1 == 1 && score->getScore() > 30){
        QTimer * tim = new QTimer();
        QObject::connect(tim,SIGNAL(timeout()),player,SLOT(spawn()));
        tim->start(1800);
        check1--;
    }
    if (health->getHealth() <= 0){
        QString messege;
        QString scores;
        ti->stop();
        scores = QString("Total Score: ")+QString::number(score->getScore());
        messege = "Game Over";
        scene->clear();
        displayGameOverWindow(messege, scores);
        beginMusic->setMedia(QUrl::fromLocalFile("music/gameOver.mp3"));
        beginMusic->play();

    }


}
void Game::displayGameOverWindow(QString textToDisplay, QString scores){
    // disable all scene items
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
        scene->items()[i]->setEnabled(false);
    }

    // pop up semi transparent panel
    drawPanel(0,0,screenWidth,screenHeight,Qt::black,0.65);

    // draw panel
    drawPanel(400,300,screenWidth/2,screenHeight/2,Qt::lightGray,0.75);

    // create playAgain button
    Button* playAgain = new Button(QString("Play Again"));
    playAgain->setPos(600,500);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    // create quit button
    Button* quit = new Button(QString("Quit"));
    quit->setPos(600,700);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    QGraphicsTextItem* overText = new QGraphicsTextItem(textToDisplay);
    overText->setPos(630,350);
    QFont titleFont("comic sans",18);
    overText->setFont(titleFont);
    scene->addItem(overText);

    //report score
    QGraphicsTextItem* displayScore = new QGraphicsTextItem(scores);
    displayScore->setPos(630,400);
    displayScore->setFont(titleFont);
    scene->addItem(displayScore);

}
