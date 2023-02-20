#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(int n, vector<int> subset, vector<int> new_subset)
{
    if (n == subset.size())
    {
        for (int i = 0; i < new_subset.size(); i++)
        {
            cout << new_subset[i];
        }
        cout << endl;
    }
    else
    {
        generateSubsets(n + 1, subset, new_subset);
        new_subset.push_back(subset[n]);
        generateSubsets(n + 1, subset, new_subset);
    }
}

int main()
{
    int n = 3;
    vector<int> subset = {1, 2, 3};
    vector<int> new_subset;
    generateSubsets(0, subset, new_subset);
    return 0;
}
