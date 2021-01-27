#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <QDialog>
#include "score.h"

namespace Ui {
class GameOverWindow;
}

class GameOverWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameOverWindow(QWidget *parent = nullptr);
    ~GameOverWindow();

    void setScore(int score);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::GameOverWindow *ui;
    std::string name;
    int score;
    void save();

};

#endif // GAMEOVERWINDOW_H
