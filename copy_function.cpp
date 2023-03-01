#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void copy_func(vector<int> vec, int n, vector<int> vec_1)
{
    copy(vec.begin(), vec.begin() + n, vec_1.begin());
    for (int i = 0; i < n; i++)
    {
        cout << vec_1[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> vec_1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    copy_func(vec, n, vec_1);
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}