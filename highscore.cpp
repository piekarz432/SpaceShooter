#include "highscore.h"
#include "ui_highscore.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

HighScore::HighScore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighScore)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    QStringList title;
    title << "User name" << "Points";
    ui->tableWidget->setHorizontalHeaderLabels(title);
    read();
}

HighScore::~HighScore()
{
    delete ui;
}

void HighScore::read()
{
    QString filename = "E:\\SpaceShooter\\SpaceShooter\\Score\\score.txt";
    QFile file(filename);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        while(!file.atEnd())
        {
            QString line = file.readLine();
            cutString(line.toStdString());
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(name));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(score));
        }

    }

    file.close();
}

void HighScore::on_pushButton_clicked()
{
    this->hide();
}

void HighScore::cutString(std::string text)
{
    int pos = text.find(",");
    std::string cutScore = text.substr(pos + 1);
    cutScore.erase(std::remove(cutScore.begin(), cutScore.end(), '\n'), cutScore.end());
    std:: string cutName = text.substr(0, pos);
    QString tmpScore  = QString::fromStdString(cutScore);
    QString tmpName = QString::fromStdString(cutName);
    score = tmpScore;
    name = tmpName;
}

