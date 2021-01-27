#include "entity.h"

void Entity::settings(int X, int Y, float Angle)
{
    x = X; y = Y;
    angle = Angle;
}

void Entity::draw()
{
    setPos(x, y);
    setRotation(angle);
}

void Entity::updatePosition(QGraphicsScene* scene)
{
    scene->removeItem(this);
    this->draw();
    scene->addItem(this);
}



