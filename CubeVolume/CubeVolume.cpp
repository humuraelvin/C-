#include <iostream>
using namespace std;

// Function to compute the volume of a cube
double computeVolume(double side)
{
    return side * side * side;
}

int main()
{
    double side;

    cout << "Enter the side length of the cube: ";
    cin >> side;

    cout << "Volume of the cube: " << computeVolume(side) << endl;

    return 0;
}
