#include <iostream>
#include <vector>
using namespace std;

void grayCodeHelper(int n, vector<int> &result)
{
    if (n == 1)
    {
        result.push_back(1);
    }
    else
    {
        grayCodeHelper(n - 1, result);
        result.push_back(n);
        int size = result.size();
        for (int i = size - 2; i >= 0; i--)
        {
            result.push_back(result[i]);
        }
    }
}

vector<int> grayCode(int n)
{
    vector<int> result;
    grayCodeHelper(n, result);
    return result;
}

int main()
{
    vector<int> result = grayCode(4);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
