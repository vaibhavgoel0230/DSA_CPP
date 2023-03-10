#include <iostream>
#include "new_currency.h"

using namespace std;

int main()
{
    currency::signType plus = currency::plus;
    currency::signType minus = currency::minus;

    currency g, h(plus, 3, 50), i, j;

    // try out both forms of setValue
    g.setValue(minus, 2, 25);
    i.setValue(-6.45);

    // do an add and output
    j = h.add(g);
    h.output();
    cout << " + ";
    g.output();
    cout << " = ";
    j.output();
    cout << endl;

    // do two adds in a sequence
    j = i.add(g).add(h);
    i.output();
    cout << " + ";
    g.output();
    cout << " + ";
    h.output();
    cout << " = ";
    j.output();
    cout << endl;

    // do an increment and add
    j = i.increment(g).add(h);
    i.output();
    cout << " + ";
    g.output();
    cout << " + ";
    h.output();
    cout << " = ";
    j.output();
    cout << endl;

    // Take Input
    g.input();
    g.output();

    // calculate subtract and output
    j = h.subtract(g);
    h.output();
    cout << " - ";
    g.output();
    cout << " = ";
    j.output();
    cout << endl;

    // calculate percentage and output
    j = h.percent(1.5);
    h.output();
    cout << " % 1.5 = ";
    j.output();
    cout << endl;

    // calculate multiplication and output
    j = h.multiply(1.5);
    h.output();
    cout << " x 1.5 = ";
    j.output();
    cout << endl;

    // calculate division and output
    j = h.divide(1.5);
    h.output();
    cout << " / 1.5 = ";
    j.output();
    cout << endl;

    // test the exception
    cout << "Attempting to initialize with cents = 152" << endl;
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
