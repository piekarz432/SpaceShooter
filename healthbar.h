#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QDebug>
#include <QApplication>

class Healthbar : public QGraphicsTextItem
{
public:
    Healthbar(int health, QGraphicsItem* parent = 0);
    void decrease();
    int getHealth();
    void addHealth(int count);

private:
    int health;
};

#endif // HEALTHBAR_H
