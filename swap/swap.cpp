#include<iostream>
using namespace std;

int main()
{

    int num1;
    int num2;
    int temp;


    cout << "Input 1nd number: ";
    cin >> num1;
    cout << "Input 2nd number: ";
    cin >> num2;

    temp = num1;
    num1 = num2;
    num2 = temp;
  

    std::cout << "1st number is: " << num1 << "\n";
    std::cout << "2nd number is: " << num2 << "\n";

    return 0;
}