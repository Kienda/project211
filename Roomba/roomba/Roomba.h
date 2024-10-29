#ifndef ROOMBA_H
#define ROOMBA_H

#include <iostream>
using namespace std;

class Roomba
{
private:
    int x; // Roomba's x position
    int y; // Roomba's y position

public:
    // Constructor
    Roomba(int startX = 0, int startY = 0);

    // Function declarations
    void display() const;
    void moveForward(int maxY);
    void moveBackward();
    void moveLeft();
    void moveRight(int maxX);
    void moveForwardToWall(int maxY);
    void moveBackwardToWall();
    void moveLeftToWall();
    void moveRightToWall(int maxX);
    void moveDirection(char direction, int maxX, int maxY);
    void validatorAndPrinter(int maxX, int maxY);
};

#endif // ROOMBA_H
