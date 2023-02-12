#include <iostream>
using namespace std;

// Modify Program 1.8 so that it throws an exception of type int. The value of
// the thrown exception should be 1 if a, b, and c are all less than 0; the value
// should be 2 if all three equal 0. When neither of these conditions is satisfied,
// no exception is throwWn. Write a main function that uses your modified code;
// catches the exception if thrown; and outputs a message that depends on the
// value of the thrown exception. Test your code.
// Do Exercise 2. Your code for the function should throw an exception of type
// char in case n <1. Test your code.

int abc(int a, int b, int c)
{
    if (a < 1 || b < 1 || c < 1)
    {
        throw "Parameter(s) should be greater than 0";
    }
    return a + b + c;
}

int main()
{
    try
    {
        cout << abc(0, 0, 0) << endl;
    }
    catch (const char *e)
    {
        cout << "An Exception has been thrown" << endl;
        cout << e << endl;
        return 1;
    }
}