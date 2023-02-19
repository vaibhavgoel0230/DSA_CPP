#include <iostream>
#include <cmath>
using namespace std;

int func(int i, int j)
{
    if (i == 1)
    {
        return pow(2, j);
    }

    if (j == 1)
    {
        return func(i - 1, 2);
    }

    return func(i - 1, func(i, j - 1));
}

int main()
{
    int i, j;
    cin >> i >> j;
    cout << func(i, j) << endl;
}