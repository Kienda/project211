#include "Roomba.h"

// Constructor to initialize Roomba's position
Roomba::Roomba(int startX, int startY) : x(startX), y(startY) {}

void Roomba::display() const
{
    cout << "The Roomba is at location (" << x << "," << y << ")\n";
}

// Move methods with boundary checks
void Roomba::moveForward(int maxY)
{
    if (y + 1 < maxY)
    {
        cout << "Moving forward -->>\n";
        y++;
    }
    else
    {
        cout << "Bumped the northern wall!\n";
    }
}

void Roomba::moveBackward()
{
    if (y - 1 >= 0)
    {
        cout << "Moving backward <<\n";
        y--;
    }
    else
    {
        cout << "Bumped the southern wall!\n";
    }
}

void Roomba::moveLeft()
{
    if (x - 1 >= 0)
    {
        cout << "Moving left...\n";
        x--;
    }
    else
    {
        cout << "Bumped the western wall!\n";
    }
}

void Roomba::moveRight(int maxX)
{
    if (x + 1 < maxX)
    {
        cout << "Moving right...\n";
        x++;
    }
    else
    {
        cout << "Bumped the eastern wall!\n";
    }
}

// Move until hitting the wall
void Roomba::moveForwardToWall(int maxY)
{
    cout << "Moving forward until the northern wall...\n";
    while (y + 1 < maxY)
    {
        y++;
        display();
    }
    cout << "Bumped into the northern wall!\n";
}

void Roomba::moveBackwardToWall()
{
    cout << "Moving backward until the southern wall...\n";
    while (y - 1 >= 0)
    {
        y--;
        display();
    }
    cout << "Bumped into the southern wall!\n";
}

void Roomba::moveLeftToWall()
{
    cout << "Moving left until the western wall...\n";
    while (x - 1 >= 0)
    {
        x--;
        display();
    }
    cout << "Bumped into the western wall!\n";
}

void Roomba::moveRightToWall(int maxX)
{
    cout << "Moving right until the eastern wall...\n";
    while (x + 1 < maxX)
    {
        x++;
        display();
    }
    cout << "Bumped into the eastern wall!\n";
}

// Function to handle the direction commands
void Roomba::moveDirection(char direction, int maxX, int maxY)
{
    switch (direction)
    {
    case 'n':
        moveForward(maxY);
        break;
    case 's':
        moveBackward();
        break;
    case 'e':
        moveRight(maxX);
        break;
    case 'w':
        moveLeft();
        break;
    case 'N':
        moveForwardToWall(maxY);
        break;
    case 'S':
        moveBackwardToWall();
        break;
    case 'E':
        moveRightToWall(maxX);
        break;
    case 'W':
        moveLeftToWall();
        break;
    case 'Q':
        cout << "Game Over!\n";
        return; // Early return on quit
    default:
        cout << "Invalid command. Try again!\n";
        return; // Prevent moving if command is invalid
    }
}

// Function to validate input and print position
void Roomba::validatorAndPrinter(int maxX, int maxY)
{
    char command;
    while (true)
    {
        cout << "Enter direction (n/s/e/w/N/S/E/W) or 'Q' to quit: ";
        cin >> command;
        moveDirection(command, maxX, maxY);
        display();
    }
}
