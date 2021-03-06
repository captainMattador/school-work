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



//-- Added method - Definition of size()
int LinkedList::size()
{
    return mySize;
}



//-- Added method - Definition of nodeAtIndex(int)
ElementType LinkedList::valueAtIndex(int pos)
{
    if (pos < 0 || pos >= mySize)
    {
        cerr << "Illegal location to Access -- " << pos << endl;
        return NULL;
    }
    
    Node * current = first;
    
    for(int i = 0; i < pos; i++)
    {
        current = current->next;
    }
    
    return current->data;
}



//-- Added method - Definition of findSublists(ElementType startData, ElementType endData)
void LinkedList::findSublists(ElementType startData, ElementType endData)
{
    
    // return early if no items
    if(mySize == 0 || first == 0)
        return;
    
    int totalSubStr = 0;
    Node * outerCurrent = first, * innerCurrent = nullptr;
    
    for(int i = 0; i < mySize; i++)
    {
        
        // skip loop if not the startLetter
        if(outerCurrent->data != startData)
        {
            outerCurrent = outerCurrent->next;
            continue;
        }
        
        string subStr = "";
        innerCurrent = outerCurrent;
        
        for(int k = 0; k < mySize - i; k++)
        {
            subStr += innerCurrent->data;
            
            if(innerCurrent->data == endData)
                cout << "Substring " << ++totalSubStr << ": " << subStr << endl;
            
            innerCurrent = innerCurrent->next;
        }
        
        outerCurrent = outerCurrent->next;
    }
    
    cout << "Total " << totalSubStr << " substrings" << endl;

}
