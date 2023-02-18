#include <iostream>
#include "operator_overloading.h"
using namespace std;

int main()
{
    currency ::signType plus = currency ::plus;
    currency ::signType minus = currency ::minus;

    currency g, h(plus, 3, 50), i, j;

    g = -2.25;
    i = 140;

    // do an add and output
    j = h + g;
    cout << h << " + " << g << " = " << j << endl;

    // do two adds in a sequence
    j = i + g + h;
    cout << i << " + " << g << " + " << h << " = " << j << endl;

    // do an increment and add
    cout << "Increment " << i << " by " << g << " and then add " << h << endl;
    j = (i += g) + h;

    cout << "Result is " << j << endl;
    cout << "Incremented object is " << i << endl;

    cin >> g;
    cout << g << endl;

    // subtract g from h
    cout << h << " - " << g << " = " << h - g << endl;

    // Multiply g and h
    cout << h << " * " << g << " = " << h * 1.50 << endl;

    // Divide h with g
    cout << h << " / " << g << " = " << h / 1.50 << endl;

    // g percent of h
    cout << h << " % " << g << " = " << h % 1.50 << endl;

    // test the exception
    cout << "Attempting to initialize with cents > 100" << endl;
    try
    {
        i.setValue(plus, 3, 152);
    }
    catch (invalid_argument &e)
    {
        cout << "Caught thrown exception." << endl;
        cout << e.what() << endl;
    }

    return 0;
}