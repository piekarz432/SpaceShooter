#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QGraphicsScene>

class Entity : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    bool thrust;
    bool life;
    float x, y, angle, radius, width, height;
    int health;
    int points;
    int itemWidth, itemHeight;
    const int W = 1200;
    const int H = 800;
    QString name;
    void settings(int X, int Y, float Angle = 0);
    void draw();
    virtual void move() = 0;

public slots:
    void updatePosition(QGraphicsScene* scene);
};

#endif // ENTITY_H
