#include <iostream>
#include <string>

void printNameInReverse(const std::string &firstName, const std::string &lastName)
{
    std::cout << "Name in reverse is: " << lastName << " " << firstName << std::endl;
}

int main()
{
    std::string firstName, lastName;

    std::cout << "Input First Name: ";
    std::cin >> firstName;

    std::cout << "Input Last Name: ";
    std::cin >> lastName;

    printNameInReverse(firstName, lastName);
    return 0;
}
