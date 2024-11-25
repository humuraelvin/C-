#include <iostream>
using namespace std;

template <typename T>
    T multiply(T a, T b){
        return a*b;
    }

    int main(){

        cout<<"Result: "<<multiply<int>('a','b')<<endl;
        cout<<"Result: "<<multiply<double>(5.2, 6.5)<<endl;

    }