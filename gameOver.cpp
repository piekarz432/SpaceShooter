#include "gameOver.h"
#include <QGraphicsTextItem>
#include "button.h"
#include "game.h"
#include <iostream>
#include <fstream>


GameOver::GameOver(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1200, 800);
    scene->setBackgroundBrush(QBrush(QImage(":/Image/Dynamic Space Background/Sprites/Nebula Aqua-Pink.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200, 800);
}

void GameOver::displayGameOver()
{
    // create the title text
       QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Game Over"));
       QFont titleFont("comic sans",50);
       titleText->setFont(titleFont);
       int txPos = this->width()/2 - titleText->boundingRect().width()/2;
       int tyPos = 150;
       titleText->setPos(txPos,tyPos);
       scene->addItem(titleText);

       QTextEdit *textEdit = new QTextEdit();
       textEdit->setObjectName(QString::fromUtf8("textEdit"));
       textEdit->setGeometry(QRect(100, 120, 151, 51));


       // create the play button
       Button* restartButton = new Button(QString("Save and Restart"));
       int bxPos = this->width()/2 - restartButton->boundingRect().width()/2;
       int byPos = 275;
       restartButton->setPos(bxPos,byPos);
       connect(restartButton,SIGNAL(clicked()),this,SLOT(restart()));
       scene->addItem(restartButton);


       // create the quit button
       Button* quitButton = new Button(QString("Quit"));
       int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
       int qyPos = 500;
       quitButton->setPos(qxPos,qyPos);
       connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
       scene->addItem(quitButton);
}

void GameOver::restart(){
    // clear the screen
    scene->clear();

}

void GameOver::saveScore()
{
    std::ofstream writeFile("Score/score.txt");

    if(writeFile.is_open())
    {
        //write
    }
}

void GameOver::readScore()
{
    std:: ifstream readFile;
    readFile.open("Score/score.txt");

    if(readFile.is_open())
    {
        int i = 0;
        while(!readFile.eof())
        {

        }
    }

    readFile.close();
}
