#include <iostream>
using namespace std;

// Global variables to represent Roomba's position
int x = 0;
int y = 0;

// Display the current position of Roomba
void display()
{
    cout << "The Roomba is at location (" << x << "," << y << ")\n";
}

// Move functions with boundary checks
void moveForward(int maxY)
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

void moveBackward()
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

void moveLeft()
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

void moveRight(int maxX)
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

// Move until hitting the wall functions
void moveForwardToWall(int maxY)
{
    cout << "Moving forward until the northern wall...\n";
    while (y + 1 < maxY)
    {
        y++;
        display();
    }
    cout << "Bumped into the northern wall!\n";
}

void moveBackwardToWall()
{
    cout << "Moving backward until the southern wall...\n";
    while (y - 1 >= 0)
    {
        y--;
        display();
    }
    cout << "Bumped into the southern wall!\n";
}

void moveLeftToWall()
{
    cout << "Moving left until the western wall...\n";
    while (x - 1 >= 0)
    {
        x--;
        display();
    }
    cout << "Bumped into the western wall!\n";
}

void moveRightToWall(int maxX)
{
    cout << "Moving right until the eastern wall...\n";
    while (x + 1 < maxX)
    {
        x++;
        display();
    }
    cout << "Bumped into the eastern wall!\n";
}

// Function to handle direction commands
void moveDirection(char direction, int maxX, int maxY)
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
        break;
    default:
        cout << "Invalid command. Try again!\n";
        break;
    }
}

// Main loop for controlling the Roomba
void validatorAndPrinter(int maxX, int maxY)
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
            checker = false;
            break;
        }
        moveDirection(car, maxX, maxY);
    }
}

int main()
{
    int maxX = 10, maxY = 10;

    // Roomba starts at position (0, 0)
    validatorAndPrinter(maxX, maxY);

    return 0;
}
