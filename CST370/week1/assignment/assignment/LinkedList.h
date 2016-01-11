
/*--------------------------------------------------------------------
 Title: Assignment 1 - Linked Lists - Bozelka
 File: Header for LinkedList
 Abstract: This assigment adds a few methods to the linked
           list which allow a user to search and test for substrings
           starting with an A and ending with a B. The program then
           outputs those substring to the screen and counts how many
           total substrings were found.
 Author: Matthew Bozelka
 ID: 002276039
 Date: 01/10/2016
 --------------------------------------------------------------------*/

//----- LinkedList.h -----
#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
using namespace std;

typedef char ElementType;

class LinkedList
{
public:
    LinkedList();   // constructor
    ~LinkedList();  // destructor
    LinkedList(const LinkedList & original); //copy constructor
    void insert(ElementType item, int pos);
    void erase(int pos);
    
    void display(ostream & out) const;
    /*--------------------------------------------------------------------
     Display the contensts of this LinkedList.
     Precondition: ostream out is open
     Postcondition: Elements of this LinkedList have been output to out.
     --------------------------------------------------------------------*/
    
    int size();
    /*--------------------------------------------------------------------
     Returns the size of the LinkedList
     Precondition: Requires no arguments
     Postcondition: returns the size of the LinkedList to the calling user
     --------------------------------------------------------------------*/
    
    ElementType valueAtIndex(int pos);
    /*--------------------------------------------------------------------
     Finds and returns data at a specific position
     Precondition:  Requires int pos which is the position of a desired node
     Postcondition: Returns the data of a particular node to the calling user.
     --------------------------------------------------------------------*/
    
    void findSublists(ElementType startData, ElementType endData);
    /*--------------------------------------------------------------------
     Finds and displays the Sublists in the linkedList that match startData and endData.
     Precondition:  Expects ElementType startData and ElementType endData representing
                    the start and the end of the substring
     Postcondition: Prints all found substrings to the console as well as the 
                    count of substrings
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