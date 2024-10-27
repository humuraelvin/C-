#include <iostream>
#include <vector>
#include <unordered_set>
#include <ctime>
#include <cstdlib>
using namespace std;

void displayWord(const string& word, const unordered_set<char>& guessedLetters){
    for (char c : word) 
    {
        if (guessedLetters.count(c))
        {
            cout << c;
        }else{
            cout << '_';
        }
        
    }
    
}


int main(){



    return 0;
}