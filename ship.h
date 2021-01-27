#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <qwidget.h>
#include "entity.h"
#include "bullet.h"

enum ShipType {Red, Green, Blue, Yellow, RedUpgrade, GreenUpgrade, BlueUpgrade, YellowUpgrade };

class Ship : public Entity
{
private:
    double speed;
    bool rotateLeft;
    bool rotateRight;
    double maxSpeed;
    double shipAcceleration;
    double shipBreak;

    Bullet* bullet;

public:
    Ship(QString graphicUrl, ShipType shipType, int health);
    ShipType shipType;
    void keyReact(QKeyEvent* event);
    void keyRelease(QKeyEvent* event);
    void calculateMove();
    void calculateAngle();
    void move();
    void calculateXY();
        double shipAgility;
};

#endif // SHIP_H
