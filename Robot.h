#ifndef ROBOT_H
#define ROBOT_H

#include "Point.h"
#include "World.h"
#include <string>

class Robot
{
public:
    enum orientation_type
    {
        north,
        south,
        east,
        west
    };

private:
    Point currentLocation;
    orientation_type currentOrientation;
    int moveCount;

public:
    Robot();
    void init();
    void print() const;
    void setOrientation(orientation_type orientation);
    void upDateLocation(int x, int y);
    bool forward();
    bool findCoin(const World &world) const;
    int getMoveCount() const;
    bool eastEnd() const;
    bool westEnd() const;
    bool northEnd() const;
    bool southEnd() const;

private:
    std::string getOrientation() const;
};

#endif
