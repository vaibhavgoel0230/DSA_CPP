#include <iostream>
using namespace std;

int main()
{
    int num{0};
    cin >> num;
    if (num == 0 || num == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    int result = 1;
    for (int i = 2; i <= num; i++)
    {
        result *= i;
    }
    cout << result << endl;
}