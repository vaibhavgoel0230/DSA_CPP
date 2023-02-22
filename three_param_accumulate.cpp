#include <iostream>
#include <numeric>
using namespace std;

void accumulate_func(int arr[], int n)
{
    cout << accumulate(arr, arr + n, 0);
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
    accumulate_func(arr, n);
    return 0;
}