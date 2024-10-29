#include "Roomba.h"

int main()
{
    int maxX = 10, maxY = 10;

    // Create a Roomba instance
    Roomba roomba(0, 1);

    // Start the validator and printer loop
    roomba.validatorAndPrinter(maxX, maxY);

    return 0;
}
