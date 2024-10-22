#include <iostream>

float celsiusToFahrenheit(float celsius)
{
    return (celsius * 9.0 / 5.0) + 32;
}

int main()
{
    float celsius;
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;

    float fahrenheit = celsiusToFahrenheit(celsius);
    std::cout << celsius << "°C is " << fahrenheit << "°F" << std::endl;

    return 0;
}
