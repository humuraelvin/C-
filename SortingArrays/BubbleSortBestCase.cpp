#include <iostream>
using namespace std;

int main()
{
    int size, temp, i = 0;
    cout << "Enter size : ";
    cin >> size;
    int array[size];

    // Inputting array elements
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element : ";
        cin >> array[i];
    }

    // Bubble Sort algorithm (optimized)
    while (i < size - 1)
    {
        bool flag = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
                flag = true;
            }
        }
        if (!flag)
            break;
        i++;
    }

    // Outputting the sorted array
    cout << "Number of iterations : " << i << endl;
    cout << "Sorted array : ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}