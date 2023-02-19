#include <iostream>
using namespace std;

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    int mod = x % y;
    return gcd(y, mod);
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << endl;
}