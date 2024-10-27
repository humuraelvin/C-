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
    cout <<endl;
    
}

string chooseRandomWord(const vector<string>& words){
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}


int main(){

    srand(time(0));

    vector<string> animals = {"elephant", "tiger", "lion", "giraffe"};
    vector<string> teams = {"barcelona", "arsenal", "milan", "paris"};
    vector<string> movies = {"inception", "avatar", "matrix", "superman"};


    cout << "Welcome to the word Guessing Game" <<endl;

    cout <<"Choose any one category that you want" <<endl;
    cout <<"1. Animals"<<endl;
    cout <<"2. European clubs"<<endl;
    cout <<"3. Films"<<endl;

    int categoryChoice;
    cin >>categoryChoice;


    vector<string> choosenCategory;

    switch (categoryChoice)
    {
    case 1:
        choosenCategory = animals;
        break;

    case 2:
        choosenCategory = teams;
        break;

    case 3:
        choosenCategory = movies;
        break;
    
    default:
        cout <<"Invaid category choice" <<endl; return 0;
    }

    string wordToGuess = chooseRandomWord(choosenCategory);
    unordered_set<char> guessedLetters;
    int chances = 6;





    return 0;
}