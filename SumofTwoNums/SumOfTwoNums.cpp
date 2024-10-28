#include <iostream>
using namespace std;

int addTwoNums(int a, int b){
    return a+b;
}

int addTwoNums(int a, int b, int c){
    return a+b+c;
}

int addTwoNums(double a, double b){
    return a + b;
}

int addTwoNums(double a, double b, double c){
    return a+b+c;
}

int main(){

    cout << "Result: "<<addTwoNums(10, 20) <<endl;
    cout << "Result: " << addTwoNums(10, 20, 30) << endl;
    cout << "Result: " << addTwoNums(10.5, 20.3) << endl;
    cout << "Result: " << addTwoNums(10.5, 20.3, 45.23) << endl;

    return 0;
}