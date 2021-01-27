#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsView>
#include "highscore.h"
#include "achievement.h"
#include "shopwindow.h"
#include "game.h"

class MainMenu : public QGraphicsView
{
    Q_OBJECT
    QGraphicsScene* scene;

public:
    MainMenu(QWidget* parent = 0);
    void displayMainMenu();

public slots:
    void start();
    void shop();
    void highScore();
    void achievement();

private:
    Game* game;
    HighScore* highscore;
    Achievement* achievements;
};


#endif // MAINMENU_H
