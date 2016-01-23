/*---------------------------------------------------------------------
 Driver program to test the Queue class.
 ----------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "Queue.h"
#include "Stack.h"


void storeUserInput(Stack & stack, Queue & queue, string str);
bool isSpecialChar(char current);
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