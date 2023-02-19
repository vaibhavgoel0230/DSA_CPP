#include <iostream>
using namespace std;

template <typename T>
bool find_x(T list[], T x, int n)
{
    if (n == 0)
        return false;
    if (list[n - 1] == x)
        return true;
    return find_x(list, x, n - 1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    cout << find_x<int>(arr, x, n) << endl;
}