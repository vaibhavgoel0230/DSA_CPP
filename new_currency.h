#include <iostream>
using namespace std;

class currency
{
public:
    enum signType
    {
        plus,
        minus
    };
    // constructor
    currency(signType theSign = plus, unsigned long theDollars = 0, unsigned int the Cents = 0);
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
    currency add(const currency &) const;
    currency &increment(const currency &x)
    {
        amount += x.amount;
        return *this;
    }
    void output() const;

private:
    long amount;
}

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

currency currency ::add(const currency &x) const
{
    // Add x and *this
    currency y;
    y.amount = amount + x.amount;
    return y;
}

void currency ::output() const
{
    // Output currency value
    long theAmount = amount;
    if (theAmount < 0)
    {
        cout << '-';
        theAmount = -theAmount;
    }
    long dollars = theAmount / 100;        // dollars
    int cents = theAmount - dollars * 100; // cents
    cout << '$' << dollars << '.';
    if (cents < 10)
        cout << '0';
    cout << cents;
}