/*---------------------------------------------------------------------
 Driver program to test the Stack class.
 ----------------------------------------------------------------------*/

#include <iostream>
#include <math.h>
using namespace std;


#include "Stack.h"

void storeStack(int posInt, Stack & stack);
string computeBinary(int posInt, Stack & stack);

int main()
{
    Stack stack;
    string binaryRep;
    int posInteger;
    
    cout << "Enter a number: ";
    cin >> posInteger;
    
    if(posInteger <= 0)
    {
        cout << "Incorrect input\n";
        exit(1);
    }
    
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

