#include "mainMenu.h"
#include <QGraphicsTextItem>
#include "button.h"
#include "game.h"
#include "highscore.h"
#include "achievement.h"
#include "shopwindow.h"

MainMenu::MainMenu(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1200, 800);
    scene->setBackgroundBrush(QBrush(QImage("E:/SpaceShooter/SpaceShooter/Image/Nebula Red.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200, 800);
}

void MainMenu::displayMainMenu()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Galaxy Space"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    titleText->setDefaultTextColor(Qt::white);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    Button* shopButton = new Button(QString("Shop"));
    int sxPos = this->width()/2 - shopButton->boundingRect().width()/2;
    int syPos = 350;
    shopButton->setPos(sxPos,syPos);
    connect(shopButton,SIGNAL(clicked()),this,SLOT(shop()));
    scene->addItem(shopButton);

    Button* highScoreButton = new Button(QString("HighScore"));
    int hxPos = this->width()/2 - highScoreButton->boundingRect().width()/2;
    int hyPos = 425;
    highScoreButton->setPos(hxPos,hyPos);
    connect(highScoreButton,SIGNAL(clicked()),this,SLOT(highScore()));
    scene->addItem(highScoreButton);

    Button* achievementButton = new Button(QString("Achievements"));
    int axPos = this->width()/2 -  achievementButton->boundingRect().width()/2;
    int ayPos = 500;
    achievementButton->setPos(axPos,ayPos);
    connect(achievementButton,SIGNAL(clicked()),this,SLOT(achievement()));
    scene->addItem( achievementButton);

    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 575;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void MainMenu::start(){
    game = new Game();
    game->show();
}

void MainMenu::shop()
{
    ShopWindow *shopwindow = new ShopWindow();
    shopwindow->show();
}

void MainMenu::highScore()
{
    highscore = new HighScore();
    highscore->show();
}

void MainMenu::achievement()
{
    achievements = new Achievement();
    achievements->show();
}
