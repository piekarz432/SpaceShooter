#include "gameoverwindow.h"
#include "ui_gameoverwindow.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include "score.h"
#include "game.h"

GameOverWindow::GameOverWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOverWindow)
{
    ui->setupUi(this);

}

GameOverWindow::~GameOverWindow()
{
    delete ui;
}

void GameOverWindow::on_pushButton_2_clicked()
{
    QApplication::quit();
}

void GameOverWindow::on_pushButton_clicked()
{
    save();
    Game *game = new Game();
    game->show();
    this->hide();
}

void GameOverWindow::save()
{
    QString filename = "E:\\SpaceShooter\\SpaceShooter\\Score\\score.txt";
    QFile file(filename);

    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream stream(&file);
        name = ui->textEdit->toPlainText().toStdString();
        QString qstr = QString::fromStdString(name);

        stream <<qstr<<","<<score<<endl;
    }

    file.close();
}

void GameOverWindow::setScore(int score)
{
    this->score = score;
}

