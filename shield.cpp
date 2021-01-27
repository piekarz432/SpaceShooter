#include "shield.h"

Shield::Shield(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
    shield = 0;
    setVisible(false);
    setPlainText(QString("Shield: ") + QString::number(shield));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Shield::addShield()
{
    if (shield == 0) {
        shield += 1;
        setPlainText(QString("Shield: ") + QString::number(shield));
    }
}

void Shield::removeShield() {
    if (shield > 0) {
        shield -= 1;
        setPlainText(QString("Shield: ") + QString::number(shield));
        if (shield == 0) {
            setVisible(false);
        }
    }
}

int Shield::getShield()
{
    return shield;
}

void Shield::setVisibility(bool visible) {
    if (visible) {
        setVisible(true);
    }
    else {
        setVisible(false);
    }
}
