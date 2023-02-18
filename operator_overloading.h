#include <iostream>
using namespace std;

class currency
{
public:
    friend istream &operator>>(istream &, currency &x);
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
    void output(ostream &) const;
    currency operator-(const currency &) const;
    currency operator*(double) const;
    currency operator/(double) const;
    currency operator%(double) const;
    void operator=(int);
    void operator=(double);

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

currency currency::operator-(const currency &x) const
{
    // Subtract x and *this
    currency y;
    y.amount = amount - x.amount;
    return y;
}

currency currency::operator%(const double x) const
{
    // x percent of *this
    currency y;
    y.amount = amount * (x / 100);
    return y;
}

currency currency::operator*(const double x) const
{
    // Multiply x and *this
    currency y;
    y.amount = amount * x;
    return y;
}

currency currency::operator/(const double x) const
{
    // Divide x and *this
    currency y;
    y.amount = amount / x;
    return y;
}

void currency ::output(ostream &out) const
{
    // Insert currency value into stream out
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

// overload <<
ostream &operator<<(ostream &out, const currency &x)
{
    x.output(out);
    return out;
}

istream &operator>>(istream &in, currency &x)
{
    char signChar, decimal_point;
    unsigned long dollars;
    unsigned int cents;
    in >> signChar >> dollars >> decimal_point >> cents;
    // set currency value
    if (cents > 99)
    {
        // too many cents
        throw invalid_argument("Cents should be < 100.");
    }
    double amount = (dollars + cents * .01);
    if (signChar == '-')
    {
        amount = -amount;
    }

    if (amount < 0)
    {
        x.amount = (long)((amount - 0.001) * 100);
    }
    else
    {
        x.amount = (long)((amount + 0.001) * 100);
    }

    return in;
}

void currency ::operator=(int x)
{
    if (x < 0)
        amount = -x;
    else
        amount = x;
}

void currency ::operator=(double x)
{
    if (x < 0)
    {
        amount = (long)((x - 0.001) * 100);
    }
    else
    {
        amount = (long)((x + 0.001) * 100);
    }
}