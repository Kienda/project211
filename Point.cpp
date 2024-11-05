#include "Point.h"

void Point::set(int x_value, int y_value)
{
    x = x_value;
    y = y_value;
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::print() const
{
    cout << "(" << x << ", " << y << ")";
}

bool Point::isEqual(const Point &other) const
{
    return x == other.x && y == other.y;
}
