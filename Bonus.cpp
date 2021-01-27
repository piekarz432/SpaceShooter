#include "bonus.h"
#include "ship.h"

Bonus::Bonus()
{
    int number = rand() %3;

    if (number == 0){
        QPixmap mypix ("E:/SpaceShooter/SpaceShooter/Image/Shield.png");
        setPixmap(mypix);
        name = "shield";
        width = mypix.width();
        height = mypix.height();
        radius = (sqrt(pow(mypix.width(), 2) + pow(mypix.height(), 2))) / 2;
    }else if(number == 1){
        QPixmap mypix ("E:/SpaceShooter/SpaceShooter/Image/Poison.png");
        setPixmap(mypix);
        name = "poison";
        width = mypix.width();
        height = mypix.height();
        radius = (sqrt(pow(mypix.width(), 2) + pow(mypix.height(), 2))) / 2;
    }else if(number == 2){
        QPixmap mypix ("E:/SpaceShooter/SpaceShooter/Image/Health.png");
        setPixmap(mypix);
        name = "health";
        width = mypix.width();
        height = mypix.height();
        radius = (sqrt(pow(mypix.width(), 2) + pow(mypix.height(), 2))) / 2;
    }


    dx = rand() % 8 - 4;
    dy = rand() % 8 - 4;
}

void Bonus::move()
{
    calculateXY();
}

void Bonus::calculateXY()
{
    double speed = 0.1;
    double actualX = x;
    double actualY = y;
    double destinationX;
    double destinationY;
    double deltaX;
    double deltaY;
    double pi = 3.14159265359;

    deltaX = speed * sin(angle * (pi / 180));
    deltaY = speed * cos(angle * (pi / 180));

    if (x > deltaX)
    {
        destinationX = actualX + deltaX;
    }
    else
    {
        destinationX = actualX - deltaX;
    }

    if (y > deltaY)
    {
        destinationY = actualY - deltaY;
    }
    else
    {
        destinationY = actualY + deltaY;
    }


    x = destinationX;
    y = destinationY;

    if (x > W) x = 0; if (x < 0) x = W;
    if (y > H) y = 0; if (y < 0) y = H;
}
