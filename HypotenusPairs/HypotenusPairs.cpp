#include <iostream>
#include <cmath> 
using namespace std;

void findHypotenusePairs()
{
    int count = 0;

    for (int a = 2; a < 100; a++)
    {
        for (int b = a; b < 100; b++)
        {                                  
            double c = sqrt(a * a + b * b); 

            if (c == static_cast<int>(c) && c < 100)
            {
                cout << "(" << a << ", " << b << ") with hypotenuse " << static_cast<int>(c) << endl;
                count++;
            }
        }
    }

    cout << "Total pairs found: " << count << endl;
}

int main()
{
    findHypotenusePairs();
    return 0;
}
