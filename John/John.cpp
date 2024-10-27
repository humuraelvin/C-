// John is 1,000,000,000 seconds old; how old is John in terms of Years.

#include <iostream>

int main()
{
    long long secondsOld = 1000000000; 
    const int secondsInHour = 3600;
    const int secondsInDay = 24 * secondsInHour;
    const int secondsInWeek = 7 * secondsInDay;
    const int secondsInYear = 52 * secondsInWeek;

    double ageInYears = static_cast<double>(secondsOld) / secondsInYear;

    std::cout << "John is approximately " << ageInYears << " years old." << std::endl;

    return 0;
    
}

