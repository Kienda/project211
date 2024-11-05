#ifndef WORLD_H
#define WORLD_H

#include "Point.h"

class World
{
private:
    Point coins[3]; // Array of 3 Point objects representing coins

public:
    void set(int i, int x, int y);
    bool hasCoin(const Point &location) const;
    void print() const;
};

#endif
