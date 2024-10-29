#include "Roomba.h"

// Constructor to initialize Roomba's position
Roomba::Roomba(int startX, int startY) : x(startX), y(startY) {}

void Roomba::display() const
{
    cout << "The roomba is at location (" << x << "," << y << ")\n";
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
    case 'n': // lowercase 'n' now moves ONE step forward
        moveForward(maxY);
        break;
    case 's': // lowercase 's' now moves ONE step backward
        moveBackward();
        break;
    case 'e': // lowercase 'e' now moves ONE step to the right
        moveRight(maxX);
        break;
    case 'w': // lowercase 'w' now moves ONE step to the left
        moveLeft();
        break;
    case 'N': // uppercase 'N' now moves UNTIL hitting the wall
        moveForwardToWall(maxY);
        break;
    case 'S': // uppercase 'S' now moves UNTIL hitting the wall
        moveBackwardToWall();
        break;
    case 'E': // uppercase 'E' now moves UNTIL hitting the wall
        moveRightToWall(maxX);
        break;
    case 'W': // uppercase 'W' now moves UNTIL hitting the wall
        moveLeftToWall();
        break;
    case 'Q':
        cout << "Game Over!\n";
        break;
    default:
        cout << "Invalid command. Try again!\n";
        break;
    }
}

// Main loop for controlling the Roomba
void Roomba::validatorAndPrinter(int maxX, int maxY)
{
    char car;
    bool checker = true;
    while (checker)
    {
        display();
        cout << "Select direction (N/S/E/W for one step...\n n/s/e/w to move until wall, Q to quit): ";
        cin >> car;
        if (toupper(car) == 'Q')
        {
            moveDirection('Q', maxX, maxY);
            checker = false; // Exit loop
            break;
        }
        moveDirection(car, maxX, maxY);
    }
}
