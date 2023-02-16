#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
using namespace std;
class currency
{
public:
    friend ostream &operator<<(ostream &, const currency &);
    enum signType
    {
        plus,
        minus
    };
    // constructor
    currency(signType theSign = plus, unsigned long theDollars = 0, unsigned int theCents = 0);
    // destructor
    ~currency() {}

    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);
    signType getSign() const
    {
        if (amount < 0)
            return minus;
        else
            return plus;
    }
    unsigned long getDollars() const
    {
        if (amount < 0)
            return (-amount) / 100;
        else
            return amount / 100;
    }
    unsigned int getCents() const
    {
        if (amount < 0)
            return (-amount) - getDollars() * 100;
        else
            return amount - getDollars() * 100;
    }
    currency operator+(const currency &) const;
    currency &operator+=(const currency &x)
    {
        amount += x.amount;
        return *this;
    }

private:
    long amount;
};

currency ::currency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
    setValue(theSign, theDollars, theCents);
}

void currency ::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
    // set currency value
    if (theCents > 99)
    {
        // too many cents
        throw invalid_argument("Cents should be < 100.");
    }

    amount = theDollars * 100 + theCents;
    if (theSign == minus)
        amount = -amount;
}

void currency ::setValue(double theAmount)
{
    if (theAmount < 0)
    {
        amount = (long)((theAmount - 0.001) * 100);
    }
    else
    {
        amount = (long)((theAmount + 0.001) * 100);
    }
}

currency currency ::operator+(const currency &x) const
{
    // Add x and *this
    currency y;
    y.amount = amount + x.amount;
    return y;
}

// overload <<
ostream &operator<<(ostream &out, const currency &x)
{
    // Insert currency value into stream out
    long theAmount = x.amount;
    if (theAmount < 0)
    {
        out << '-';
        theAmount = -theAmount;
    }
    long dollars = theAmount / 100;        // dollars
    int cents = theAmount - dollars * 100; // cents
    out << '$' << dollars << '.';
    if (cents < 10)
        out << '0';
    out << cents;
    return out;
}

#endif