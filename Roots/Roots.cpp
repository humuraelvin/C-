#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, Delta, x1, x2;

    cout << "Enter coefficients a, b, and c: ";
    cin >> a >> b >> c;

    Delta = b * b - 4 * a * c; 

    if (Delta >= 0)
    {
        x1 = (-b + sqrt(Delta)) / (2 * a);
        x2 = (-b - sqrt(Delta)) / (2 * a);
        cout << "Roots: " << x1 << ", " << x2 << endl;
    }
    else
    {
        cout << "No real roots." << endl;
    }

    return 0;
}
