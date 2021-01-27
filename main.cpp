#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "ship.h"
#include <qtimer.h>
#include "game.h"
#include <QDebug>
#include "mainMenu.h"
#include "gameOver.h"


MainMenu* mainMenu;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainMenu = new MainMenu();
    mainMenu->show();
    mainMenu->displayMainMenu();


    return a.exec();
}
