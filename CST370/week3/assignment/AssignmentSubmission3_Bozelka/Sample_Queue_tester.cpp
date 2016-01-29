/*--------------------------------------------------------------------
 Title: Programming Assignment 3 - (Queues) - Bozelka
 File: Driver for the Assignment
 Abstract: This assignment takes in a string of text from the user.
 It then stores that string into a Queue and Stack respectivley.
 The program then uses the operations of a Stack and Queue to determine
 if the text entered is a palandrome or not.
 Author: Matthew Bozelka
 ID: 002276039
 Date: 01/25/2016
 --------------------------------------------------------------------*/


/*---------------------------------------------------------------------
 Driver program to test the Queue class.
 ----------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "Queue.h"
#include "Stack.h"


/*
 helper function:
 pre condiction: expects a reference to a Stack name stack, 
                 and a reference to a Queue name queue
                 and a string named str
 post condition: Loops the string character by character and stores each
 character into both the Queue and the Stack (assuming it's not a special character).
 */
void storeUserInput(Stack & stack, Queue & queue, string str);

/*
 helper function:
 pre condiction: expects a char named current
 post condition: checks if the char is a special character by checking
 it against a set of acceptable chars and returns true if it is a
 special character or false if it is in the acceptable list.
 */
bool isSpecialChar(char current);

/*
 helper function:
 pre condiction: expects a reference to a Stack named stack, a reference to a Queue named queue
 post condition: Uses the stack and queue operations to determine if their contents are
 a palindrome.
 */
bool isPalindrome(Stack & stack, Queue & queue);

int main()
{
    
    Stack stack;
    Queue queue;
    string userInput;
    bool isPal;
    
    cout << "Only letters and numbers will be consider\n";
    cout << "Enter a string of text and see if it is a palindrome:\n";
    getline(cin, userInput);
    
    if(userInput.length() <=0)
    {
        cout << "You entered an empty string\n";
        exit(1);
    }
    
    storeUserInput(stack, queue, userInput);
    isPal = isPalindrome(stack, queue);
    
    if(isPal)
        cout << userInput << " is a Palindrome!\n";
    else
        cout << userInput << " is NOT a Palindrome!\n";
    
}

void storeUserInput(Stack & stack, Queue & queue, string str)
{
    for(char c : str)
    {
        char temp = tolower(c);
        if(!isSpecialChar(temp))
        {
            stack.push(temp);
            queue.enqueue(temp);
        }
    }
}

bool isPalindrome(Stack & stack, Queue & queue)
{
    if(stack.empty() || queue.empty())
        return false;
    
    while (!stack.empty() && !queue.empty()) {
        if(stack.top() != queue.front())
            return false;
        
        stack.pop();
        queue.dequeue();
    }
    
    return true;
}

bool isSpecialChar(char current)
{
    const string ACCEPTABLE = "abcdefghijklmnopqrstuvwxyz1234567890";
    for(char c : ACCEPTABLE)
    {
        if(current == c)
            return false;
    }
    return true;
}