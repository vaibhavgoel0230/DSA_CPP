#include <iostream>
using namespace std;

// Write a template function changeLength1D to change the length (i.e., num-
// ber of positions) of a one-dimensional array from oldLength to newLength.
// Your function should allocate space for a new one-dimensional array of length
// newLength; copy the first min{oldLength, newLength} elements of the old
// array into the new one; and free the space allocated to the old array. Test
// your code.

template <typename T>
T *changeLength1D(T *oldArray, int oldLength, int newLength)
{

    try
    {
        // check for minimum length
        int minLength{0};
        if (oldLength <= newLength)
            minLength = oldLength;
        else
            minLength = newLength;

        T *newArray = new T[minLength];

        // Get memory for each row
        for (int i = 0; i < minLength; i++)
        {
            newArray[i] = oldArray[i];
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
    int arr[oldLength]{1, 2, 3, 4, 5, 6};

    int *out = changeLength1D<int>(arr, oldLength, newLength);
    for (int i = 0; i < newLength; i++)
        cout << out[i] << " ";

    return 0;
}