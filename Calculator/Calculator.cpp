#include<iostream>
using namespace std;

int addition(int x, int y){
    return x+y;
}

int subtraction(int x, int y){
    return x-y;
}

int multiplication(int x, int y){
    return x*y;
}

int division(int x, int y){
    return x/y;
}

int modulo(int x, int y){
    return x % y;
}

void exitProgram(){
    exit(0);
}

int main(){

    int choice;
    int num1;
    int num2;
    int result;

    while (true)
    {
        cout << "MENU" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Modulus" << endl;
        cout << "9. Exit" << endl;

        cout << "Enter the choice number of what you want to do: " << endl;

        cin >> choice;

        cout << "Enter the first number" << endl;
        cin >> num1;

        cout << "Enter the second number" << endl;
        cin >> num2;

        if (choice == 1)
        {
            result = addition(num1, num2);
            cout<<"The additon of the two nums is ="<<result<<endl;
        }else if (choice == 2)
        {
            result = subtraction(num1, num2);
            cout<<"The subtraction of the two nums is ="<<result<<endl;
        }
        else if (choice == 3)
        {
            result = multiplication(num1, num2);
            cout << "The product of the two nums is =" << result << endl;
        }
        else if (choice == 4)
        {
            result = division(num1, num2);
            cout << "The quotient of the two nums is =" << result << endl;
        }
        else if (choice == 5)
        {
            result = modulo(num1, num2);
            cout << "The modulus of the two is =" << result << endl;
        }else if (choice == 9)
        {
            exitProgram();
        }else
        {
            cout<<"Invalid choice number"<<endl;
        }
        
    }
    
    



    

    return 0;
}