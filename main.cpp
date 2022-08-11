// Author: Fransiskus Agapa

#include <iostream>
#include "string"
#include "cctype"                                  // check capital alphabet

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::isupper;

void Scramble(string user_inp)                    // assume the size of the word is 5
{
    if(user_inp.size() == 5)
    {
        cout << user_inp.at(4) << user_inp.at(2) << user_inp.at(0) << user_inp.at(3) << user_inp.at(1);
    }
    else if(user_inp.size() < 5)                   // not meet word's limit - 5 alphabets
    {
        cout << "(Word's limit is not reached)";
    }
    else
    {
        cout << "(Word's limit exceeded)";
    }
}

void Reverse(string user_inp)
{
    if(user_inp.size() == 5)
    {
        cout << user_inp.at(4) << user_inp.at(3) << user_inp.at(2) << user_inp.at(2) << user_inp.at(1) << user_inp.at(0);
    }
    else if(user_inp.size() < 5)
    {
        cout << "(Word's limit is not reached)";
    }
    else
    {
        cout << "(Word's limit exceeded)";
    }
}

int main()
{
    char choice;                                    // expect char only
    string userInput;

    std::cout << "\n== Word Operation ==" << std::endl;
    cout << "1. Input 5-letter Word" << endl;
    cout << "2. Capitalize" << endl;
    cout << "3. Scramble the word" << endl;
    cout << "4. Reverse the word" << endl;
    cout << "e. Exit" << endl;
    cout << "choice: ";
    cin >> choice;

    while(choice != 'e' and choice != 'E')
    {
        if(choice == '1')
        {
            cout << "\nInput 5-letter word: ";
            cin >> userInput;
            cout << "\n[ " << userInput << " added ]" << endl;
        }
        else if(choice == '2')
        {
            if(userInput.size() > 0)                                       // user input has to be put filled
            {
                bool isCapital = false;
                cout << "\n== Capitalize the word ==" << endl;

                if (!isupper(userInput.at(0)))                       // if the word is not capitalized
                {
                    cout << "\nBefore: " << userInput << endl;
                    isCapital = false;
                } else
                {
                    cout << "\n[ The word is capitalized: " << userInput << " ]" << endl;
                    isCapital = true;
                }

                if (!isCapital)                                              //   if the word is not capitalized
                {
                    userInput.at(0) = toupper(userInput.at(0));     // capitalize the first alphabet in the word
                    cout << "After: " << userInput << endl;
                }
            }
            else
            {
                cout << "\n[ Input a word first ]" << endl;
            }

        }

        else if(choice == '3')
        {
            if(userInput.size() == 0)
            {
                cout << "\n[ Input a word first ]" << endl;
            }
            else
            {
                cout << "\n== Scramble the word ==" << endl;
                cout << "\n[ The scrambled word: ";
                Scramble(userInput);
                cout << " ]" << endl;
            }
        }

        else if(choice == '4')
        {
            if(userInput.size() == 0)
            {
                cout << "\n[ Input a word first ]" << endl;
            }
            else
            {
                cout << "\n== Reverse the word ==" << endl;
                cout << "\n[ The reversed word: ";
                Reverse(userInput);
                cout  << " ]" << endl;
            }
        }

        else
        {
            cout << "\n[ Invalid choice ]" << endl;
        }

        std::cout << "\n== Word Operation ==" << std::endl;
        cout << "1. Input 5-letter Word" << endl;
        cout << "2. Capitalize" << endl;
        cout << "3. Scramble the word" << endl;
        cout << "4. Reverse the word" << endl;
        cout << "e. Exit" << endl;
        cout << "choice: ";
        cin >> choice;
    }

    if(choice == 'e' or choice == 'E')
    {
        cout << "\n== Exit Program ==" << endl;
    }

    return 0;
}

