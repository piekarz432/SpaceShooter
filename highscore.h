#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QDialog>

namespace Ui {
class HighScore;
}

class HighScore : public QDialog
{
    Q_OBJECT

public:
    explicit HighScore(QWidget *parent = nullptr);
    ~HighScore();

public slots:
    void on_pushButton_clicked();
private:
    Ui::HighScore *ui;
    QString score;
    QString name;
    void read();
    void cutString(std::string string);
};

#endif // HIGHSCORE_H
