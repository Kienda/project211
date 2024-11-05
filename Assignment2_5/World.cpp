#include "World.h"
#include <iostream>

void World::set(int i, int x, int y)
{
    if (i >= 0 && i < 3)
    {
        coins[i].set(x, y); // Set location for the i-th coin
    }
}

bool World::hasCoin(const Point &location) const
{
    for (int i = 0; i < 3; i++)
    {
        if (location.isEqual(coins[i]))
        {
            return true;
        }
    }
    return false;
}

void World::print() const
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Coin " << (i + 1) << " is at position: ";
        coins[i].print();
        std::cout << std::endl;
    }
}
