#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy : public Entity
{
private:
    double dx, dy;
    double speed;
    double rotateLeft;
    double rotateRight;
    double maxSpeed;
    double shipAcceleration;
    double shipBreak;
    double shipAgility;

public:
    Enemy(QString graphicUrl);
    void calculateMove();
    void calculateAngle();
    void move();
    void calculateXY();
};

#endif // ENEMY_H
