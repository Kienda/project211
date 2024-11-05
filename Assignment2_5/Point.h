#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point() : x(0), y(0) {}
    void set(int x_value, int y_value);
    int getX() const;
    int getY() const;
    void print() const;
    bool isEqual(const Point &other) const;
};

#endif
