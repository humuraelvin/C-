#include <iostream>
using namespace std;

int main()
{
    int product = 1;

    for (int i = 1; i <= 20; i += 2)
    {
        product *= i;
    }

    cout << "The product of all odd numbers between 1 and 20 is: " << product << endl;

    return 0;
}
