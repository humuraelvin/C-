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

    vector<string> animals = {"snake", "rat", "dog", "bufalo"};
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
        cout <<"Invalid category choice" <<endl; return 0;
    }

    string wordToGuess = chooseRandomWord(choosenCategory);
    unordered_set<char> guessedLetters;
    int chances = 6;


    while (chances > 0)
    {
        displayWord(wordToGuess, guessedLetters);

        cout <<"Guess a letter or type exit to quit: ";
        string input;
        cin >>input;

        if (input == "exit"){
            cout <<"Thanks for playing"<<endl;
            break;
        }

        if (input.size() != 1 || !isalpha(input[0]))
        {
            cout <<"Please input a single letter."<<endl;
            continue;
        }
        
        char guess = tolower(input[0]);

        if (guessedLetters.count(guess)){
            cout<<"You already guessed that letter! "<<endl;
            continue;
        }

        guessedLetters.insert(guess);

        if (wordToGuess.find(guess) == string::npos)
        {
            chances--;
            cout<<"Incorrect guess"<<endl;
            cout<<"Chances left: "<< chances <<endl;
        }
        

        bool allGuessed = true;

        for (char c: wordToGuess)
        {
            if (!guessedLetters.count(c))
            {
                allGuessed = false;
                break;
            }
            
        }

        if (allGuessed)
        {
            cout<<"Congratulations!!! word guessed completely: "<< wordToGuess <<endl;

            cout << "Do you want to play again (y/n): ";
            char playAgain;
            cin >> playAgain;

            if (playAgain == 'y' || playAgain == 'Y')
            {
                main();
            }
            else
            {
                cout << "Thanks for playing" << endl;
            }
        }   
        
    }

    if (chances == 0)
    {
        cout << "So sorry but u are Out of chances! The word was: " << wordToGuess << endl;
    }


    cout <<"Do you want to play again (y/n): ";
    char playAgain;
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y')
    {
        main();
    }else {
        cout <<"Thanks for playing"<<endl;
    }
    

    return 0;
}