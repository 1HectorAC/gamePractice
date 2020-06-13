#include "Game.h"
#include "Enemy.h"
#include "Button.h"
#include "score.h"
#include "Limiter.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QtMultimedia/QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <random>

using namespace std;
Game::Game(QWidget *parent){

    // Create the scene.
    scene = new QGraphicsScene();
    screenWidth = 1920;
    screenHeight = 1080;

    scene->setSceneRect(0,0,screenWidth,screenHeight);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(screenWidth,screenHeight);

}

void Game::start(){
    // Clear the screen. Need to do for restarting a game.
    scene->clear();
    powBulletCheck =1;

    // Set background image.
    QImage stuff("images/background1.png");
    setBackgroundBrush(QBrush(stuff.scaled(screenWidth,screenHeight)));

    // Create the player.
    player = new Player(screenHeight / 10 * 2, screenHeight / 10);
    // Position set to bottom center of screen.
    player->setPos(screenWidth/2 - (screenHeight/ 10), screenHeight - (screenHeight/10));
    // Make the player focusable and set it to be the current focus.
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Add the player to the scene.
    scene->addItem(player);

    // Add score to scene.
    score = new Score();
    scene->addItem(score);

    //Add health to scene.
    health = new Health();
    health->setPos(health->x(),health->y()+40);
    scene->addItem(health);

    //Add limit to scene.
    limits = new Limiter();
    limits->setPos(limits->x(),limits->y()+80);
    scene->addItem(limits);

    // Add enemyManager to manage enemies spawned.
    enemyManager = new EnemyManager();
    scene->addItem(enemyManager);

    // Game over check.
    ti = new QTimer();
    QObject::connect(ti,SIGNAL(timeout()),this,SLOT(gameOver()));
    ti->start(10);

    // Play background music.
    beginMusic->setMedia(QUrl::fromLocalFile("music/basic.mp3"));
    beginMusic->play();
    show();

}
void Game::restartGame(){
    scene->clear();
    start();
}
void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    // Draws a panel at the specified location with the specified properties.
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}


void Game::displayMainMenu(){
    scene->clear();
    // Create the title text.
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Falling Rock Destroyer"));
    QColor titleColors("White");
    titleText->setDefaultTextColor(titleColors);
    QFont titleFont("comic sans",30);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 300;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // Create the author.
    QGraphicsTextItem* titleTexts = new QGraphicsTextItem(QString("By H&A inc."));
    QColor titleColor("White");
    titleTexts->setDefaultTextColor(titleColor);
    QFont titleFonts("comic sans",15);
    titleTexts->setFont(titleFonts);
    int txPoss = this->width()/2 - titleTexts->boundingRect().width()/2;
    int tyPoss = 390;
    titleTexts->setPos(txPoss,tyPoss);
    scene->addItem(titleTexts);


    // Create the play button.
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 600;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // Create the quit button.
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 800;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

    // Begining start music.
    beginMusic = new QMediaPlayer();
    beginMusic->setMedia(QUrl::fromLocalFile("music/intro.mp3"));
    beginMusic->setVolume(60);
    beginMusic->play();

    // Set background image.
    QImage stuff("images/startmenu.png");
    setBackgroundBrush(QBrush(stuff.scaled(screenWidth,screenHeight)));
}


void Game::gameOver(){
    //Check if health is down to 0 or below and display game over.
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
    // Disable all scene items.
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
        scene->items()[i]->setEnabled(false);
    }

    // Pop up semi transparent panel.
    drawPanel(0,0,screenWidth,screenHeight,Qt::black,0.65);

    // Draw panel.
    drawPanel(400,300,screenWidth/2,screenHeight/2,Qt::lightGray,0.75);

    // Create playAgain button.
    Button* playAgain = new Button(QString("Play Again"));
    playAgain->setPos(600,500);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    // Create quit button.
    Button* quit = new Button(QString("Quit"));
    quit->setPos(600,700);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    QGraphicsTextItem* overText = new QGraphicsTextItem(textToDisplay);
    overText->setPos(630,350);
    QFont titleFont("comic sans",18);
    overText->setFont(titleFont);
    scene->addItem(overText);

    // Report score.
    QGraphicsTextItem* displayScore = new QGraphicsTextItem(scores);
    displayScore->setPos(630,400);
    displayScore->setFont(titleFont);
    scene->addItem(displayScore);

}
