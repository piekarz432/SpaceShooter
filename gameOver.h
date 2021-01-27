#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QGraphicsView>
#include <map>
#include <string>
#include <QtWidgets/QTextEdit>

class GameOver : public QGraphicsView
{
    Q_OBJECT
    QGraphicsScene* scene;


public:
    GameOver(QWidget* parent = 0);
    std::map<std::string, int> score;
    void displayGameOver();
    void saveScore();
    void readScore();

public slots:
    void restart();
};

#endif // GAMEOVER_H
