#include <iostream>
#include <cstdlib> // For atoi()
using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point() { x = 0, y = 0; }

    void set(int x_value, int y_value) { x = x_value, y = y_value; }

    int getX() { return x; }
    int getY() { return y; }

    void print() const { cout << "(" << x << ", " << y << ")" << endl; }
};

int main(int argc, char *argv[])
{
    if (argc != 7)
    {
        cout << "Coordinates of the coins must be between 0 to and 9 !!!" << endl;
        return 1;
    }

    // Create three Point objects for the three coins
    Point coin1, coin2, coin3;

    // Validate and set the coordinates for coin 1
    int coin1X = atoi(argv[1]);
    int coin1Y = atoi(argv[2]);
    if (coin1X < 0 || coin1X > 9 || coin1Y < 0 || coin1Y > 9)
    {
        cout << "Coordinates of the coins must be between 0 to and 9 !!!" << endl;
        return 1;
    }
    coin1.set(coin1X, coin1Y);

    // Validate and set the coordinates for coin 2
    int coin2X = atoi(argv[3]);
    int coin2Y = atoi(argv[4]);
    if (coin2X < 0 || coin2X > 9 || coin2Y < 0 || coin2Y > 9)
    {
        cout << "Coordinates of the coins must be between 0 to and 9 !!!" << endl;
        return 1;
    }
    coin2.set(coin2X, coin2Y);

    // Validate and set the coordinates for coin 3
    int coin3X = atoi(argv[5]);
    int coin3Y = atoi(argv[6]);
    if (coin3X < 0 || coin3X > 9 || coin3Y < 0 || coin3Y > 9)
    {
        cout << "Coordinates of the coins must be between 0 to and 9 !!!" << endl;
        return 1;
    }
    coin3.set(coin3X, coin3Y);

    // Print all the coin locations
    cout << "Coin 1 is at position: ";
    coin1.print();
    cout << "Coin 2 is at position: ";
    coin2.print();
    cout << "Coin 3 is at: ";
    coin3.print();

    return 0;
}
