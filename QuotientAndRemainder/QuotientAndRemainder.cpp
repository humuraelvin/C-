#include <iostream>

void computeQuotientAndRemainder(int a, int b, int &quotient, int &remainder)
{
    quotient = a / b;
    remainder = a % b;
}

int main()
{
    int num1, num2, quotient, remainder;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    computeQuotientAndRemainder(num1, num2, quotient, remainder);
    std::cout << "Quotient: " << quotient << ", Remainder: " << remainder << std::endl;

    return 0;
}
