#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <QDialog>
#include "storage.h"

namespace Ui {
class Achievement;
}

class Achievement : public QDialog
{
    Q_OBJECT

public:
    explicit Achievement(QWidget *parent = nullptr);
    ~Achievement();

private:
    Ui::Achievement *ui;
    Storage *storage;
    void checkAsteroid(int count);
    void checkPoints(int count);
    void read();
    void write(int value);
};

#endif // ACHIEVEMENT_H
