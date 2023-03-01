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
    cout << "Prints lexically increasing permutations" << endl;
    do
    {
        copy(list, list + m, ostream_iterator<T>(cout, ""));
        cout << endl;
    } while (next_permutation(list, list + m));

    reverse(list, list + m);

    cout << "Prints lexically decreasing permutations" << endl;
    do
    {
        copy(list, list + m, ostream_iterator<T>(cout, ""));
        cout << endl;
    } while (prev_permutation(list, list + m));
}

template <typename T>
void all_permutations_without_sort(T list[], int m)
{
    // Generate all permutations of list[k:m]
    // Assume k <= m
    // output the permutations one by one
    int arr[m];
    copy(list, list + m, arr);
    cout << "Prints lexically increasing permutations" << endl;
    do
    {
        copy(list, list + m, ostream_iterator<T>(cout, ""));
        cout << endl;
    } while (next_permutation(list, list + m));

    cout << "Prints lexically decreasing permutations" << endl;
    do
    {
        copy(arr, arr + m, ostream_iterator<T>(cout, ""));
        cout << endl;
    } while (prev_permutation(arr, arr + m));
}

int main()
{
    int arr[5] = {2, 3, 1};
    all_permutations_without_sort(arr, 3);
    // sort the array
    sort(arr, arr + 3);
    permutations(arr, 3);
}