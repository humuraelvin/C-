#include <iostream>
using namespace std;

void calculatePower(int number, int power){

    for (int i = 1; i < power; i++)
    {
        number *= number;
    }
    
    cout << "Result: " << number<< endl;

}

int main(){

    calculatePower(7, 2);

    return 0;
}