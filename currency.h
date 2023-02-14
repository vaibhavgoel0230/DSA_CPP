#include <iostream>
#include <stdexcept>

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
    currency(signType theSign = plus, unsigned long theDollars = 0, unsigned int theCents = 0);

    // destructor
    ~currency(){};

    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);

    signType getSign() const { return sign; }
    unsigned long getDollars() const { return dollars; }
    unsigned int getCents() const { return cents; }

    currency add(const currency &) const;
    currency increment(const currency &);
    void output() const;

private:
    signType sign;
    unsigned long dollars;
    unsigned int cents;
};

currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
    setValue(theSign, theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
    // Set Currency Value
    if (theCents > 99)
    {
        // too many cents
        throw invalid_argument("Cents should be < 100");
    }
    sign = theSign;
    dollars = theDollars;
    cents = theCents;
}

void currency::setValue(double theAmount)
{
    // Set Currency Value
    if (theAmount < 0)
    {
        sign = minus;
        theAmount = -theAmount;
    }
    else
    {
        sign = plus;
    }
    dollars = static_cast<unsigned long>(theAmount); // extract integer part
    cents = static_cast<unsigned int>((theAmount - dollars) * 100);
}

currency currency::add(const currency &x) const
{
    // Add x and *this
    long a1, a2, a3;
    currency result;
    // convert invoking object to signed integers
    a1 = dollars * 100 + cents;
    if (sign == minus)
    {
        a1 = -a1;
    }

    // convert x to signed integers
    a2 = x.dollars * 100 + x.cents;
    if (x.sign == minus)
    {
        a2 = -a2;
    }

    a3 = a1 + a2;

    // convert to currency representation
    if (a3 < 0)
    {
        result.sign = minus;
        a3 = -a3;
    }
    else
    {
        result.sign = plus;
    }
    result.dollars = a3 / 100;
    result.cents = a3 % 100;

    return result;
}

currency currency::increment(const currency &x)
{
    // Increment by x
    *this = add(x);
    return *this;
}

void currency::output() const
{
    // output currency value
    if (sign == minus)
    {
        cout << '-';
    }
    cout << '$' << dollars << '.';
    if (cents < 10)
    {
        cout << '0';
    }
    cout << cents;
}
