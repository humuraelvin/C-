#include <iostream>
using namespace std;

int  printFactorial(int n){

    if (n == 0 || n == 1)
    {
        return 1;
    }else
    {
        return n * printFactorial(n - 1);
    }
    
    


}


int main(){

    cout <<"Result: "<<printFactorial(10)<<endl;

}