#include <iostream>
using namespace std;

// Function prototypes
void rotate_1dArray(int arr[], int size);
void rotate_2dArray(int arr[][3], int size);

// Function to rotate a 1D array
void rotate_1dArray(int arr[], int size)
{
    int first = arr[0];

    // Shift elements to the left
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    // Move the first element to the end
    arr[size - 1] = first;

    // Print rotated array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to rotate a 2D array 90 degrees clockwise
void rotate_2dArray(int arr[][3], int size)
{
    // First transpose the matrix (swap rows and columns)
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    // Then reverse each row
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size / 2; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[i][size - j - 1];
            arr[i][size - j - 1] = temp;
        }
    }

    // Print rotated 2D array
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Example 1D arrays
    int arr1[3] = {1, 2, 3};
    cout << "Original 1D array: ";
    for (int i = 0; i < 3; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\nRotated 1D array: ";
    rotate_1dArray(arr1, 3);

    // Example 2D array
    int arr_2d[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "Original 2D array:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr_2d[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Rotated 2D array 90 degrees:\n";
    rotate_2dArray(arr_2d, 3);

    return 0;
}