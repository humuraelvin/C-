#include <iostream>
using namespace std;

int findPower(int num, int power){
    if (power == 0)
    {
        return 1;
    }else if (power == 1)
    {
        return num;
    }else
    {
        return num * findPower(num, power - 1);
    }
    
    

    
    
}

int main(){

    cout<< findPower(10, 2)<<endl;

}