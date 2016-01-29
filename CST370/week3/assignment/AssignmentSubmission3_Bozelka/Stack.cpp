
/*--------------------------------------------------------------------
 Title: Programming Assignment 3 - (Queues) - Bozelka
 File: cpp file for Stack
 Abstract: This assignment takes in a string of text from the user.
 It then stores that string into a Queue and Stack respectivley.
 The program then uses the operations of a Stack and Queue to determine
 if the text entered is a palandrome or not.
 Author: Matthew Bozelka
 ID: 002276039
 Date: 01/25/2016
 --------------------------------------------------------------------*/

/*-- Stack.cpp-------------------------------------------------------------
 This file implements Stack member functions.
 --------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "Stack.h"

//--- Definition of Stack constructor
Stack::Stack()
: myTop(-1)
{}

//--- Definition of empty()
bool Stack::empty() const
{
    return (myTop == -1);
}

//--- Definition of push()
void Stack::push(const StackElement & value)
{
    if (myTop < STACK_CAPACITY - 1) //Preserve stack invariant
    {
        ++myTop;
        myArray[myTop] = value;
    }
    else
    {
        cerr << "*** Stack full -- can't add new value ***\n"
        "Must increase value of STACK_CAPACITY in Stack.h\n";
        exit(1);
    }
}

//--- Definition of display()
void Stack::display(ostream & out) const
{
    for (int i = myTop; i >= 0; i--)
        out << myArray[i];
    cout << endl;
}

//--- Definition of top()
StackElement Stack::top() const
{
    if ( !empty() )
        return (myArray[myTop]);
    else
    {
        cerr << "*** Stack is empty -- returning garbage value ***\n";
        StackElement garbage = 0;
        return garbage;
    }
}

//--- Definition of pop()
void Stack::pop()
{
    if ( !empty() )
        myTop--;
    else
        cerr << "*** Stack is empty -- can't remove a value ***\n";
}