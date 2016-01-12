
/*--------------------------------------------------------------------
 Title: Lab 1 - Linked Lists - Bozelka
 File: Header for LinkedList
 Abstract: This lab builds on to a supplied linked list adding methods
           to find and return the maximum value stored in the linked
           list and another method to determine if the linked list
           is in ascending order
 Author: Matthew Bozelka
 ID: 002276039
 Date: 01/10/2016
--------------------------------------------------------------------*/

//----- LinkedList.h -----
#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
using namespace std;

typedef int ElementType;

class LinkedList
{
public:
    LinkedList();   // constructor
    ~LinkedList();  // destructor
    LinkedList(const LinkedList & original); //copy constructor
    void insert(ElementType item, int pos);
    void erase(ElementType item);
    
    void display(ostream & out) const;
    /*--------------------------------------------------------------------
     Display the contensts of this LinkedList.
     Precondition: ostream out is open
     Postcondition: Elements of this LinkedList have been output to out.
     --------------------------------------------------------------------*/
    
    ElementType maxItem();
    /*--------------------------------------------------------------------
     Added function for the lab.
     Precondition: takes no paramaters
     Postcondition: returns the data of the max item in the LinkedList
     --------------------------------------------------------------------*/
    
    bool isAscendingOrder();
    /*--------------------------------------------------------------------
     Added function for the lab.
     Precondition: takes no paramaters
     Postcondition: returns true if the list is in ascending order
     and false if not.
     --------------------------------------------------------------------*/
    
private:
    class Node
    {
    public:
        ElementType data;
        Node * next;
        //------ Node OPERATIONS
        //-- Default constrctor: initializes next member to
        Node()
        : next(NULL)
        { }
        //-- Explicit-value constructor: initializes data member to dataValue
        //-- and next member to 0
        Node(ElementType dataValue)
        : data(dataValue), next(NULL)
        { }
    };
    Node * first;
    int mySize;
};

#endif