
/*--------------------------------------------------------------------
 Title: Lab 1 - Linked Lists - Bozelka
 File: .cpp for LinkedList
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

//-- Default constructor
LinkedList::LinkedList()
{
    mySize = 0;
    first = NULL;
}

//-- Definition of the copy constructor
LinkedList::LinkedList(const LinkedList & origList)
{
    mySize = origList.mySize;
    first = NULL;
    
    if (mySize == 0)
        return;
    
    Node * origPtr, * lastPtr;
    first = new Node(origList.first->data); // copy first node
    lastPtr = first;
    origPtr = origList.first->next;
    while (origPtr != NULL)
    {
        lastPtr->next = new Node(origPtr->data);
        origPtr = origPtr->next;
        lastPtr = lastPtr->next;
    }
}


//-- Definition of the destructor
LinkedList::~LinkedList()
{
    Node * prev = first;
    Node * ptr;
    
    while (prev != NULL)
    {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}


//-- Definition of insert()
void LinkedList::insert(ElementType dataVal, int index)
{
    if (index < 0 || index > mySize)
    {
        cerr << "Illegal location to insert -- " << index << endl;
        return;
    }
    
    mySize++;
    Node * newPtr = new Node(dataVal);
    Node * predPtr = first;
    if (index == 0)
    {
        newPtr->next = first;
        first = newPtr;
    }
    else
    {
        for(int i = 1; i < index; i++)
            predPtr = predPtr->next;
        newPtr->next = predPtr->next;
        predPtr->next = newPtr;
    }
}

void LinkedList::insertnew(ElementType dataVal, int index)
{
    mySize++;
    Node * newPtr = new Node(dataVal);
    Node * predPtr = first;
    for(int i = 0; i <= index; i++)
    {
        predPtr = predPtr->next;
    }
    newPtr->next = predPtr->next;
    predPtr->next = newPtr;
}


//-- Definition of erase()
void LinkedList::erase(int index)
{
    if (index < 0 || index >= mySize)
    {
        cerr << "Illegal location to delete -- " << index << endl;
        return;
    }
    
    mySize--;
    Node * ptr;
    Node * predPtr = first;
    if (index == 0)
    {
        ptr = first;
        first = ptr->next;
        delete ptr;
    }
    else
    {
        for(int i = 1; i < index; i++)
            predPtr = predPtr->next;
        ptr = predPtr->next;
        predPtr->next = ptr->next;
        delete ptr;
    }
}



//-- Definition of display()
void LinkedList::display(ostream & out) const
{
    Node * ptr = first;
    while (ptr != 0)
    {
        out << ptr->data << " ";
        ptr = ptr->next;
    }
}


/*
 Added method to determine what the maximum data element is.
 It returns that element
 */
ElementType LinkedList::maxItem()
{
    
    ElementType maxData = -1;
    Node * current = first;
    
    if (mySize == 0 || first == 0)
    {
        cerr << "Error: There are no elements in the list." << endl;
        return maxData;
    }
    
    while(current != 0)
    {
        
        if(current->data > maxData)
            maxData = current->data;
        
        current = current->next;
    }

    return maxData;
}


/*
 Added method to determine if list is in ascending order
*/
bool LinkedList::isAscendingOrder()
{
    
    if (mySize == 0 || first == 0)
        return true;
    
    Node * current = first;
    ElementType size = 0;
    
    while (current != 0)
    {
        if(current->data < size)
            return false;
        
        size = current->data;
        current = current->next;
    }
  
    return true;
}

