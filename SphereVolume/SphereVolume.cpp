#include <iostream>
using namespace std;
#include <cmath> 

using namespace std;

int main()
{
    double radius, volume;

    cout << "Enter the radius of the sphere: ";
    cin >> radius;

    volume = (4.0 / 3.0) * M_PI * pow(radius, 3);

    cout << "The volume of the sphere is:  = " << volume << endl;

    return 0;
}
