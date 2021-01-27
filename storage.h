#ifndef STORAGE_H
#define STORAGE_H

#include <list>
#include <iterator>
#include "ship.h"

class Storage
{
private:
    std::list <Ship*> shipsList;
    Ship *selectedShip = nullptr;
    int asteroidCounter = 0;
    int pointsCounter = 0;
    Storage() {}
    Storage(Storage const&){}
    static Storage* _INSTANCE;

public:
    static Storage* getInstance();
    void addShip(Ship *ship);
    void setSelectedShip(Ship *ship);
    void showCountOfShips();
    int getAsteroidCounter() const;
    void setAsteroidCounter(int value);
    int getPointsCounter() const;
    void setPointsCounter(int value);
    Ship *getSelectedShip() const;
};

#endif // STORAGE_H
