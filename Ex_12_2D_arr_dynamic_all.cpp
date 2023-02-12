#include <iostream>
using namespace std;

// Write a general version of make 2dArray (Program 1.11) whose third parameter
// is a one-dimensional array rowSize rather than the integer number0f Columns.
// Your function should create a two-dimensional array in which row i has row-
// Size [] positions.

template <typename T>
bool make2dArray(T **x, int *rowSize, int numberOfColumns)
{

    try
    {
        int numberOfRows = *rowSize;
        // create a two dimensional array
        x = new T *[numberOfRows];

        // Get memory for each row
        for (int i = 0; i < numberOfRows; i++)
        {
            x[i] = new T[numberOfColumns];
        }

        return true;
    }
    catch (bad_alloc)
    {
        return false;
    }
}

int main()
{
    int **arr;
    int numberOfRows{0};
    int numberOfColumns{0};
    cout << "Enter the number of Rows : ";
    cin >> numberOfRows;
    cout << "Enter the number of Columns : ";
    cin >> numberOfColumns;

    int rowSize[]{numberOfRows};

    cout << make2dArray<int>(arr, rowSize, numberOfColumns);

    return 0;
}