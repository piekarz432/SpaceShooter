#include "bullet.h"
#include "asteroid.h"

Bullet::Bullet(QString graphicUrl, CannonType cannonType, float shootDuration, float speed, float power)
{
    QPixmap mypix (graphicUrl);
    setPixmap(mypix);
    width = mypix.width();
    height = mypix.height();
    radius = (sqrt(pow(mypix.width(), 2) + pow(mypix.height(), 2))) / 2;
    this->cannonType = cannonType;
    this->shootDuration = shootDuration;
    this->speed = speed;
    this->power = power;
    name = "bullet";
}

void Bullet::move()
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

}

void Bullet::calcPosition()
{
    this->x = this->x + (this->x * cos(this->angle));
}


