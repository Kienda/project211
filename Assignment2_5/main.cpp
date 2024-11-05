#include <iostream>
#include "Roomba.h"
#include "Robot.h"
#include "World.h"

using namespace std;

int main()
{
    // Set up the world with coins
    World world;
    world.set(0, 1, 2); // Set coin 1
    world.set(1, 3, 4); // Set coin 2
    world.set(2, 5, 6); // Set coin 3

    // Print coin positions
    cout << "Coins in the world:\n";
    world.print();

    // Initialize the Roomba
    Roomba roomba;
    roomba.validatorAndPrinter(10, 10); // Set grid size to 10x10

    // Initialize the robot
    Robot robot;
    robot.init();
    robot.print();

    // Simulate robot movement and check for coins
    while (robot.forward())
    {
        if (robot.findCoin(world))
        {
            cout << "Coin found at ";
            robot.print();
        }
        else
        {
            robot.print();
        }
    }

    cout << "Robot has moved " << robot.getMoveCount() << " times.\n";
    return 0;
}
