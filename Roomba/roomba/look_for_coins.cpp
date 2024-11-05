#include <iostream>
#include <cstdlib> // For atoi()
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point() : x(0), y(0) {}

    void set(int x_value, int y_value)
    {
        x = x_value;
        y = y_value;
    }

    int getX() const { return x; }
    int getY() const { return y; }

    void print() const
    {
        cout << "(" << x << ", " << y << ")";
    }

    bool isEqual(const Point &other) const
    {
        return x == other.x && y == other.y;
    }
};

class World
{
private:
    Point coins[3]; // Array of 3 Point objects representing coins

public:
    void set(int i, int x, int y)
    {
        if (i >= 0 && i < 3)
        {
            coins[i].set(x, y); // Set location for the i-th coin
        }
    }

    bool hasCoin(const Point &location) const
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

    void print() const
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "Coin " << (i + 1) << " is at position: ";
            coins[i].print();
            cout << endl;
        }
    }
};

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
    Robot() : moveCount(0) {}

    void init()
    {
        currentLocation.set(0, 0);
        currentOrientation = east;
    }

    void print() const
    {
        cout << "I am at ";
        currentLocation.print();
        cout << " and I am facing " << getOrientation() << "." << endl;
    }

    void setOrientation(orientation_type orientation)
    {
        currentOrientation = orientation;
    }

    void upDateLocation(int x, int y)
    {
        currentLocation.set(x, y);
    }

    bool forward()
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

    bool findCoin(const World &world) const
    {
        return world.hasCoin(currentLocation);
    }

    int getMoveCount() const
    {
        return moveCount;
    }

    bool eastEnd() const { return currentLocation.getX() >= 9; }
    bool westEnd() const { return currentLocation.getX() <= 0; }
    bool northEnd() const { return currentLocation.getY() >= 9; }
    bool southEnd() const { return currentLocation.getY() <= 0; }

private:
    string getOrientation() const
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
};

// Main function to control the robot and traverse the grid
int main(int argc, char *argv[])
{
    if (argc != 7)
    {
        cout << "Error: Please enter exactly 6 command-line arguments." << endl;
        return 1;
    }

    int x1 = atoi(argv[1]), y1 = atoi(argv[2]);
    int x2 = atoi(argv[3]), y2 = atoi(argv[4]);
    int x3 = atoi(argv[5]), y3 = atoi(argv[6]);

    if ((x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9) ||
        (x2 < 0 || x2 > 9 || y2 < 0 || y2 > 9) ||
        (x3 < 0 || x3 > 9 || y3 < 0 || y3 > 9))
    {
        cout << "Error: All coordinates must be within the range 0 to 9." << endl;
        return 1;
    }

    World world;
    world.set(0, x1, y1);
    world.set(1, x2, y2);
    world.set(2, x3, y3);

    Robot robot;
    robot.init();

    cout << "Starting grid traversal..." << endl;

    for (int y = 0; y < 10; ++y)
    {
        robot.setOrientation(y % 2 == 0 ? Robot::south : Robot::north);

        for (int x = (y % 2 == 0) ? 0 : 9; (y % 2 == 0) ? (x < 10) : (x >= 0); x += (y % 2 == 0) ? 1 : -1)
        {
            if (robot.findCoin(world))
            {
                cout << "I am at ";
                robot.print();
                cout << "I found a coin! I’m gonna be rich! Yippee! >>" << endl;
            }
            robot.forward();
            robot.upDateLocation(x, y);
        }

        //     if (y <= 9)
        //     {
        //         robot.setOrientation(Robot::south);
        //         robot.forward();
        //         robot.upDateLocation(x, y);
        //     }
    }

    cout << "Traversal complete. The robot made " << robot.getMoveCount() << " moves." << endl;

    return 0;
}
