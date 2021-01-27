#include "asteroid.h"
#include "ship.h"
#include "bullet.h"
#include <QDebug>


Asteroid::Asteroid()
{
    QPixmap mypix (":/Image/meteorBrown_big4.png");
    setPixmap(mypix);
    width = mypix.width();
    height = mypix.height();
    radius = (sqrt(pow(mypix.width(), 2) + pow(mypix.height(), 2))) / 2;
    dx = rand() % 8 - 4;
    dy = rand() % 8 - 4;
    name = "asteroid";
    points = 1 + rand() % 10;
}

void Asteroid::move()
{
    calculateXY();
}

void Asteroid::calculateXY()
{
    double speed = 0.1;
    double actualX = x;
    double actualY = y;
    double destinationX;
    double destinationY;
    double dujkaX;
    double dujkaY;
    double pi = 3.14159265359;

    dujkaX = speed * sin(angle * (pi / 180));
    dujkaY = speed * cos(angle * (pi / 180));

    if (x > dujkaX)
    {
        destinationX = actualX + dujkaX;
    }
    else
    {
        destinationX = actualX - dujkaX;
    }

    if (y > dujkaY)
    {
        destinationY = actualY - dujkaY;
    }
    else
    {
        destinationY = actualY + dujkaY;
    }


    x = destinationX;
    y = destinationY;

    if (x > W) x = 0; if (x < 0) x = W;
    if (y > H) y = 0; if (y < 0) y = H;
}
