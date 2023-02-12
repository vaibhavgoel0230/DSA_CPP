#include <iostream>
using namespace std;

template <typename T>
bool make2dArray(T **x, int numberOfRows, int numberOfColumns)
{

    try
    {
        // create a two dimensional array
        x = new T *[numberOfRows];

        // Get memory for each row
        for (int i = 0; i < numberOfRows; i++)
        {
            x[i] = new int[numberOfColumns];
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

    cout << make2dArray<int>(arr, numberOfRows, numberOfColumns);

    return 0;
}