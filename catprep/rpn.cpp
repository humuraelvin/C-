#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class RPN
{

    public:

    int evalRPN(vector<string>&tokens){

        stack<int> st;

        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int v1 = st.top();
                st.pop();

                int v2 = st.top();
                st.pop();

                if (tokens[i] == "+")
                {
                    st.push(v2 + v1);
                }else if (tokens[i] == "-")
                {
                    st.push(v2 - v1)
                }
                else if (tokens[i] == "*")
                {
                    st.push(v2 * v1)
                }
                else if (tokens[i] == "/")
                {
                    st.push(v2 / v1);
                }
            }else
            {
                st.push(stoi(tokens[i]));
            }
            
        }
    return st.top();
    }

};


int main(){

    RPN rpn;

    vector<string> vect = {"4", "13", "5", "/", "+"};
    cout<<rpn.evalRPN(vect);

    return 0;
}
