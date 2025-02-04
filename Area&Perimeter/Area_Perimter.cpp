#include <iostream>
using namespace std;

int main()
{
    double width, length;

    cout << "Enter width and length: ";
    cin >> width >> length;

    double area = width * length;
    double perimeter = 2 * (width + length);

    cout << "Area: " << area << ", Perimeter: " << perimeter << endl;

    return 0;
}
