#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include "ship.h"
#include <Qtimer>
#include "bullet.h"
#include "healthbar.h"
#include "score.h"
#include "enemy.h"
#include "asteroid.h"
#include "entity.h"
#include "shield.h"
#include <cmath>
#include "gameoverwindow.h"
#include "storage.h"
#include "bonus.h"
#include <QMediaPlayer>

using namespace std;

class Game : public QGraphicsView
{
    Q_OBJECT
    QGraphicsScene* scene;
    Ship* myShip;
    QTimer* mainTimer;
    Score* score;
    Storage *storage;
    Healthbar* health;
    QMediaPlayer *gunPlayer;
    QMediaPlayer* music;
    int points = 0;
    int asteroidCounter;
    int pointsCounter;
    bool isCollide(Entity* a, Entity* b);
    void closeEvent(QCloseEvent *bar);

public:
    Game(QWidget* parent = 0);
    list<Entity*> entities = list<Entity*>();

    Shield* shield;
    int updateCounter = 0;
    void gameOver();

public slots:
    void mainLoop();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
};

#endif // GAME_H
