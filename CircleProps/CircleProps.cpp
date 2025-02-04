#include <iostream>
#include <cmath>
using namespace std;

double computeArea(double radius)
{
    return M_PI * radius * radius;
}

double computeCircumference(double radius)
{
    return 2 * M_PI * radius;
}

int main()
{
    double radius;

    cout << "Enter the radius of the circle: ";
    cin >> radius;

    cout << "Area of the circle: " << computeArea(radius) << endl;
    cout << "Circumference of the circle: " << computeCircumference(radius) << endl;

    return 0;
}
