#include <iostream>
#include <iterator>
using namespace std;

template <typename T>
void permutations(T list[], int k, int m)
{
    // Generate all permutations of list[k:m]
    int i;
    if (k == m)
    {
        // list[k:m] has only one permutation, output it
        copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
        cout << endl;
    }
    else
    {
        // list[k:m] has more than one permutation
        // generate these recursively
        for (i = k; i <= m; i++)
        {
            swap(list[k], list[i]);
            permutations(list, k + 1, m);
            swap(list[k], list[i]);
        }
    }
}

int main()
{
    char l[] = {'a', 'b', 'c'};
    int k = 0;
    int m = 2;
    permutations<char>(l, k, m);
}