#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {

           // cout<<"i="<<i<<" j = "<<j<<" i*j = "<<i*j<<endl;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; 
    }
    cout << endl; 
}

int main()
{

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // {9, 7, 2, 5, 4, 10, 3, 8, 1, 6}

    int n = sizeof(arr) / sizeof(arr[0]);


    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}