#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator> // for ostream_iterator
#include <numeric>  // for inner_product

using namespace std;

int main()
{
    int n;
    cout << "Enter the length of array :";
    cin >> n;

    // initialize vec with size n
    cout << "Enter the array :";
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    // print the count of a number in your array
    cout << "Enter the number to count :";
    int num;
    cin >> num;
    cout << num << " appears " << count(vec.begin(), vec.begin() + n, num) << " times." << endl;

    // fill the end three positions with a given number
    cout << "Enter the number you want to fill the array with :";
    cin >> num;
    fill(vec.end() - 3, vec.end(), num);
    copy(vec.begin(), vec.begin() + n, ostream_iterator<int>(cout, " "));
    cout << endl;

    // read in second vector
    cout << "Enter the second array :";
    vector<int> sec_vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sec_vec[i];
    }

    cout << "Enter the initial number :";
    int init;
    cin >> init;
    cout << "The Inner Product is " << inner_product(sec_vec.begin(), sec_vec.end(), vec.begin(), init) << endl;

    // print consecutive 10 integers
    int arr[10];
    iota(arr, arr + 10, 1);
    copy(arr, arr + 10, ostream_iterator<int>(cout, " "));
    cout << endl;

    // check whether the array is sorted or not
    if (is_sorted(vec.begin(), vec.end()))
    {
        cout << "Sorted " << endl;
    }
    else
    {
        cout << "Not Sorted " << endl;
    }

    // declaring pointer pair
    pair<vector<int>::iterator, vector<int>::iterator> mispair;
    mispair = mismatch(vec.begin(), vec.end(), sec_vec.begin());

    // printing the mismatch pair
    // 1st mismatch at 15 and 25
    cout << "The 1st mismatch element of 1st container : ";
    cout << *mispair.first << endl;

    cout << "The 1st mismatch element of 2nd container : ";
    cout << *mispair.second << endl;

    return 0;
}
