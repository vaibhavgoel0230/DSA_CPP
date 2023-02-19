#include <iostream>
using namespace std;

int RecursionFunc(int num)
{
    if (num % 2 == 0)
    {
        return num / 2;
    }

    return RecursionFunc(3 * num + 1);
}

int IterativeFunc(int num)
{
    if (num % 2 == 1)
    {
        num = 3 * num + 1;
    }

    return num / 2;
}
int main()
{
    int num{0};
    cin >> num;
    cout << RecursionFunc(num) << endl;

    cout << IterativeFunc(num) << endl;
}