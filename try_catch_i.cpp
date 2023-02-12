#include <iostream>
using namespace std;

int abc(int a, int b, int c)
{
    if (a < 0 && b < 0 && c < 0)
    {
        throw 1;
    }
    else if (a == 0 && b == 0 && c == 0)
    {
        throw 2;
    }
    return a + b + c;
}

int main()
{
    try
    {
        cout << abc(0, 0, 0) << endl; // inputs a = -1, b = -2, c = -3 , inputs a = 0, b = 0, c = 0
    }
    catch (int e)
    {
        if (e == 1)
        {
            cout << "An Exception has been thrown" << endl;
            cout << "All parameters are lesser than zero and they should be greater than zero.";
        }
        else if (e == 2)
        {
            cout << "An Exception has been thrown" << endl;
            cout << "All parameters are equal to zero and they should be greater than zero.";
        }
        return 1;
    }
}