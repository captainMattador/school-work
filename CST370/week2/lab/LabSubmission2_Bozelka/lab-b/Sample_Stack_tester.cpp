/*--------------------------------------------------------------------
 Title: Lab 2 Part B - Stacks - Bozelka
 File: Driver for Lab Part B
 Abstract: This portion of the Lab uses a Stack of ints, and asks a user
 for a positive initger. The Positive integer is the converted to a
 binary representation and outputed to the screen.
 Author: Matthew Bozelka
 ID: 002276039
 Date: 01/18/2016
 --------------------------------------------------------------------*/

#include <iostream>
#include <math.h>
using namespace std;


#include "Stack.h"

/*
 helper function:
 pre condiction: expects an int named posInt, and a reference to a stack named stack
 post condition: based on posInt, the function then stores the values of a base 10
 integer as a base 2 representation in a stack
 */
void storeStackAsBinary(int posInt, Stack & stack);


int main()
{
    Stack stack;
    string binaryRep;
    int posInteger;
    
    do{
        cout << "Enter a positive intiger: ";
        cin >> posInteger;
        cin.clear();
        cin.ignore(10000, '\n');
        
        if(posInteger <= 0){
            cout << "\nBad Input (try again)\n";
        }
    }while(posInteger <= 0);
        
    cout << "Decimal: " << posInteger << endl;
    
    storeStackAsBinary(posInteger, stack);
    
    cout << "Binary: ";
    stack.display(cout);
    
}

void storeStackAsBinary(int posInt, Stack & stack)
{
    while ( posInt != 0 )
    {
        stack.push(posInt%2);
        posInt = posInt/2;
    }
}

