#include <iostream>
using namespace std;

bool isPalindrome(string s)
{
    int start = 0, end = s.length() - 1;

    while (start < end)
    {
        while (start < end && !isalpha(s[start]))
            start++;
        while (start < end && !isalpha(s[end]))
            end--;

        if (tolower(s[start]) != tolower(s[end]))
        {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (isPalindrome(input))
        cout << "The word entered is a Palindrome!" << endl;
    else
        cout << "The word entered is Not a palindrome." << endl;

    return 0;
}
