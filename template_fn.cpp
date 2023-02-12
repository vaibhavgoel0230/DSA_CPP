#include <iostream>
using namespace std;

template <typename T>
void fill_array(T arr[], int size)
{
    cout << "Enter " << size << " numbers for the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
int main()
{
    int arr[5];
    int size{5};
    fill_array<int>(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}