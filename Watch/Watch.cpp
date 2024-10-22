#include <iostream>
#include <ctime>

void displayCurrentDateTime()
{
    std::time_t now = std::time(nullptr);
    std::cout << "Current date and time: " << std::ctime(&now);
}

int main()
{
    displayCurrentDateTime();
    return 0;
}
