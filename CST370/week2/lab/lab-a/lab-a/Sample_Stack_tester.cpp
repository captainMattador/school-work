/*---------------------------------------------------------------------
 Driver program to test the Stack class.
 ----------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "Stack.h"

/*
 helper function:
 pre condiction: expects a string, and a reference to a linked list
 post condition: makes all chars in the string uppercase and removes spaces.
 then stores into the referenced list
 
 */
void storeInputInStack(string input, Stack & stack);
void reverseStack(Stack & stack);

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
