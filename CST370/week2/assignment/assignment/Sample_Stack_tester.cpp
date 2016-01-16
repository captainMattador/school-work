/*---------------------------------------------------------------------
 Driver program to test the Stack class.
 ----------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "Stack.h"

void displayStack(Stack & stack);
void sortStack(Stack & stack1, Stack & stack2);

int main()
{
    Stack stack1, stack2;
    
    /***************
     testing stack one
     ***************/
    stack1.push(1);
    stack1.push(5);
    stack1.push(3);
    stack1.push(-3);
    stack1.push(4);
    stack1.push(8);
    stack1.push(10);
    stack1.push(-5);
    
    /***************
     testing stack two
     ***************/
//    stack1.push(10);
//    stack1.push(-1);
//    stack1.push(-5);
//    stack1.push(-4);
//    stack1.push(-6);
//    stack1.push(-2);
    
    
    /***************
     testing stack three
     ***************/
//    stack1.push(-1);
//    stack1.push(-4);
//    stack1.push(-4);
//    stack1.push(6);
//    stack1.push(6);
//    stack1.push(9);
    
    sortStack(stack1, stack2);
    
    cout << "Sorted Stack: ";
    displayStack(stack2);
}

void sortStack(Stack & stack1, Stack & stack2)
{
    while(!stack1.empty())
    {
        int tempVal = stack1.top();
        stack1.pop();
        
        while(!stack2.empty() && tempVal < stack2.top())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        
        stack2.push(tempVal);
    }
}

void displayStack(Stack & stack)
{
    while (!stack.empty()) {
        cout << stack.top();
        stack.pop();
        if(!stack.empty())
            cout << ", ";
    }
    cout << endl;
}

