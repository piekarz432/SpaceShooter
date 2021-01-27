#include "ship.h"
#include "bullet.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsRotation>
#include <qtimer.h>
#include "game.h"
#include "asteroid.h"

Ship::Ship(QString graphicUrl, ShipType shipType, int health)
{
    QPixmap mypix (graphicUrl);
    setPixmap(mypix);
    width = mypix.width();
    height = mypix.height();

    radius = (sqrt(pow(mypix.width(), 2) + pow(mypix.height(), 2))) / 2;

    thrust = false;
    speed = 0;
    maxSpeed = 0.01;
    shipAcceleration = 1;
    shipBreak = 0.005;
    shipAgility = 0.5;
    rotateLeft = false;
    rotateRight = false;
    name = "player";
    this->shipType = shipType;
    this->health = health;
}

void Ship::keyReact(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Left)
    {
        rotateLeft = true;
    }
    else if (event->key() == Qt::Key_Right)
    {
        rotateRight = true;
    }
    else if (event->key() == Qt::Key_Up)
    {
        thrust = true;
    }
}

void Ship::keyRelease(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Left)
    {
        rotateLeft = false;
    }
    else if (event->key() == Qt::Key_Right)
    {
        rotateRight = false;
    }
    else if (event->key() == Qt::Key_Up)
    {
        thrust = false;

    }
}

void Ship::move()
{
    calculateAngle();
    calculateMove();
    calculateXY();
}

void Ship::calculateAngle()
{
    if (rotateRight == true)
    {
        angle += shipAgility;
    }
    else if (rotateLeft == true)
    {
        angle -= shipAgility;
    }

    if(angle >= 360)
    {
        angle = 0;
    }

    if(angle <= -360)
    {
        angle = 0;
    }

}

void Ship::calculateMove()
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

void Ship::calculateXY()
{
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







