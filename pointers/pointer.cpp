#include<iostream>
using namespace std;

int main(){

    int num1=20;
    int *p = &num1;
    cout<<"The value of num1= "<<num1<<endl;
    cout<<"The address of num1 = "<<&num1<<endl;
    cout << "The value of num1 using pointer =" << *p << endl;
    cout << "The address of num1 using pointer = " << p << endl;

    int arr[5] = {10, 20, 30, 40, 50};
    int *pArr = arr;
    cout<<"The first element is "<<*pArr<<endl;
    cout<<"The first element is "<<*arr<<endl;
    for (int i = 0; i < 5; i++)
    {
        /* code */
    }
    

    return 0;
}