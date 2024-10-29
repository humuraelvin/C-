#include <iostream>
using namespace std;

int  printFactorial(int n){

    return n * printFactorial(n - 1);

}


int main(){

    cout <<"Result: "<<printFactorial(10)<<endl;

}