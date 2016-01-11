
/*--------------------------------------------------------------------
 Title: Assignment 1 - Linked Lists - Bozelka
 File: main test for LinkedList Assignment
 Abstract: This assigment a few methods were added to the linked list
           which allow a user to search and test for substrings
           starting with an A and ending with a B. The program then
           outputs those substring to the screen and counds how many
           total substrings were found.
 Author: Matthew Bozelka
 ID: 002276039
 Date: 01/10/2016
 --------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "LinkedList.h"


/*
    helper function:
    pre condiction: expects a string, and a reference to a linked list
    post condition: makes all chars in the string uppercase and removes spaces.
                    then stores into the referenced list
 
*/
void storeInputInList(string input, LinkedList & list);

int main()
{

    string userInput;
    LinkedList userIntputAsList;
    
    // get a line of text from user
    cout << "Enter a string of characters:\n";
    getline(cin, userInput);
    
    // store the text entered by user into the LinkedList
    storeInputInList(userInput, userIntputAsList);
    
    // print LinkedList to screen for testing
    cout << "LinkedList based on user input\n";
    userIntputAsList.display(cout);
    cout << endl << endl;
    
    userIntputAsList.findSublists('A', 'B');
    
}


// helper function
void storeInputInList(string input, LinkedList & list)
{
    int index = 0;
    for (char c : input)
    {
        if(!isblank(c))
        {
            list.insert(toupper(c), index);
            index++;
        }
    }
}