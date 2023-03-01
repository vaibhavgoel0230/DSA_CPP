#include <iostream>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void permutations(T list[], int m)
{
    // Generate all permutations of list[k:m]
    // Assume k <= m
    // output the permutations one by one
    do
    {
        copy(list, list + m, ostream_iterator<T>(cout, ""));
        cout << endl;
    } while (next_permutation(list, list + m));
}

int main()
{
    int arr[5] = {2, 3, 1};
    // sort the array
    sort(arr, arr + 3);
    permutations(arr, 3);
}