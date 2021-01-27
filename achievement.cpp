#include "achievement.h"
#include "ui_achievement.h"
#include "QDebug"

Achievement::Achievement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Achievement)
{
    ui->setupUi(this);

    storage = Storage::getInstance();
    read();
    checkAsteroid(storage->getAsteroidCounter());
    checkPoints(storage->getPointsCounter());
}

Achievement::~Achievement()
{
    delete ui;
}

void Achievement::checkAsteroid(int count)
{
    for(int i = 0; i < ui->listWidget->count(); i++)
    {
        if(count >= 5 && count <10)
        {
            ui->listWidget->item(0)->setBackground(Qt::green);
            write(0);
            break;
        }else if (count >= 10 && count <20)
        {
            ui->listWidget->item(0)->setBackground(Qt::green);
            ui->listWidget->item(1)->setBackground(Qt::green);
            write(1);
            break;
        }else if (count >= 20 && count < 50)
        {
            ui->listWidget->item(0)->setBackground(Qt::green);
            ui->listWidget->item(1)->setBackground(Qt::green);
            ui->listWidget->item(2)->setBackground(Qt::green);
            write(2);
            break;
        }else if (count >= 50)
        {
            ui->listWidget->item(0)->setBackground(Qt::green);
            ui->listWidget->item(1)->setBackground(Qt::green);
            ui->listWidget->item(2)->setBackground(Qt::green);
            ui->listWidget->item(3)->setBackground(Qt::green);
            write(3);
            break;
        }

    }
}

void Achievement::checkPoints(int count)
{
    for(int i = 0; i < ui->listWidget->count(); i++)
    {
        if(count >= 100 && count < 200)
        {
            ui->listWidget->item(4)->setBackground(Qt::green);
            write(4);
            break;
        }else if (count >= 200)
        {
            ui->listWidget->item(4)->setBackground(Qt::green);
            ui->listWidget->item(5)->setBackground(Qt::green);
            write(5);
            break;
        }
    }

}

void Achievement::read()
{
    QString filename = "E:\\SpaceShooter\\SpaceShooter\\Achievement\\achievement.txt";
    QFile file(filename);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        while(!file.atEnd())
        {
            QString line = file.readLine();
            std::string index = line.toStdString();

            for(int i = 0; i < ui->listWidget->count(); i++)
            {
                ui->listWidget->item(line.toInt())->setBackground(Qt::green);
            }

        }

    }

    file.close();
}

void Achievement::write(int value)
{
    QString filename = "E:\\SpaceShooter\\SpaceShooter\\Achievement\\achievement.txt";
    QFile file(filename);

    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream << value << endl;
    }

    file.close();

}


