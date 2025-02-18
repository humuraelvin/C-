#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class RPN
{
private:
    /* data */
public:
    
    int evalRPN(vector<string>& tokens){
        stack<int> stk;

       for (int i = 0; i < tokens.size(); i++)
       {
         if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
         {
            int v1 = stk.top();
            stk.pop();
            int v2 = stk.top();
            stk.pop();

            if (tokens[i] == "+")
            {
                stk.push(v2 + v1);
            }else if (tokens[i] == "-")
            {
                stk.push(v2 - v1);
            }else if (tokens[i] == "*")
            {
                stk.push(v2 * v1);
            }else if (tokens[i] == "/")
            {
                stk.push(v2 / v1);
            }     
            

         }else{
            stk.push(stoi(tokens[i]));
         }
         
       }
       
        return stk.top();
    }

};

int main(){

    RPN rpn;

    vector<string> vect = {"4", "13", "5", "/", "+"};

    cout<< rpn.evalRPN(vect) <<endl;

return 0;
}




