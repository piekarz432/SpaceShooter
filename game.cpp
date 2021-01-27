#include "game.h"
#include <QMediaPlayer>
#include "button.h"
#include <QGraphicsTextItem>
#include "gameoverwindow.h"
#include <QMessageBox>

Game::Game(QWidget* parent)
{
    asteroidCounter = 0;
    pointsCounter = 0;

    srand(time(0));

    storage = Storage::getInstance();


    //make game scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1200, 800);
    scene->setBackgroundBrush(QBrush(QImage("E:/SpaceShooter/SpaceShooter/Image/Nebula Aqua-Pink.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200, 800);


    //Create asteroids
    for (int i = 0; i < 15; i++)
    {
        Asteroid* a = new Asteroid();
        a->settings(rand() % 1200, rand() % 800, rand() % 360);
        entities.push_back(a);
    }

    //create bonus
    for (int i = 0; i < 3; i++)
    {
        Bonus* a = new Bonus();
        a->settings(rand() % 1200, rand() % 800, rand() % 360);
        entities.push_back(a);
    }


    /*
    //Create enemy
    for (int i = 0; i < 2; i++)
    {
        Enemy* enemy = new Enemy(":/Image/enemyBlack1.png");
        enemy->settings(rand() % 1200, rand() % 800, rand() % 360);
        entities.push_back(enemy);
    }
    */

    //Create player
    if (storage->getSelectedShip() != nullptr){
        myShip = storage->getSelectedShip();
    }else{
       myShip = new Ship("E:/SpaceShooter/SpaceShooter/Image/Ship (1).png", Red, 3);
    }
    myShip->settings(400, 200, 0);
    myShip->setFlag(QGraphicsItem::ItemIsFocusable);
    myShip->setFocus();

    entities.push_back(myShip);

    //Create health
    health = new Healthbar(myShip->health);
    health->setPos(x() + 1060,y());
    scene->addItem(health);

    //Create score
    score = new Score();
    score->setPos(x() + 900, y());
    scene->addItem(score);

    //Create a timer
    mainTimer = new QTimer(this);
    connect(mainTimer, SIGNAL(timeout()), this, SLOT(mainLoop()));
    mainTimer->start(0);

    shield = new Shield();
    shield->setPos(x() + 1060, y()+30);
    scene->addItem(shield);

    //music

   music = new QMediaPlayer();
   music->setMedia(QUrl("qrc:/music/Music/Battle-in-the-Stars.mp3"));
   music->play();


    for (Entity* e : entities)
    {
        scene->addItem(e);
    }

}

void Game::gameOver()
{
    this->hide();
    music->stop();
    storage->setPointsCounter(score->getScore() / 2);
    GameOverWindow gameOverWindow;
    gameOverWindow.setModal(true);
    gameOverWindow.setScore(score->getScore());
    gameOverWindow.exec();
}

void Game::keyPressEvent(QKeyEvent* event)
{
    myShip->keyReact(event);

    if (event->key() == Qt::Key_Space)
    {
        if(myShip->shipType == Red)
        {
            Bullet* bullet;
            Bullet* bullet1;

            bullet = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);
            bullet1 = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);

            gunPlayer = new QMediaPlayer();
            gunPlayer->setAudioRole(QAudio::Role::GameRole);
            gunPlayer->setMedia(QUrl("qrc:/music/Music/gun_fire.mp3"));
            gunPlayer->play();
            //connect(gunPlayer, &QMediaPlayer::stateChanged, this, &DeviceCanvas::gunStateChanged);

            bullet->settings(myShip->x, myShip->y, myShip->angle);
            bullet1->settings(bullet1->radius * cos(myShip->angle), myShip->y, myShip->angle);
            //bullet1->calcPosition();
            scene->addItem(bullet);
            scene->addItem(bullet1);
            entities.push_back(bullet);
            entities.push_back(bullet1);

        }
        if(myShip->shipType == Green)
        {
            Bullet* bullet;
            Bullet* bullet1;

            bullet = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);
            //bullet1 = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);

            gunPlayer = new QMediaPlayer();
            gunPlayer->setAudioRole(QAudio::Role::GameRole);
            gunPlayer->setMedia(QUrl("qrc:/music/Music/gun_fire.mp3"));
           gunPlayer->play();
            //connect(gunPlayer, &QMediaPlayer::stateChanged, this, &DeviceCanvas::gunStateChanged);

            bullet->settings(myShip->x, myShip->y, myShip->angle);
            //bullet1->settings(myShip->x, myShip->y, myShip->angle, 10.5);
            scene->addItem(bullet);
            //scene->addItem(bullet1);
            entities.push_back(bullet);
            //entities.push_back(bullet1);

        }
        if(myShip->shipType == Blue)
        {
            Bullet* bullet;
            Bullet* bullet1;

            bullet = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);
            //bullet1 = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);

            gunPlayer = new QMediaPlayer();
            gunPlayer->setAudioRole(QAudio::Role::GameRole);
            gunPlayer->setMedia(QUrl("qrc:/music/Music/gun_fire.mp3"));
           gunPlayer->play();
            //connect(gunPlayer, &QMediaPlayer::stateChanged, this, &DeviceCanvas::gunStateChanged);

            bullet->settings(myShip->x, myShip->y, myShip->angle);
            //bullet1->settings(myShip->x, myShip->y, myShip->angle, 10.5);
            scene->addItem(bullet);
            //scene->addItem(bullet1);
            entities.push_back(bullet);
            //entities.push_back(bullet1);

        }
        if(myShip->shipType == Yellow)
        {
            Bullet* bullet;
            Bullet* bullet1;

            bullet = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);
            //bullet1 = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);

            gunPlayer = new QMediaPlayer();
            gunPlayer->setAudioRole(QAudio::Role::GameRole);
            gunPlayer->setMedia(QUrl("qrc:/music/Music/gun_fire.mp3"));
           gunPlayer->play();
            //connect(gunPlayer, &QMediaPlayer::stateChanged, this, &DeviceCanvas::gunStateChanged);

            bullet->settings(myShip->x, myShip->y, myShip->angle);
            //bullet1->settings(myShip->x, myShip->y, myShip->angle, 10.5);
            scene->addItem(bullet);
            //scene->addItem(bullet1);
            entities.push_back(bullet);
            //entities.push_back(bullet1);

        }
        if(myShip->shipType == RedUpgrade)
        {
            Bullet* bullet;
            Bullet* bullet1;

            bullet = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);
            //bullet1 = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);

            gunPlayer = new QMediaPlayer();
            gunPlayer->setAudioRole(QAudio::Role::GameRole);
            gunPlayer->setMedia(QUrl("qrc:/music/Music/gun_fire.mp3"));
           gunPlayer->play();
            //connect(gunPlayer, &QMediaPlayer::stateChanged, this, &DeviceCanvas::gunStateChanged);

            bullet->settings(myShip->x, myShip->y, myShip->angle);
            //bullet1->settings(myShip->x, myShip->y, myShip->angle, 10.5);
            scene->addItem(bullet);
            //scene->addItem(bullet1);
            entities.push_back(bullet);
            //entities.push_back(bullet1);

        }
        if(myShip->shipType == GreenUpgrade)
        {
            Bullet* bullet;
            Bullet* bullet1;

            bullet = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);
            //bullet1 = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);

            gunPlayer = new QMediaPlayer();
            gunPlayer->setAudioRole(QAudio::Role::GameRole);
            gunPlayer->setMedia(QUrl("qrc:/music/Music/gun_fire.mp3"));
           gunPlayer->play();
            //connect(gunPlayer, &QMediaPlayer::stateChanged, this, &DeviceCanvas::gunStateChanged);

            bullet->settings(myShip->x, myShip->y, myShip->angle);
            //bullet1->settings(myShip->x, myShip->y, myShip->angle, 10.5);
            scene->addItem(bullet);
            //scene->addItem(bullet1);
            entities.push_back(bullet);
            //entities.push_back(bullet1);

        }
        if(myShip->shipType == BlueUpgrade)
        {
            Bullet* bullet;
            Bullet* bullet1;

            bullet = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);
            //bullet1 = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);

            gunPlayer = new QMediaPlayer();
            gunPlayer->setAudioRole(QAudio::Role::GameRole);
            gunPlayer->setMedia(QUrl("qrc:/music/Music/gun_fire.mp3"));
           gunPlayer->play();
            //connect(gunPlayer, &QMediaPlayer::stateChanged, this, &DeviceCanvas::gunStateChanged);

            bullet->settings(myShip->x, myShip->y, myShip->angle);
            //bullet1->settings(myShip->x, myShip->y, myShip->angle, 10.5);
            scene->addItem(bullet);
            //scene->addItem(bullet1);
            entities.push_back(bullet);
            //entities.push_back(bullet1);

        }
        if(myShip->shipType == YellowUpgrade)
        {
            Bullet* bullet;
            Bullet* bullet1;

            bullet = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);
            //bullet1 = new Bullet("E:/SpaceShooter/SpaceShooter/Image/laserBlue02.png", Single, 1, 1, 10);

            gunPlayer = new QMediaPlayer();
            gunPlayer->setAudioRole(QAudio::Role::GameRole);
            gunPlayer->setMedia(QUrl("qrc:/music/Music/gun_fire.mp3"));
            gunPlayer->play();
            //connect(gunPlayer, &QMediaPlayer::stateChanged, this, &DeviceCanvas::gunStateChanged);

            bullet->settings(myShip->x, myShip->y, myShip->angle);
            //bullet1->settings(myShip->x, myShip->y, myShip->angle, 10.5);
            scene->addItem(bullet);
            //scene->addItem(bullet1);
            entities.push_back(bullet);
            //entities.push_back(bullet1);

        }

    }
}

/*
updateCounter = rand() % 50;

if (score->getScore() > 5) {
        if (updateCounter == 2)
        {
                bullet = new Bullet(":/Image/laserBlue02.png", Single, 1, 3, 10);
        }
        else {
                bullet = new Bullet(":/Image/laserBlue02.png", Single, 1, 1, 10);
        }

        if (updateCounter > 37) {
                shield->addShield();
                shield->setVisibility(true);
        }
}
else {
*/

void Game::keyReleaseEvent(QKeyEvent* event)
{
    myShip->keyRelease(event);
}

bool Game::isCollide(Entity* a, Entity* b)
{

    if (a->x < b->x + b->width &&
       a->x + b->width > b->x &&
       a->y < b->y + b->height &&
       a->y + a->height > b->y)
    {
        return true;
    }

    return false;
}

void Game::closeEvent(QCloseEvent *bar)
{
    music->stop();
}

void Game::mainLoop()
{
    for (auto a : entities)
    {
        for (auto b : entities)
        {
            if (a->name == "asteroid" && b->name == "bullet")
                if (isCollide(a, b))
                {
                    asteroidCounter +=1;
                    storage->setAsteroidCounter(asteroidCounter);
                    a->life = false;
                    b->life = false;
                    score->increase(a->points);
                }

            if (a->name == "player" && b->name == "shield")
                if (isCollide(a, b))
                {
                    shield->addShield();
                    shield->setVisibility(true);
                    b->life = false;
                }
            if (a->name == "player" && b->name == "health")
                if (isCollide(a, b))
                {
                    health->addHealth(1);
                    b->life = false;
                }
            if (a->name == "player" && b->name == "poison")
                if (isCollide(a, b))
                {
                    health->decrease();
                    b->life = false;
                }

            if (a->name == "player" && b->name == "asteroid")
                if (isCollide(a, b))
                {
                    if (shield->getShield() > 0) {
                        shield->removeShield();
                    }
                    else {
                        health->decrease();
                    }

                    b->life = false;

                    myShip->settings(1200 / 2, 800 / 2, 0);


                if (health->getHealth() <= 0)
                {
                    a->life = false;
                    gameOver();

                }
            }
        }
    }

    for (auto i = entities.begin(); i != entities.end();)
    {
        Entity* e = *i;

        e->move();

        if (e->name == "bullet") {
            if (e->pos().x() < 0) {
                e->life = false;
            }
            if (e->pos().x() > scene->width()) {
                e->life = false;
            }
            if (e->pos().y() < 0) {
                e->life = false;
            }
            if (e->pos().y() > scene->height()) {
                e->life = false;
            }
        }

        if (e->life == false)
        {
            i = entities.erase(i);
            delete e;
        }
        else
        {
            i++;
        }
    }

    for (auto i : entities)
    {
        i->draw();
    }
}


