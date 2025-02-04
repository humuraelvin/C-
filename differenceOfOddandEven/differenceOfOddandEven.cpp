#include <iostream>
using namespace std;

void calculateDifference(int numbers[]){
    int oddSum = 0;
    int evenSum = 0;
    int difference;


    int size = sizeof(numbers)/sizeof(numbers[0]);

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] % 2 == 0)
        {
            evenSum += numbers[i];
        }else
        {
            oddSum += numbers[i];
        }
              
    }
    
    difference = oddSum - evenSum;

    cout <<"The difference of the sum of odd and even numbers given in the array is: = "<< difference <<endl;
    

}


int main(){

    int numbers[] = {2, 24, 35, 47, 56, 77, 9, 10, 11};

    calculateDifference(numbers);


    return 0;
}