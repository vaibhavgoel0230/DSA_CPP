#include <iostream>
#include <stdexcept>
#include <string>

class IllegalParameterValue : public std::runtime_error
{
public:
    IllegalParameterValue(const std::string &message)
        : std::runtime_error(message)
    {
    }
};

int abc(int a, int b, int c)
{
    if (a < 1 || b < 1 || c < 1)
    {
        throw IllegalParameterValue("All parameters should be greater than 0.");
    }
    return a + b + c;
}

int main()
{
    try
    {
        std::cout << abc(2, 0, 4) << std::endl;
    }
    catch (const IllegalParameterValue &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
