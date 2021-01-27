#ifndef BONUS_H
#define BONUS_H

#include"entity.h"

class Bonus : public Entity
{
private:
    double dx, dy;
public:
    Bonus();
    void move();
    void calculateXY();
};


#endif // BONUS_H
