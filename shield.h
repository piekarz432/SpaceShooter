#ifndef SHIELD_H
#define SHIELD_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QDebug>

class Shield : public QGraphicsTextItem {
public:
    Shield(QGraphicsItem *parent = 0);
    void addShield();
    int getShield();
    void setVisibility(bool);
    void removeShield();
private:
    int shield;
};

#endif // SHIELD_H
