#include <iostream>
using namespace std;

// Write a function changeLength2D that changes the dimensions of a two-
// dimensional array (see Exercise 13). Test your code.

template <typename T>
T **changeLength2D(T **oldArray, int oldLength, int newLength)
{

    try
    {
        // check for minimum length
        int minLength{0};
        if (oldLength <= newLength)
            minLength = oldLength;
        else
            minLength = newLength;

        T **newArray = new T *[minLength];

        int numberOfColumns = 3;
        for (int i = 0; i < minLength; i++)
        {
            newArray[i] = new T[numberOfColumns];
            for (int j = 0; j < numberOfColumns; j++)
            {
                newArray[i][j] = oldArray[i][j];
            }
        }

        return newArray;
    }
    catch (bad_alloc)
    {
        exit(1);
    }
}

int main()
{
    int oldLength{6};
    int newLength{3};
    int **array{new int *[oldLength]};
    for (int count{0}; count < oldLength; ++count)
    {
        array[count] = new int[newLength];
        for (int j = 0; j < newLength; j++)
            array[count][j] = j;
    }

    int **out = changeLength2D<int>(array, oldLength, newLength);
    for (int i = 0; i < newLength; i++)
    {
        for (int j = 0; j < newLength; j++)
            cout << out[i][j] << " ";
        cout << endl;
    }

    return 0;
}