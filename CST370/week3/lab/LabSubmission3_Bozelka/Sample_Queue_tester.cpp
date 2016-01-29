/*--------------------------------------------------------------------
 Title: Lab 3 - Queues - Bozelka
 File: Driver for the lab
 Abstract: This Lab uses a queue to store special notes found in a text
 file. The main program will open and search through the contents of
 a .txt file and store the text it finds between the delimiters {} in
 a queue to later be used. I this case it just prints to the screen.
 Author: Matthew Bozelka
 ID: 002276039
 Date: 01/25/2016
 --------------------------------------------------------------------*/


/*---------------------------------------------------------------------
 Driver program to test the Queue class.
 ----------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
using namespace std;

#include "Queue.h"


/*
 helper function:
 pre condiction: expects a reference to a Queue named q, and string named txt
 post condition: Loops the string character by character to determine if it contains
 any special noted deliminated by {}
 */
void processText(string txt, Queue & q);


int main()
{
    const string FILE_IN = "sample.txt";
    
    string finaInputlText = "", line;
    Queue notesStorage;
    ifstream inputFile;
    
    inputFile.open(FILE_IN, ios::in);
    
    if(!inputFile.is_open())
    {
        cerr << "Error opening file " + FILE_IN << endl;
        exit(1);
    }
    
    while ( getline(inputFile, line) )
    {
        finaInputlText += line + "\n";
    }
    
    inputFile.close();
    
    processText(finaInputlText, notesStorage);
    
    if(notesStorage.empty())
    {
        cout << "No special notes in text\n";
    }else
    {
        cout << "Special notes from text:\n";
        notesStorage.display(cout);
    }
}


void processText(string txt, Queue & q)
{
    const char OPENING_DELIMITOR = '{';
    const char CLOSING_DELIMITOR = '}';
    
    string note = "";
    bool openingFound = false;
    
    for(char c : txt)
    {
        
        if(c == OPENING_DELIMITOR)
        {
            openingFound = true;
        }
        else if(openingFound && c == CLOSING_DELIMITOR)
        {
            openingFound = false;
            q.enqueue(note);
            note = "";
        }
        else if(openingFound)
        {
            note += c;
        }
    }
}


