#include <iostream>
#include <cstdlib> // For atoi()
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

    int getX() { return x; }
    int getY() { return y; }

    void print() const { cout << "(" << x << ", " << y << ")" << endl; }
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

    void print() const
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "Coin " << (i + 1) << " is at position: ";
            coins[i].print();
        }
    }
};

int main(int argc, char *argv[])
{
    // Check if the correct number of arguments is provided
    if (argc != 7)
    {
        cout << "Error: Please enter exactly 6 command-line arguments." << endl;
        return 1;
    }
    // Convert arguments to integers and validate each pair of coordinates
    int x1 = atoi(argv[1]);
    int y1 = atoi(argv[2]);
    int x2 = atoi(argv[3]);
    int y2 = atoi(argv[4]);
    int x3 = atoi(argv[5]);
    int y3 = atoi(argv[6]);

    // Check if each coordinate is within the range [0, 9]
    if ((x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9) ||
        (x2 < 0 || x2 > 9 || y2 < 0 || y2 > 9) ||
        (x3 < 0 || x3 > 9 || y3 < 0 || y3 > 9))
    {
        cout << "Error: All coordinates must be within the range 0 to 9." << endl;
        return 1;
    }

    // Create a World object and set the coordinates
    World world;
    world.set(0, x1, y1);
    world.set(1, x2, y2);
    world.set(2, x3, y3);

    // Print all the coin locations
    world.print();

    return 0;
}
