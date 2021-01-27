#ifndef ASTEROID_H
#define ASTEROID_H

#include"entity.h"

class Asteroid : public Entity
{
private:
    double dx, dy;
public:
    Asteroid();
    void move();
    void calculateXY();
};
#endif // ASTEROID_H
