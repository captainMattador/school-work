
/*--------------------------------------------------------------------
 Title: Lab 1 - Linked Lists - Bozelka
 File: main test for LinkedList Lab Assignment
 Abstract: This lab builds on to a supplied linked list adding methods
           to find and return the maximum value stored in the linked
           list and another method to determine if the linked list
           is in ascending order
 Author: Matthew Bozelka
 ID: 002276039
 Date: 01/10/2016
 --------------------------------------------------------------------*/


#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
    
    // Test the class constructor
    LinkedList intList;
    cout << "Constructing intList\n\n";
    
    // tests for maxItem - Lab part a
    cout << "******* Testing maxItem *******\n\n";
    
    intList.insert(9, 0);
    intList.insert(17, 1);
    intList.insert(22, 2);
    intList.insert(26, 3);
    intList.insert(34, 4);
    intList.display(cout);
    cout << endl;
    
    intList.insertnew(20, 1);
    intList.display(cout);
    cout << endl;
    
    intList.insertnew(30, 1);
    intList.display(cout);
    cout << endl;
    
    
    
}