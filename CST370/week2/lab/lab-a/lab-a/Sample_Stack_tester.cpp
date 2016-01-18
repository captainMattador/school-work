/*--------------------------------------------------------------------
 Title: Lab 2 Part A - Stacks - Bozelka
 File: main test for week 2 Lab Part A
 Abstract: This portion of the Lab uses a Stack of Chars, to store
 the input of some text from the user. The driver then prints the
 User input backwards by utilizing the Stacks Last-In-First-Out
 mechanism.
 Author: Matthew Bozelka
 ID: 002276039
 Date: 01/18/2016
 --------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "Stack.h"

/*
 helper function:
 pre condiction: expects a string named input, and a reference to a stack named stack
 post condition: Stores each char in input into the Stack stack.
 */
void storeInputInStack(string input, Stack & stack);

int main()
{
    Stack stack;
    string userInput, reversed = "";
    cout << "Stack created.  Empty? " << boolalpha << stack.empty() << endl;
    
    // get a line of text from user
    cout << "Enter a string of characters => ";
    getline(cin, userInput);
    
    cout << "You entered: " + userInput << endl;;
    
    storeInputInStack(userInput, stack);
    
    while(!stack.empty()){
        reversed += stack.top();
        stack.pop();
    }
    cout << "Reverse is " << reversed << endl;
    
}


// helper functions
void storeInputInStack(string input, Stack & stack)
{
    for (char c : input)
        stack.push(c);
}
