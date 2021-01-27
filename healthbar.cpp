#include "healthbar.h"

Healthbar::Healthbar(int health, QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
    this->health = health;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));

}

void Healthbar::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Healthbar::getHealth()
{
    return health;
}

void Healthbar::addHealth(int count){
    health = health + count;
    setPlainText(QString("Health: ") + QString::number(health));
}
