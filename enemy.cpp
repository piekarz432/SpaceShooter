#include "enemy.h"

Enemy::Enemy(QString graphicUrl)
{
    QPixmap mypix (graphicUrl);
    setPixmap(mypix);

    radius = (sqrt(pow(mypix.width(), 2) + pow(mypix.height(), 2))) / 2;
    dx = rand() % 8 - 4;
    dy = rand() % 8 - 4;
    thrust = false;
    speed = 0;
    maxSpeed = 0.01;
    shipAcceleration = 1;
    shipBreak = 0.005;
    shipAgility = 0.5;
    rotateLeft = 0.4;
    rotateRight = false;
    name = "enemy";
    this->health = health;
}

void Enemy::move()
{
    calculateXY();
}

void Enemy::calculateAngle()
{
    if (rotateRight == true)
    {
        angle += shipAgility;
    }
    else if (rotateLeft == true)
    {
        angle -= shipAgility;
    }
}

void Enemy::calculateMove()
{
    if (thrust == true)
    {
        if (speed < maxSpeed)
        {
            speed += shipAcceleration;
        }

    }
    else
    {
        if (speed > 0)
        {
            speed -= shipBreak;
        }
        else
        {
            speed = 0;
        }

    }
}

void Enemy::calculateXY()
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



