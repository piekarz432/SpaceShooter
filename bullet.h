#ifndef BULLET_H
#define BULLET_H

#include "entity.h"

enum CannonType { Single, Double, Triple};

class Bullet : public Entity {

public:
    Bullet(QString graphicUrl, CannonType cannonType, float shootDuration, float speed, float power);
    void move();

        void calcPosition();

private:
    CannonType cannonType;
    float shootDuration;
    float speed;
    float power;


};

#endif // BULLET_H
