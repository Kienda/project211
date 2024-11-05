#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;

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

public:
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

        // Simulate movement based on current orientation
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
        return true;
    }

    void turnCW()
    {
        currentOrientation = static_cast<orientation_type>((currentOrientation + 1) % 4);
    }

    void turnAntiCW()
    {
        currentOrientation = static_cast<orientation_type>((currentOrientation + 3) % 4);
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
int main()
{
    Robot robot;
    robot.init();

    // Traversing the world from (0, 0) to (9, 9)
    for (int y = 0; y < 10; ++y) // y from 0 to 9
    {
        // Set orientation based on the row

        // Even rows: move east
        robot.setOrientation(Robot::east);
        for (int x = 0; x < 10; ++x) // x from 0 to 9
        {
            robot.print();   // Print current cell
            robot.forward(); // Move forward to the next cell
            robot.upDateLocation(x, y);
        }
        // Odd rows: move west
        robot.setOrientation(Robot::west);
        for (int x = 9; x >= 0; --x) // x from 9 to 0
        {
            robot.print();              // Print current cell
            robot.forward();            // Move forward to the next cell
            robot.upDateLocation(x, y); // update the location of the robot whenever it moves
        }

        // Move down to the next row if not at the bottom edge
        if (!robot.southEnd())
        {
            robot.setOrientation(Robot::south);
            robot.forward(); // Move down one row
        }
    }

    return 0;
}
