#include <iostream>
using namespace std;

int fibonacci(int num)
{
    if (num == 1)
        return 0;
    if (num == 2)
        return 1;
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main()
{
    int num{0};
    cin >> num;
    cout << fibonacci(num) << endl;
}
