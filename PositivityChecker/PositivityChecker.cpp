#include <iostream>

void checkNumber(int num)
{
    if (num > 0)
    {
        std::cout << num << " is positive." << std::endl;
    }
    else if (num < 0)
    {
        std::cout << num << " is negative." << std::endl;
    }
    else
    {
        std::cout << "The number is zero." << std::endl;
    }
}

int main()
{
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    checkNumber(number);
    return 0;
}
