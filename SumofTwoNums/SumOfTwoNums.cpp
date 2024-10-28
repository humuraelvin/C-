#include <iostream>
using namespace std;

template <typename T> T addTwoNums(T a, T b){
    return a + b;
}

template <typename T> T addTwoNums(T a, T b, T c){
    return a + b + c;
}

int main(){


    cout << "Result: "<<addTwoNums(10, 20) <<endl;
    cout << "Result: " << addTwoNums(10, 20, 30) << endl;
    cout << "Result: " << addTwoNums(10.5, 20.3) << endl;
    cout << "Result: " << addTwoNums(10.5, 20.3, 45.23) << endl;

    return 0;
}