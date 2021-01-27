#include "storage.h"
#include <QDebug>

Storage* Storage::_INSTANCE = nullptr;

int Storage::getAsteroidCounter() const
{
    return asteroidCounter;
}

void Storage::setAsteroidCounter(int value)
{
    asteroidCounter = value;
}

int Storage::getPointsCounter() const
{
    return pointsCounter;
}

void Storage::setPointsCounter(int value)
{
    pointsCounter = value;
}

Ship *Storage::getSelectedShip() const
{
    return selectedShip;
}

Storage* Storage::getInstance(){
    if (!_INSTANCE){
        _INSTANCE = new Storage();
    }
    return _INSTANCE;
}

void Storage::addShip(Ship *ship){
    shipsList.push_back(ship);
}

void Storage::setSelectedShip(Ship *ship){
    selectedShip = ship;
}

void Storage::showCountOfShips(){
    qDebug()<< shipsList.size();
}
