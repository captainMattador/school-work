
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

    ElementType max;
    bool isAscendingOrder;
    
    // Test the class constructor
    LinkedList intList;
    cout << "Constructing intList\n\n";
    
    // tests for maxItem - Lab part a
    cout << "******* Testing maxItem *******\n\n";
    
    // test of maxItem with empty list
    cout << "Testing maxItem with empty list:\n";
    max = intList.maxItem();
    cout << "Max Item: " << max << endl << endl;
    
    // test of maxItem with one in list
    intList.insert(100, 0);
    cout << "Current List: ";
    intList.display(cout);
    cout << endl;
    cout << "Testing maxItem with one in list:\n";
    max = intList.maxItem();
    cout << "Max Item: " << max << endl << endl;
    
    // test of maxItem with two in list
    intList.insert(200, 0);
    cout << "Current List: ";
    intList.display(cout);
    cout << endl;
    cout << "Testing maxItem with two in list:\n";
    max = intList.maxItem();
    cout << "Max Item: " << max << endl << endl;
    
    // test of maxItem with many in list
    intList.insert(400, 1);
    intList.insert(150, 0);
    intList.insert(350, 4);
    cout << "Current List: ";
    intList.display(cout);
    cout << endl;
    cout << "Testing maxItem with many in list:\n";
    max = intList.maxItem();
    cout << "Max Item: " << max << endl << endl;
    
    
    //delete items to prepare for ascending tests
    intList.erase(0);
    intList.erase(0);
    intList.erase(0);
    intList.erase(0);
    intList.erase(0);
    
    
    // tests for isAscendingOrder - Lab part b
    cout << "******* Testing isAscendingOrder *******\n\n";
    
    // testing of ascending order for empty list
    isAscendingOrder = intList.isAscendingOrder();
    cout << "Empty list test:\n";
    cout << "Ascending in order: " << ((isAscendingOrder) ? "True." : "False.") << endl << endl;
    
    // testing of ascending order for one it list
    intList.insert(100, 0);
    cout << "One in list test:\nCurrent List: ";
    intList.display(cout);
    cout << endl;
    isAscendingOrder = intList.isAscendingOrder();
    cout << "Ascending in order: " << ((isAscendingOrder) ? "True." : "False.") << endl << endl;
    
    // testing of ascending order for two in list (still ascending)
    intList.insert(200, 1);
    cout << "Two in list test (still ascending):\nCurrent List: ";
    intList.display(cout);
    cout << endl;
    isAscendingOrder = intList.isAscendingOrder();
    cout << "Ascending in order: " << ((isAscendingOrder) ? "True." : "False.") << endl << endl;
    
    // testing of ascending order for three in list (still ascending)
    intList.insert(300, 2);
    cout << "Three in list test (still ascending):\nCurrent List: ";
    intList.display(cout);
    cout << endl;
    isAscendingOrder = intList.isAscendingOrder();
    cout << "Ascending in order: " << ((isAscendingOrder) ? "True." : "False.") << endl << endl;
    
    // testing of ascending order for four in list (NOT ascending)
    intList.insert(150, 3);
    cout << "Four in list test (NOT ascending):\nCurrent List: ";
    intList.display(cout);
    cout << endl;
    isAscendingOrder = intList.isAscendingOrder();
    cout << "Ascending in order: " << ((isAscendingOrder) ? "True." : "False.") << endl << endl;
    
}