#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QDebug>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem* parent = 0);
    void increase(int value);
    int getScore();
    int score;
};

#endif // SCORE_H
