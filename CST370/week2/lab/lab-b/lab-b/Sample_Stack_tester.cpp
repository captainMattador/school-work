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
 post condition: based on posInt, the function then stores the values needed
 to compute a binary representation of posInt into the stack reference.
 */
void storeStack(int posInt, Stack & stack);

/*
 helper function:
 pre condiction: expects an int named posInt, and a reference to a stack named stack
 post condition: computes the binary representation of posInt, based on the stack
 values
 */
string computeBinary(int posInt, Stack & stack);

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
    
    storeStack(posInteger, stack);
    binaryRep = computeBinary(posInteger, stack);
    
    cout << "Binary: " << binaryRep << endl;
    
}

void storeStack(int posInt, Stack & stack)
{
    for(int i = 0; i < posInt; i++)
    {
        int powerOf = pow(2, i);
        if(powerOf > posInt)
            break;
        
        stack.push(powerOf);
    }
}

string computeBinary(int posInt, Stack & stack)
{
    
    string binary = "";
    while(!stack.empty())
    {
        if(posInt - stack.top() >= 0)
        {
            binary += "1";
        }else{
            binary += "0";
        }
        
        posInt %= stack.top();
        stack.pop();
    }
    
    return binary;
}

