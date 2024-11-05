#include <iostream>
#include <cstdlib>
#include "Point.h"
#include "World.h"
#include "Robot.h"

using namespace std;

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
                robot.print();
                cout << "I found a coin! I’m gonna be rich! Yippee! >>" << endl;
            }
            robot.forward();
            robot.upDateLocation(x, y);
        }
    }

    cout << "Traversal complete. The robot made " << robot.getMoveCount() << " moves." << endl;

    return 0;
}
