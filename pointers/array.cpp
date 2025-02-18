// #include<iostream>
// using namespace std;


// int main(){

//  int a[5] = {10, 20, 30, 40 , 50};

//     int sum, i

//  for(sum = *a, i=1; i < 5; i++)
//  {
//     sum+=*(a+i);
//  }

//  cout<<sum<<endl;
 

// }


#include<iostream>
using namespace std;

int main(){

    int a[5] = {10, 20, 30, 40, 50};

    int sum, i;

    int *ptr;
    ptr = a;

    for (sum = *a, ptr = a + 1; ptr < a + 5; ptr++)
    {
        sum += *ptr;
    }
    

}