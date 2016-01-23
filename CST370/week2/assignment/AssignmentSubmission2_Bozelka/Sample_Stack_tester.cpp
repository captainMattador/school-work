/*--------------------------------------------------------------------
 Title: Assignment 2 - Programming Assignment (Stacks) - Bozelka
 File: main test for week 2 Programming Assignment
 Abstract: This programming assignment uses two stacks to assort
 one of the stacks items into ascending order. The end of the 
 process should make the assorted stacks top item the largest value.
 Author: Matthew Bozelka
 ID: 002276039
 Date: 01/18/2016
 --------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "Stack.h"


/*
 helper function:
 pre condiction: expects a reference to a stack named stack1, and another stack named stack2
 post condition: takes stack one and assorts it in decending order into stack 2.
 */
void sortStack(Stack & stack1, Stack & stack2);

/*
 helper function:
 pre condiction: expects a reference to a stack named stack
 post condition: Pops each element out of the stack and prints it to the screen
 */
void displayStack(Stack & stack);

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
//    stack1.push(1);
//    stack1.push(5);
//    stack1.push(-4);
//    stack1.push(6);
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
    
    /***************
    all negative test
     ***************/
//    stack1.push(-1);
//    stack1.push(-4);
//    stack1.push(-4);
//    stack1.push(-3);
//    stack1.push(-100);
//    stack1.push(-2);
//    stack1.push(-1);
//    stack1.push(-97);
    
    cout << "Unsorted Stack: \n";
    stack1.display(cout);
    
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
    if(stack.empty())
    {
        cout << "No items in stack" << endl;
        return;
    }
    
    while (!stack.empty()) {
        cout << stack.top();
        stack.pop();
        if(!stack.empty())
            cout << ", ";
    }
    cout << endl;
}

