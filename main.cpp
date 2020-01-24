#include <QApplication>
#include "Game.h"
#include "random"
#include "ctime"
Game * game;

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    srand(time(0));
    game = new Game();
    game->setWindowTitle("Game of Games...stuff...more stuff");

    //game->setWindowIcon(QIcon("icon.png"));
    game->show();
    game->displayMainMenu();
    return a.exec();

}
