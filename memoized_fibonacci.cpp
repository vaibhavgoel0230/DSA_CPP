#include <iostream>
using namespace std;

int fibonacci(int num)
{
    if (num == 0 || num == 1)
        return num;

    int arr[num + 1];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= num; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[num];
}

int main()
{
    int num{0};
    cin >> num;
    cout << fibonacci(num) << endl;
}