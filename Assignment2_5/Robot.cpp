#include "Robot.h"
#include <iostream>
using namespace std;

Robot::Robot() : moveCount(0) {}

void Robot::init()
{
    currentLocation.set(0, 0);
    currentOrientation = east;
}

void Robot::print() const
{
    cout << "I am at ";
    currentLocation.print();
    cout << " and I am facing " << getOrientation() << "." << endl;
}

void Robot::setOrientation(orientation_type orientation)
{
    currentOrientation = orientation;
}

void Robot::upDateLocation(int x, int y)
{
    currentLocation.set(x, y);
}

bool Robot::forward()
{
    int x = currentLocation.getX();
    int y = currentLocation.getY();

    switch (currentOrientation)
    {
    case north:
        if (northEnd())
            return false;
        currentLocation.set(x, y + 1);
        break;
    case south:
        if (southEnd())
            return false;
        currentLocation.set(x, y - 1);
        break;
    case east:
        if (eastEnd())
            return false;
        currentLocation.set(x + 1, y);
        break;
    case west:
        if (westEnd())
            return false;
        currentLocation.set(x - 1, y);
        break;
    }
    moveCount++;
    return true;
}

bool Robot::findCoin(const World &world) const
{
    return world.hasCoin(currentLocation);
}

int Robot::getMoveCount() const
{
    return moveCount;
}

bool Robot::eastEnd() const { return currentLocation.getX() >= 9; }
bool Robot::westEnd() const { return currentLocation.getX() <= 0; }
bool Robot::northEnd() const { return currentLocation.getY() >= 9; }
bool Robot::southEnd() const { return currentLocation.getY() <= 0; }

std::string Robot::getOrientation() const
{
    switch (currentOrientation)
    {
    case north:
        return "north";
    case south:
        return "south";
    case east:
        return "east";
    case west:
        return "west";
    }
    return "unknown";
}
