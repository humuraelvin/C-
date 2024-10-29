#include <iostream>
using namespace std;


int countDigits(int num){
    if (num == 0)
    {
        return 0;
    }

    return 1 + countDigits(num / 10);
    
}

int sumOfDigits(int num){
    if (num == 0)
        return 0;
    

    return (num % 10) + sumOfDigits(num / 10);
    
}

int main(){

    int number;
    cout <<"Enter a number: ";
    cin >> number;

    if (number < 0)
    {
        number = -number;
    }

    int numberOfDigits = countDigits(number);
    int sum = sumOfDigits(number);

    cout <<"The number of digits in the number is: " << numberOfDigits <<endl;
    cout <<"The sum of the digits in the number is: " << sum <<endl; 
    

}